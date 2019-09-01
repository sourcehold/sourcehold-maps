from .network import *

import sys
if sys.version_info < (3,):
    def b(x):
        return x
else:
    import codecs
    def b(x):
        return codecs.latin_1_encode(x)[0]

def assert_equal(a, b):
    if not a == b:
        raise Exception("Value a {} is not equal to value b {}".format(a, b))

class AbstractDebugger(object):

    def __init__(self, path):
        self.path = path

    def set_breakpoints(self, breakpoints):
        raise NotImplementedError("")

    def go_to_next_breakpoint(self):
        raise NotImplementedError("")

    def get_breakpoint(self):
        raise NotImplementedError("")

    def read(self, addr, size):
        raise NotImplementedError("")

    def write(self, addr, data):
        raise NotImplementedError("")

    def get_register(self, register):
        raise NotImplementedError("")

import debugger.network

class NetworkedDebugger(AbstractDebugger):

    def __init__(self, path, client_mode = True):
        AbstractDebugger.__init__(self, path)

        self.breakpoint = None
        self.breakpoints = []
        self.client_mode = client_mode

    def setup_connection(self):
        if self.client_mode:
            s = debugger.network.create_client_socket()
            self.client = debugger.network.run_client(s)
        else:
            self.client = debugger.network.server_as_client()

    def initialize(self):
        self.client.execute("import x64dbgpy")
        self.client.execute("global BREAKPOINT; BREAKPOINT = None")
        self.client.execute("""def on_breakpoint(type, addr, enabled, singleshoot, active, name, mod, slot):
    global BREAKPOINT;
    if enabled:
        if active:
            BREAKPOINT = (addr, name)""")
        self.client.execute("x64dbgpy.Event.listen('breakpoint', on_breakpoint)")

    def set_breakpoints(self, breakpoints):
        for addr, name in breakpoints:
            self.exec_direct("bp {}, \\\"{}\\\"".format(addr, name))
            self.exec_direct("bpe {}".format(addr))
            self.breakpoints.append((addr, name))

    def clear_breakpoints(self):
        self.exec_direct("bpc")

    def get_breakpoint(self):
        bp = self.client.evaluate("BREAKPOINT")
        bp = ('0x'+hex(bp[0])[2:].upper(), bp[1])
        return bp

    def go_to_next_breakpoint(self):
        self.client.execute("x64dbgpy.pluginsdk.Run()")
        return self.get_breakpoint()

    def read(self, addr, size):
        return b(self.client.evaluate("x64dbgpy.pluginsdk.Read({}, {})".format(hex(addr), size)))

    def write(self, addr, data):
        return self.client.evaluate("x64dbgpy.pluginsdk.Write({}, {})".format(hex(addr), data))

    def get_register(self, register):
        return self.client.evaluate("x64dbgpy.pluginsdk.Get{}()".format(register.upper()))

    def init(self):
        self.exec_direct("init \\\"{}\\\"".format(self.path))

    def restart(self):
        self.client.execute("x64dbgpy.pluginsdk.Stop()")
        self.init()

    def exec_direct(self, command):
        self.client.execute("x64dbgpy.pluginsdk.x64dbg.DbgCmdExecDirect(\"{}\")".format(command))

class DirectDebugger(AbstractDebugger):

    def __init__(self, path):
        AbstractDebugger.__init__(self, path)

        import x64dbgpy
        self.x64dbgpy = x64dbgpy

        self.x64dbgpy.Event.listen("breakpoint", self.on_breakpoint)

        self.breakpoint = None
        self.breakpoints = []

    def on_breakpoint(self, type, addr, enabled, singleshoot, active, name, mod, slot):
        if enabled:
            if active:
                self.breakpoint = (addr, name)

    def get_breakpoint(self):
        return self.breakpoint

    def set_breakpoints(self, breakpoints):
        for addr, name in breakpoints:
            self.x64dbgpy.pluginsdk.x64dbg.DbgCmdExecDirect('bp {}, "{}"'.format(addr, name))
            self.x64dbgpy.pluginsdk.x64dbg.DbgCmdExecDirect('bpe {}'.format(addr))
            self.breakpoints.append((addr, name))

    def go_to_next_breakpoint(self):
        self.x64dbgpy.pluginsdk.Run()
        return self.get_breakpoint()

    def read(self, addr, size):
        return self.x64dbgpy.pluginsdk.Read(addr, size)

    def write(self, addr, data):
        return self.x64dbgpy.pluginsdk.Write(addr, data)

    def get_register(self, register):
        return self.x64dbgpy.pluginsdk.__dict__["Get{}".format(register)]()

    def init(self):
        #self.x64dbgpy.pluginsdk.Stop()
        self.x64dbgpy.pluginsdk.x64dbg.DbgCmdExecDirect("init \"{}\"".format(self.path))

    def restart(self):
        self.x64dbgpy.pluginsdk.Stop()
        self.init()

    def exec_direct(self, command):
        self.x64dbgpy.pluginsdk.x64dbg.DbgCmdExecDirect(command)

    def clear_breakpoints(self):
        self.exec_direct("bpc")

import struct

class Variable(property):

    def __init__(self, getter, setter, addr, size, type):
        super(property, self).__init__(getter, setter)
        self.addr = addr
        self.size = size
        self.type = type

    def assert_equal(self, debugger, value):
        data = debugger.read(self.addr, self.size)
        test = struct.unpack(type, data)
        if test != value:
            raise Exception("Given value {} does not equal value in debugger {}".format(value, test))

    def test_equal(self, debugger, value):
        data = debugger.read(self.addr, self.size)
        test = struct.unpack(self.type, data)
        return test == value

class Property(object):
    "Emulate PyProperty_Type() in Objects/descrobject.c"

    def __init__(self, fget=None, fset=None, fdel=None, doc=None):
        self.fget = fget
        self.fset = fset
        self.fdel = fdel
        if doc is None and fget is not None:
            doc = fget.__doc__
        self.__doc__ = doc

    def __get__(self, obj, objtype=None):
        if obj is None:
            return self
        if self.fget is None:
            raise AttributeError("unreadable attribute")
        return self.fget(obj)

    def __set__(self, obj, value):
        if self.fset is None:
            raise AttributeError("can't set attribute")
        self.fset(obj, value)

    def __delete__(self, obj):
        if self.fdel is None:
            raise AttributeError("can't delete attribute")
        self.fdel(obj)

    def getter(self, fget):
        return type(self)(fget, self.fset, self.fdel, self.__doc__)

    def setter(self, fset):
        return type(self)(self.fget, fset, self.fdel, self.__doc__)

    def deleter(self, fdel):
        return type(self)(self.fget, self.fset, fdel, self.__doc__)


def variable(addr, size, type, debugger = None):
    #print("setting up property")
    class Property(property):
        def __init__(self, fget=None, fset=None, fdel=None, doc=None):
            property.__init__(self,fget, fset, fdel, doc)
            #super(property, self).__init__(fget, fset, fdel, doc)
            self.addr = addr
            self.size = size
            self.type = type
            self.debugger = debugger
            #print(self.addr, self.size, self.type)
            #print("setting up instance")

        def assert_equal(self, obj, debugger = None):
            if self.debugger is None:
                if debugger is None:
                    raise Exception("No debugger is specified")
            else:
                if debugger is None:
                    debugger = self.debugger
                else:
                    #this lets debugger argument override self.debugger
                    pass

            value = self.fget(obj)
            debugger_value = struct.unpack(self.type, debugger.read(self.addr, self.size, ))
            assert value == debugger_value
    return Property

class Variable(object):

    def __init__(self, name, addr, size, type, debugger = None):
        object.__init__(self)
        self.name = name
        self.addr = addr
        self.size = size
        self.type = type
        self.debugger = debugger
        self.fget = None
        self.fset = None
        self.fdel = None

    def __call__(self, fget):
        self.fget = fget
        return self

    def __get__(self, obj, objtype=None):
        if obj is None:
            return self
        if not self.fget is None:
            return self.fget(obj, self.name)
        if "_"+self.name not in obj.__dict__:
            raise AttributeError("object has no attribute {}".format(self.name))
        return obj.__dict__["_"+self.name]

    def __set__(self, obj, value):
        if not self.fset is None:
            return self.fset(obj, self.name, value)
        obj.__dict__["_"+self.name] = value

    def __delete__(self, obj):
        if not self.fdel is None:
            return self.fdel(obj, self.name)
        del obj.__dict__["_"+self.name]

    def getter(self, fget):
        self.fget = fget
        return self

    def setter(self, fset):
        self.fset = fset
        return self

    def deleter(self, fdel):
        self.fdel = fdel
        return self

    def _get_debugger_value(self, debugger = None):
        if self.debugger is None:
            if debugger is None:
                raise Exception("No debugger is specified")
        else:
            if debugger is None:
                debugger = self.debugger
            else:
                # this lets debugger argument override self.debugger
                pass
        return struct.unpack(self.type, debugger.read(self.addr, self.size))

    def __eq__(self, other):
        return self._get_debugger_value() == other

    def is_equal(self, obj, debugger = None):
        value = self.__get__(obj)
        debugger_value = self._get_debugger_value(debugger)
        return value == debugger_value

    def test_equal(self, obj, debugger = None):
        value = self.__get__(obj)
        debugger_value = self._get_debugger_value(debugger)
        if value != debugger_value:
            raise Exception("value {} of variable {} is not the same as debugger value {}".format(value, self.name, debugger_value))
        return True

class Testable(object):

    def __init__(self):
        pass

    def test_all_equal(self, debugger = None):
        for key in type(self).__dict__.keys():
            obj = type(self).__dict__[key]
            if type(obj) == type(Variable):
                obj.test_equal(self, debugger)
        return True

class TestClass(Testable):

    def __init__(self):
        super(Testable, self).__init__()
        self._a = 1
        self._b = 2
        self._c = 3
        self._d = 4

    @variable(0,0,0, debugger = None)
    def a(self):
        return self._a

    @a.setter
    def a(self, value):
        self._a = value

    def get(self, name):
        return self.__dict__["_"+name]

    def set(self, name, value):
        self.__dict__["_"+name] = value

    c = Variable("c",1,0,0)
    d = Variable("d",2,0,0)

    @Variable("e",3,0,0)
    def e(self):
        return self._es

    @e.setter
    def e(self, value):
        self._es = value


tc = TestClass()

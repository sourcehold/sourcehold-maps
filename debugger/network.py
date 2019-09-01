import pickle, struct, json, base64, importlib, threading


import sys

def load_pickled(data):
    if sys.version_info.major < 3:
        return pickle.loads(data)
    else:
        return pickle.loads(data, encoding = 'latin1')

def save_pickled(obj):
    if sys.version_info.major < 3:
        return pickle.dumps(obj)
    else:
        return pickle.dumps(obj, protocol = 2)

class Environment(object):

    def __init__(self):
        self.locals = locals()
        del self.locals['self']

    def evaluate(self, expression):
        return eval(expression, self.locals, self.locals)

    def execute(self, expression):
        exec(expression, self.locals, self.locals)

#from PyQt5.QtCore import QThread
#STUB
class QThread(object):
    def __init__(self):
        pass

class Message(object):

    def __init__(self, exec_command=None, eval_command=None, payload=None, error=None, message=None):
        self.error = error
        self.message = message
        self.exec_command = exec_command
        self.eval_command = eval_command
        self.payload = payload

    def as_bytes(self):
        converted = {}
        for key in ["exec_command", "eval_command", "error", "message"]:
            converted[key] = getattr(self, key)
        converted["payload"] = base64.b64encode(save_pickled(self.payload))
        if sys.version_info.major == 3:
            converted["payload"] = converted["payload"].decode('UTF-8')
        return json.dumps(converted)

    @staticmethod
    def from_bytes(data):
        jdata = json.loads(data)
        if sys.version_info.major == 3:
            jdata["payload"] = jdata["payload"].encode('UTF-8')
        jdata["payload"] = load_pickled(base64.b64decode(jdata["payload"]))
        return Message(**jdata)


class Connection(object):

    def __init__(self, conn):
        self.conn = conn

    def send(self, obj):
        data = obj.as_bytes()
        if sys.version_info.major == 3:
            message = struct.pack("!L", len(data)) + data.encode("UTF-8")
        else:
            message = struct.pack("!L", len(data)) + data
        self.conn.send(message)

    def receive(self):
        header = self.conn.recv(struct.calcsize("!L"))
        if len(header) == struct.calcsize("!L"):
            size = struct.unpack("!L", header)[0]
            data = self.conn.recv(size)
            return Message.from_bytes(data)


class Server(QThread):

    def __init__(self, client_conn):
        QThread.__init__(self)
        self.conn = client_conn
        self.env = Environment()

    def run(self):
        while True:
            message = self.conn.receive()
            print("Received message")
            if message.eval_command:
                if message.eval_command == "interrupt":
                    print("Received interrupt command")
                    self.conn.send(Message(eval_command=message.eval_command, payload=True, error=None, message=None))
                    break
                try:
                    print("Evaluating command: {}".format(message.eval_command))
                    result = self.env.evaluate(message.eval_command)
                    print("Sending result")
                    self.conn.send(Message(eval_command=message.eval_command, payload=result, error=None, message=None))
                except Exception as e:
                    print("Could not evaluate command: ", message.eval_command)
                    print(e)
                    self.conn.send(Message(eval_command=message.eval_command, payload=None, error=e.__class__.__name__,
                                           message=str(e)))
            elif message.exec_command:
                if message.exec_command == "interrupt":
                    print("Received interrupt command")
                    self.conn.send(Message(eval_command=message.exec_command, payload=True, error=None, message=None))
                    break
                try:
                    print("Executing command: {}".format(message.exec_command))
                    self.env.execute(message.exec_command)
                    print("Sending result")
                    self.conn.send(Message(exec_command=message.exec_command, payload=None, error=None, message=None))
                except Exception as e:
                    print("Could not execute command: ", message.exec_command)
                    print(e)
                    self.conn.send(Message(exec_command=message.exec_command, payload=None, error=e.__class__.__name__,
                                           message=str(e)))
        self.conn.conn.close()

class Client(object):

    def __init__(self, server_conn):
        self.conn = server_conn

    def evaluate(self, expression):
        print("Sending expression: {}".format(expression))
        self.conn.send(Message(eval_command=expression))
        print("Receiving result")
        message = self.conn.receive()
        if message.error:
            print("During the evaluation of {}, an exception was raised: ".format(message.eval_command))
            raise Exception("An exception of type {} was raised, message: {}".format(message.error, message.message))
        return message.payload

    def execute(self, expression):
        print("Sending expression: {}".format(expression))
        self.conn.send(Message(exec_command=expression))
        print("Receiving result")
        message = self.conn.receive()
        if message.error:
            print("During the evaluation of {}, an exception was raised: ".format(message.exec_command))
            raise Exception("An exception of type {} was raised, message: {}".format(message.error, message.message))
        #return message.payload

    def interrupt(self):
        print("Sending interrupt")
        self.conn.send(Message(exec_command="interrupt"))
        message = self.conn.receive()
        if message.error:
            print("During the evaluation of {}, an exception was raised: ".format(message.exec_command))
            raise Exception("An exception of type {} was raised, message: {}".format(message.error, message.message))


import socket


def create_client_socket():
    s = socket.socket()
    s.connect(('127.0.0.1', 31338))
    return s


def run_client(s):
    client = Client(Connection(s))
    return client


def create_server_socket():
    s = socket.socket()
    s.bind(('127.0.0.1', 31338))
    s.listen(10)

    return s

def run_server_once(s):
    conn, addr = s.accept()
    server = Server(Connection(conn))
    server.run()

def run_server(s):
    while True:
        run_server_once(s)


def server_as_client():
    s = create_server_socket()
    conn, addr = s.accept()
    client = Client(Connection(conn))
    return client


def client_as_server(threaded=False):
    c = create_client_socket()
    server = Server(Connection(c))
    thread = None
    if threaded:
        server.start()

    return (server, thread)


# import sys
#
# this = sys.modules[__name__]
#
#
# def set_value(name, value):
#     setattr(this, name, value)
#
#
# def get_value(name):
#     return getattr(this, name)
#

if __name__ == "__main__":
    server = create_server_socket()
    run_server(server)
    #exit(0)
    #server = client_as_server(False)
    #server.run()
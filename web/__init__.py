import asyncio

asyncio.set_event_loop_policy(asyncio.WindowsSelectorEventLoopPolicy())

import tornado.ioloop
import tornado.web
import hashlib
import pathlib
import binascii
import tempfile
import shutil

from sourcehold import Map, Buffer


# logging.basicConfig(level=logging.DEBUG)


class FileManager(object):

    def __init__(self, path=pathlib.Path("~").expanduser() / '.sourcehold-maps-web' / 'files'):
        if not path.parent.exists():
            path.parent.mkdir()
        if not path.exists():
            path.mkdir()
        self.path = path
        self.file_names = [f.name for f in self.path.iterdir()]

    def has_file(self, name):
        return name in self.file_names

    def put_file(self, name, data):
        (self.path / name).write_bytes(data)

    def get_file(self, name):
        return (self.path / name).read_bytes()


FILE_MANAGER = FileManager()


class APIKeyManager(object):

    def __init__(self, path=pathlib.Path("~").expanduser() / ".sourcehold-maps-web" / "api_keys"):
        if not path.parent.exists():
            path.parent.mkdir()
        if not path.exists():
            path.touch()
        self.path = path
        self.valid_keys = path.read_text(encoding='ascii').split('[\n\r]+')

    def is_valid(self, key):
        return key in self.valid_keys

    def register_key(self, key):
        if key not in self.valid_keys:
            self.valid_keys.append(key)

    def close(self):
        self.path.write_text('\n'.join(self.valid_keys), encoding='ascii')


KEY_MANAGER = APIKeyManager()


class WithLoginHandler(tornado.web.RequestHandler):

    def get_current_user(self):
        return self.get_secure_cookie('user')


class LoginHandler(WithLoginHandler):

    def get(self):
        user = self.get_current_user()
        if user:
            self.write('Authenticated')
        else:
            self.write('Not authenticated')

    def post(self):
        key = self.get_argument('key', default=None)
        if not key:
            self.set_status(404, "No key specified")
            return
        if KEY_MANAGER.is_valid(key):
            self.set_secure_cookie(name='user', value=key)
        else:
            self.set_status(403, "Invalid key specified")
            self.write('invalid key specified')


class UnpackedFileHandler(WithLoginHandler):

    @tornado.web.authenticated
    def get(self):
        md5_packed = self.get_argument('MD5', default=None)
        if not md5_packed:
            self.set_status(403, 'No MD5 specified')
            return


class RepackHandler(WithLoginHandler):

    @tornado.web.authenticated
    def post(self):
        data = self.request.files['zipfile'][0]['body']
        hash = binascii.hexlify(hashlib.md5(data).digest()).decode('ascii')

        _, f = tempfile.mkstemp()
        d = tempfile.mkdtemp()

        pathlib.Path(f).write_bytes(data)
        unzipped_path = shutil.unpack_archive(f, d, format="zip")

        m = Map().load_from_folder(d)

        buf = Buffer()
        m.serialize_to_buffer(buf)

        self.set_header('Content-Type', 'application/octet-stream')
        self.set_header('Content-Disposition', 'attachment; filename=unpacked.zip')
        self.write(m.getvalue())


class UnpackHandler(WithLoginHandler):

    @tornado.web.authenticated
    def post(self):
        data = self.request.files['mapfile'][0]['body']
        hash = binascii.hexlify(hashlib.md5(data).digest()).decode('ascii')

        _, f = tempfile.mkstemp()
        d = tempfile.mkdtemp()

        Map().from_buffer(Buffer(data)).dump_to_folder(d)

        zip_path = shutil.make_archive(base_name=f, format='zip', root_dir=d)

        zipped_data = pathlib.Path(zip_path).read_bytes()

        FILE_MANAGER.put_file(hash, zipped_data)

        self.set_header('Content-Type', 'application/octet-stream')
        self.set_header('Content-Disposition', 'attachment; filename=unpacked.zip')
        self.write(zipped_data)


class MainHandler(WithLoginHandler):

    def get(self):
        self.write('<html>'
                   '<body>'
                   '<div><form action="/login" method="post">'
                   'API key: <input type="text" name="key">'
                   '<input type="submit" value="Sign in with API key">'
                   '</form></div>'
                   '<div><form action="/unpack" method="post" enctype="multipart/form-data">'
                   'File: <input type="file" name="mapfile">'
                   '<input type="submit" value="MAP to ZIP (unpack)">'
                   '</form></div>'
                   '<div><form action="/repack" method="post" enctype="multipart/form-data">'
                   'File: <input type="file" name="zipfile">'
                   '<input type="submit" value="ZIP to MAP (repack)">'
                   '</form></div>'
                   '</body>'
                   '</html>')


def make_app():
    settings = {
        'cookie_secret': 'knfw38o2jqoeninlfwe',
        'login_url': '/login'
    }
    return tornado.web.Application([
        (r"/", MainHandler),
        (r"/repack", RepackHandler),
        (r"/unpack", UnpackHandler),
        # (r"/unpacked", UnpackedFileHandler),
        (r'/login', LoginHandler)
    ], **settings)


if __name__ == "__main__":
    app = make_app()
    app.listen(9090)
    tornado.ioloop.IOLoop.current().start()

import tornado.web
import tornado.ioloop
import sys
import os


class BasicRequestHandler(tornado.web.RequestHandler):
    def get(self):
        self.write(f"Served from {os.getpid()}")

if __name__ == "__main__":
    app = tornado.web.Application([
        (r"/basic", BasicRequestHandler)
    ])

    port = 8882
    if (sys.argv.__len__() > 1):
        port = sys.argv[1]
    
    app.listen(port)
    print(f"application is listening on port {port}")
    tornado.ioloop.IOLoop.current().start()
    
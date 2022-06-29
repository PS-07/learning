> brew install nginx

> python3 -m venv venv
> source venv/bin/activate
> pip install -r requirements.txt 

> python3 index.py 1111
> python3 index.py 2222
> python3 index.py 3333
> GET http://localhost:1111/basic
> GET http://localhost:2222/basic
> GET http://localhost:3333/basic

> vi /usr/local/etc/nginx/nginx.conf
> add path of your nginx config file at bottom of the file
  include /Users/puneet6.singh/Desktop/learning/learning/technologies/load-balancing/layer7-nginx/layer7-nginx.conf;
> sudo nginx
> GET http://localhost/basic

> brew install haproxy

> npm install express
> npm run app1server1
> npm run app1server2
> npm run app2server1
> npm run app2server2
> haproxy -f http.cfg
> GET http://localhost:9999/app1
> GET http://localhost:9999/app2
## kubesphere的演示demo，c++写的，该服务为前端服务，用户访问该服务的/api/handerclick，该前端服务会向后端服务发起api请求，访问后端服务的/api/msg。
# api为
/api/handerclick

## 环境变量
SERVER_ADDR,填后端服务的地址

## 编译方法,请保证c++编译环境为c++11,g++的版本为4.8以上
g++ -std=c++11 http_server.cpp main.cpp -o front

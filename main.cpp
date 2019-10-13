#include <iostream>
#include <memory>
#include "http_server.h"
#include <stdlib.h>
//#include "http_client.h"

// 初始化HttpServer静态类成员
mg_serve_http_opts HttpServer::s_server_option;
std::string HttpServer::s_web_dir = "./web";
std::unordered_map<std::string, ReqHandler> HttpServer::s_handler_map;
std::unordered_set<mg_connection *> HttpServer::s_websocket_session_set;

void handle_func(std::string rsp)
{
        // do sth according to rsp
        std::cout << "http rsp1: " << rsp << std::endl;
}

bool handle_click(std::string url, std::string body, mg_connection *c, OnRspCallback rsp_callback)
{
	// do sth
	char new_url[256];
	new_url[0] = 0;
	const char* url1 = getenv("SERVER_ADDR");
	sprintf(new_url,"http://%s:8000/api/msg",url1);
	std::cout << "handle fun1" << std::endl;
	std::cout << "url: " << url << std::endl;
	std::cout << "body: " << body << std::endl;
	HttpClient::SendReq(new_url, handle_func);
	rsp_callback(c, "hello world");

	return true;
}


int main(int argc, char *argv[]) 
{
	std::string port = "7999";
	auto http_server = std::shared_ptr<HttpServer>(new HttpServer);
	http_server->Init(port);
	// add handler
	http_server->AddHandler("/api/handerclick", handle_click);
	http_server->Start();
	

	return 0;
}

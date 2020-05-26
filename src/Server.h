#ifndef __JSONAPI_CLIENT_SERVER_H
#define __JSONAPI_CLIENT_SERVER_H

#include<string>
#include<iostream>
#include<cstring>
#include<vector>
#include<list>

class Resource;

#include"Resource.h"

#include"namespace.h"

class Server{
    private:
	std::string url_;
	Json::Value get_URL(const std::string url_);

    public:
	Server(const std::string url);

	void set_url(const std::string url_new); //setting url for a server
	std::string get_url();

	std::list<Resource> get_all(const std::string type); 
	Resource get_one(const std::string type,const std::string id);

	~Server();
};

#endif

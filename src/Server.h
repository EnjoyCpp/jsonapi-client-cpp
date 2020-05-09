#include<string>
#include<iostream>
#include<cstring>
#include<vector>

#pragma once

#include"namespace.h"
#include"Resource.h"


class Server{
    private:
	std::string url_;
	Json::Value get_URL(const std::string url_);

    public:
	Server(const std::string url);

	std::string set_url(const std::string url_new); //setting url for a server
	std::string get_url();

	//Resource get_all(const std::string type); 
	Resource get_one(const std::string type,const std::string id);

	~Server();
};

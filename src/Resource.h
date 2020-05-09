#include<string>
#include<iostream>
#include<cstring>
#include<map>
#pragma once

#include"ResourceIdentifier.h"
#include"Server.h"
#include <jsoncpp/json/json.h> //adding json header for second constructor

class Resource: public ResourceIdentifier{
    private:
	Json::Value JSON;
	Server server;

    public:
	Resource(Server server, Json::Value value); //adding second constructor with all items from data payload

	Json::Value get_attribute(const std::string attribute_name );
	Json::Value get_id();
	Json::Value get_type();

	void set_attribute(const std::string name, bool value );
	void set_attribute(const std::string name, const std::string value );
	void set_attribute(const std::string name, int value );
	void set_attribute(const std::string name, double value );

	void set_id(const std::string value);
	void set_type(const std::string value);

	void get_server();
	void set_server();

	Json::Value get_data();

	~Resource();

};

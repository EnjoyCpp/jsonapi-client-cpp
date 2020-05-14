#ifndef __JSONAPI_CLIENT_RESOURCE_H
#define __JSONAPI_CLIENT_RESOURCE_H

#include<string>
#include<iostream>
#include<cstring>
#include<map>

class Server;

//#include "callback.h"
#include"ResourceIdentifier.h"
#include"Server.h"
#include <jsoncpp/json/json.h> //adding json header for second constructor

class Resource: public ResourceIdentifier{
    private:
	Json::Value JSON;
	Server* server;
    public:
	Resource(Server* server, Json::Value value); //adding second constructor with all items from data payload

	Json::Value get_attribute(const std::string attribute_name );
	Json::Value get_id();
	Json::Value get_type();

	void set_attribute( const std::string name, bool value );
	void set_attribute( const std::string name, const std::string value );
	void set_attribute( const std::string name, int value );
	void set_attribute( const std::string name, double value );

	void set_id( const std::string value );
	void set_type( const std::string value );

	void set_server(const std::string server_new);    
	
	Server* get_server(); 	
	void set_server( Server* server_new );        

	Json::Value get_data();
	void store();

	~Resource();

};

#endif

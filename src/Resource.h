#ifndef __JSONAPI_CLIENT_RESOURCE_H
#define __JSONAPI_CLIENT_RESOURCE_H

#include<string>
#include<iostream>
#include<cstring>
#include<map>

class Server;

#include"ResourceIdentifier.h"
#include"Server.h"
#include <jsoncpp/json/json.h> //adding json header for second constructor

class Resource: public ResourceIdentifier{
    private:
	Json::Value JSON;
	Server* server;
	bool send_json_to_server(std::string server_URL, int type); //information for POST and PATCH // type 0 to POST type 1 to PATCH type 2 to DELETE

    public:
	Resource(Server* server, Json::Value value); //adding second constructor with all items from data payload
	Json::Value get_attribute(const std::string attribute_name );
	std::string get_id();
	std::string get_type();

	void set_attribute( const std::string name, bool value );
	void set_attribute( const std::string name, int value );
	void set_attribute( const std::string name, double value );
	void set_attribute( const std::string name, const char *value);

	void set_id( const std::string value );
	void unset_id();
	void set_type( const std::string value );

	void set_server(const std::string server_new);    
	
	Server* get_server(); 	
	void set_server( Server* server_new );        

	Json::Value get_data();
	Json::Value get_data_all();
	bool create(); //POST
	bool update(); //PATCH
	bool deleteResource(const std::string type, const std::string id);

	~Resource();

};

#endif

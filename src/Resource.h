#include<string>
#include<iostream>
#include<cstring>
#include<map>
#pragma once

#include"ResourceIdentifier.h"
#include <jsoncpp/json/json.h> //adding json header for second constructor

class Resource: public ResourceIdentifier{
    private:
	std::string attribute_name_;
	std::string value_;
	Json::Value JSON;

    public:
	Resource(const std::string attribute_name="",const std::string value="");
	Resource(Json::Value value); //adding second constructor with all items from data payload

	Json::Value get_attribute(const std::string attribute_name );
	//std::string set_attribute(const std::string atribute_name, const std::string value );

	void set_attribute(const std::string name, bool value );
	void set_attribute(const std::string name, const std::string value );
	void set_attribute(const std::string name, int value );
	void set_attribute(const std::string name, double value );

	Json::Value get_data();

	~Resource();

};

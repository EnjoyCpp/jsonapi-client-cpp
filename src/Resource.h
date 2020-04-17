#include<string>
#include<iostream>
#include<cstring>
#pragma once

#include"ResourceIdentifier.h"

class Resource: public ResourceIdentifier{
    private:
	std::string attribute_name_;
	std::string value_;

    public:
	Resource(const std::string attribute_name="",const std::string value="");

	std::string get_attribute(const std::string attribute_name);
	std::string set_attribute(const std::string atribute_name, const std::string value);

	~Resource();

};

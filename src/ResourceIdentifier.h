#ifndef __JSONAPI_CLIENT_RESOURCEIDENTIFIER_H
#define __JSONAPI_CLIENT_RESOURCEIDENTIFIER_H

#include <string>
#include<iostream>
#include<cstring>

class ResourceIdentifier{
    private:
	std::string id_;
	std::string type_;

    public:
	ResourceIdentifier(const std::string id="",const std::string type="");

	std::string get_id();
	std::string set_id(const std::string id_new);

	std::string get_type();
	std::string set_type(const std::string type_new);

	~ResourceIdentifier();
};

#endif

#include <string>
#pragma once



class ResourceIdentifier{
   protected:
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



#include"Resource.h"


 Resource::Resource(const std::string attribute_name,const std::string value):
	attribute_name_(attribute_name), value_(value){
    #ifdef DEBUG
	std::cout <<"Constuctor is working..."<<std::endl;
    #endif
  }

 Resource::Resource(Json::Value value):
	JSON(value){
    #ifdef DEBUG
	std::cout <<"Constructor is working..."<<std::endl;
    #endif 
  }

 std::string Resource::get_attribute(const std::string attribute_name){ //getting attribute name
	return attribute_name_;
  };

 std::string Resource::set_attribute(const std::string attribute_name,const std::string value){ //setting attribute name and value
	this->attribute_name_ = attribute_name;
	this->value_ = value;
  };


/* std::string Resource::get_data(Json::Value value){
	

  };
*/

 Resource::~Resource(){
    #ifdef DEBUG
	std::cout<<"Destructor is working..."<<std::endl;
    #endif
  }

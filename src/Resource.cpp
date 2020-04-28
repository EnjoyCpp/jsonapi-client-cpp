

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

 Json::Value Resource::get_attribute(const std::string attribute_name){ //getting attribute value
	return JSON["attributes"][attribute_name];
  };

 /*std::string Resource::set_attribute(const std::string attribute_name,const std::string value){ //setting attribute name and value
	this->attribute_name_ = name;
	this->value_ = value;
  };
*/

 void Resource::set_attribute(const std::string name, bool value){
	 std::map<std::string, bool> mapOfJson;
	//Inserting data in std::map
	mapOfJson[name]=value;
	JSON["attributes"][name]=mapOfJson[name];
	
  };

 void Resource::set_attribute(const std::string name,const std::string value){ //setting attribute name and value
	std::map<std::string, std::string> mapOfJson;
	//Inserting data in std::map
	mapOfJson[name]=value;
	JSON["attributes"][name]=mapOfJson[name];

  };

 void Resource::set_attribute(const std::string name, int value){
	std::map<std::string, int> mapOfJson;
	//Inserting data in std::map
	mapOfJson[name]=value;
	JSON["attributes"][name]=mapOfJson[name];

  };

 void Resource::set_attribute(const std::string name, double value){
	std::map<std::string, double> mapOfJson;
	//Inserting data in std::map
	mapOfJson[name]=value;
	JSON["attributes"][name]=mapOfJson[name];
  };

 Json::Value Resource::get_data(){
	return JSON; //returns JSON["data"]
  };


 Resource::~Resource(){
    #ifdef DEBUG
	std::cout<<"Destructor is working..."<<std::endl;
    #endif
  }

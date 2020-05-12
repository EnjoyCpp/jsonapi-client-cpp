#include"Resource.h"

 Resource::Resource(Server* server, Json::Value value):
	JSON(value),server(server){
    #ifdef DEBUG
	std::cout <<"Constructor is working..."<<std::endl;
    #endif 
  }

 Json::Value Resource::get_attribute(const std::string attribute_name){ //getting attribute value
	return JSON["attributes"][attribute_name];
  };

 Json::Value Resource::get_id(){ //getting id value
	return JSON["id"];
  };

 Json::Value Resource::get_type(){ //getting type value
	return JSON["type"];
  };

 void Resource::set_attribute(const std::string name, bool value){
	JSON["attributes"][name]=value;
	
  };

 void Resource::set_attribute(const std::string name,const std::string value){ //setting attribute name and value
	JSON["attributes"][name]=value;

  };

 void Resource::set_attribute(const std::string name, int value){
	JSON["attributes"][name]=value;

  };

 void Resource::set_attribute(const std::string name, double value){

	JSON["attributes"][name]=value;
  };

 void Resource::set_id(const std::string value){
	JSON["id"]=value;
  };

 void Resource::set_type(const std::string value){
	JSON["type"]=value;
  };

 Json::Value Resource::get_data(){
	return JSON; //returns JSON["data"]
  };

 std::string Resource::get_server(){
	std::string* a = (std::string*)server;
	std::string b = *a;
	return b;
  };

 void Resource::set_server(const std::string server_new){
	Server server(server_new);
  };

 Resource::~Resource(){
    #ifdef DEBUG
	std::cout<<"Destructor is working..."<<std::endl;
    #endif
  }

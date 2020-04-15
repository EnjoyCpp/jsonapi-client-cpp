#include<iostream>
#include<cstring>
#include"object.h"

  
 ResourceIdentifier::ResourceIdentifier(const std::string id,const std::string type):
	id_(id), type_(type){
   #ifdef DEBUG
	std::cout <<"Constuctor is working..."<<std::endl;
   #endif
  }

 std::string ResourceIdentifier::get_id(){
	return id_;
  };

 std::string ResourceIdentifier::get_type(){
	return type_;
  };

 std::string ResourceIdentifier::set_id(const std::string id_new){
	this->id_ = id_new;
  };

 std::string ResourceIdentifier::set_type(const std::string type_new){
	this->type_ = type_new;
  };

 ResourceIdentifier::~ResourceIdentifier(){
   #ifdef DEBUG
	std::cout<<"Destructor is working..."<<std::endl;
   #endif
  }

 Resource::Resource(const std::string attribute_name,const std::string value):
	attribute_name_(attribute_name), value_(value){
   #ifdef DEBUG
	std::cout <<"Constuctor is working..."<<std::endl;
   #endif
  }

 std::string Resource::get_attribute(const std::string attribute_name){
	return attribute_name_;
  };

 std::string Resource::set_attribute(const std::string attribute_name,const std::string value){
	this->attribute_name_ = attribute_name;
	this->value_ = value;
  };

 Resource::~Resource(){
   #ifdef DEBUG
	std::cout<<"Destructor is working..."<<std::endl;
   #endif
  }

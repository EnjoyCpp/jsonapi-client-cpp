#include<iostream>
#include<cstring>
#include"ResourceIdentifier.h"

  
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

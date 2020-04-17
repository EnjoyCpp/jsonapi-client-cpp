

#include"server.h"


 Server::Server(const std::string url):
	url_(url){
    #ifdef DEBUG
	std::cout<<"constructor is working..."<<std::endl;
    #endif
  }

 std::string Server::set_url(const std::string url_new){
	this->url_=url_new;
  };

 std::string Server::get_url(){
	return url_;
  };

 std::string Server::get_all(const std::string type){
	std::string all_id;          //creating a new string 
	all_id.append(get_url());   //adding url to a new string
	all_id.append("/");        //adding "/" to url
	all_id.append(type);      //adding type to url + "/"
	return all_id;           //returning url+"/"+ type
  };
 
 std::string Server::get_one(const std::string type,const std::string id){
	std::string id_one;
	id_one.append(get_url());
	id_one.append("/");
	id_one.append(type);
	id_one.append("/");
	id_one.append(id);
	return id_one;
  };

 Server::~Server(){
    #ifdef DEBUG
	std::cout<<"Destructor is working..."<<std::endl;
    #endif
  }

#include <jsoncpp/json/json.h>
#include <string>
#include "Resource.h"
#include "Server.h"
#include <assert.h>



int main(){
  Server s("http://jsonapiplayground.reyesoft.com/v2");
  Resource r = s.get_one("authors","2");
  //std::cout<<r.store(); //output of http://jsonapiplayground.reyesoft.com/v2/authors/2" is http response code: 405
  if(r.create()){
	return 0; }
  
    return 1;
};


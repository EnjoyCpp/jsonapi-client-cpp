#include <jsoncpp/json/json.h>
#include <string>
#include "Resource.h"
#include "Server.h"
#include <assert.h>



int main(){
  Server s("http://jsonapiplayground.reyesoft.com/v2");
  Resource r = s.get_one("authors","2");
  if(r.deleteResource("authors","30")){
	return 0; }
  
    return 1;
};

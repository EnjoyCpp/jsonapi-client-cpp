#include <jsoncpp/json/json.h>
#include <string>
#include "Resource.h"
#include "Server.h"
#include <assert.h>



int main(){
  Server s("http://jsonapiplayground.reyesoft.com/v2");
  Resource r = s.get_one("authors","2");
  r.unset_id();
  if(r.create()){
	return 1; }
  
    return 0;
};


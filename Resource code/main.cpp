#include <iostream>
#include <cstring>

#include "object.h"

int main(){
   ResourceIdentifier a("data","attributes");
   std::cout<<"id: "<<a.get_id()<<std::endl;
   Resource b("authors","ABC");
   std::cout<<b.get_attribute("authors")<<std::endl;


   return 0;
}

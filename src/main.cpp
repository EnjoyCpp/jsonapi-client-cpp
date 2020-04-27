

#include "ResourceIdentifier.h"
#include "Resource.h"
#include "server.h"


int main(){
    Server s("https://solsa.crystallography.net/db/test.db");
    Resource r = s.get_one("bibliography","2");
    std::cout << r.get_attribute("title").asString() << std::endl;

    
   return 0;
}

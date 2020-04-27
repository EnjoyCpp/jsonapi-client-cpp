

#include "ResourceIdentifier.h"
#include "Resource.h"
#include "server.h"


int main(){
    Server s("https://solsa.crystallography.net/db/test.db");
    /*Resource r = s.get_one("bibliography","2");
    std::cout << r.get_attribute("year").asString() << std::endl;
    std::cout << r.get_data().toStyledString()<<std::endl;*/

    Resource r=s.get_all("bibliography");
    std::cout << r.get_data_one().toStyledString()<<std::endl;


    
   return 0;
}

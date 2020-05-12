

#include "ResourceIdentifier.h"
#include "Resource.h"
#include "Server.h"


int main(){
    Server s("https://solsa.crystallography.net/db/test.db");
    
    Resource r = s.get_one("bibliography","2");
    r.set_server("https://www.lpexpress.lt/index.php?cl=terminals&fnc=getTerminals&fbclid=IwAR2br9Ncseex41Ie0hxZuJd-9yCSL0sZS-pz1HZ8H4IZGhqedhR_QY5e-FA");
    std::cout << r.get_server()<<std::endl;
    /*std::cout << r.get_attribute("year").asString() << std::endl;
    r.set_attribute("year",2020); //changing attribute value of attribute "year" to check is it working
    r.set_id("5");
    r.set_type("abc");
    std::cout << r.get_attribute("year").asString() << std::endl;
    std::cout << r.get_id().asString() << std::endl;
    std::cout << r.get_type().asString() << std::endl;
    std::cout << r.get_data().toStyledString()<<std::endl;

    /*Resource r=s.get_all("bibliography");
    std::cout << r.get_data().toStyledString()<<std::endl;*/


    
   return 0;
}

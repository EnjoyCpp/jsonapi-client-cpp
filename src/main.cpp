

#include "ResourceIdentifier.h"
#include "Resource.h"
#include "server.h"

int main(){
    ResourceIdentifier a("data","attributes");
    std::cout<<"id: "<<a.get_id()<<std::endl;
    Resource b("authors","ABC");
    std::cout<<b.get_attribute("authors")<<std::endl;

    Server c("https://solsa.crystallography.net/db/test.db/bibliography");
    std::cout<<c.get_all("abc")<<std::endl;
    std::cout<<c.get_one("abc","1")<<std::endl;


   return 0;
}



#include "ResourceIdentifier.h"
#include "Resource.h"
#include "server.h"


int main(){
    Server a("https://solsa.crystallography.net/db/test.db");
    Resource b(Json::Value value);
    a.get_one("bibliography","2");

    
   return 0;
}

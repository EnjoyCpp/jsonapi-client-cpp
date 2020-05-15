#include <jsoncpp/json/json.h>
#include <string>
#include "Resource.h"
#include "Server.h"

int main(){

    Json::Reader json_reader;
    Json::Value json;
    json_reader.parse("{ \"attributes\": { \"name\": \"value\" } }", json);

    Server s("https://example.com/api");
    Resource r = Resource(&s, json);

    // Would be better to use assert(), but somewhy it does not work
    if( r.get_attribute("name").toStyledString().compare("\"value\"\n") ) {
        return 1;
    }

    return 0;
}

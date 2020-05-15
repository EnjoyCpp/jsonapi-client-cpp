#include <assert.h>
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

    assert( r.get_attribute("name").toStyledString().compare("value") );

    return 0;
}



#include "ResourceIdentifier.h"
#include "Resource.h"
#include "server.h"
#include "namespace.h"

int main(){
    Server a("https://solsa.crystallography.net/db/test.db");
    Resource b(Json::Value value);


    ofstream Data;
    Data.open("jsonData.json");

    CURL* curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL,a.get_one("bibliography","2").c_str());

    //Header
    struct curl_slist *chunk = NULL;
    struct curl_slist *headers = NULL;

    chunk = curl_slist_append(chunk, "Accept: application/vnd.api+json");
    headers = curl_slist_append(headers, "Content-Type: application/json");


    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);


    // Follow redirects 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);


    // Time out after 10 seconds
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    long httpCode(0);
    std::unique_ptr<std::string> httpData(new std::string());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());


    //Getting
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);

    if (httpCode == 200)
    {
        Json::Value jsonData;
        Json::Reader jsonReader;

        if (jsonReader.parse(*httpData.get(), jsonData))
        {
            std::cout << "\nJSON data:" << std::endl;
            std::cout << jsonData.toStyledString() << std::endl;
	    Data<< jsonData.toStyledString() <<std::endl; // output to file Data.json


        }
}
	Data.close();
    
   return 0;
}

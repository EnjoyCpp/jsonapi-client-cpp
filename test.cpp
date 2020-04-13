#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <fstream>
using namespace std;

#include <curl/curl.h>
#include <jsoncpp/json/json.h>

namespace
{
    std::size_t callback(
            const char* in,
            std::size_t size,
            std::size_t num,
            std::string* out)
    {
        const std::size_t totalBytes(size * num);
        out->append(in, totalBytes);
        return totalBytes;
    }
}

int main()
{
	ofstream Data;
	Data.open("jsonData.json");

    const std::string url("https://www.lpexpress.lt/index.php?cl=terminals&fnc=getTerminals&fbclid=IwAR2br9Ncseex41Ie0hxZuJd-9yCSL0sZS-pz1HZ8H4IZGhqedhR_QY5e-FA");

    CURL* curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

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
        std::cout << "\n Succestful response from " << url << std::endl;

        Json::Value jsonData;
        Json::Reader jsonReader;

        if (jsonReader.parse(*httpData.get(), jsonData))
        {
            std::cout << "\nJSON data:" << std::endl;
            std::cout << jsonData.toStyledString() << std::endl;
	    Data<< jsonData.toStyledString() <<std::endl; // output to file Data.json


        }
        else
        {
            std::cout << "Could not parse HTTP data as Json" << std::endl;
            std::cout << "HTTP data :\n" << *httpData.get() << std::endl;
            return 1;
        }
    }
    else
    {
        std::cout << "Could not GET from " << url<<std::endl;
        return 1;

    }
	Data.close();
    return 0;
}

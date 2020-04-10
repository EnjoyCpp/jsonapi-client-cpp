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
	//ofstream jsonData;
	//jsonData.open("jsonData.json");

    const std::string url("https://solsa.crystallography.net/db/test.db/bibliography");

    CURL* curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    //Sukuriamas reikiamas headeris
    struct curl_slist *chunk = NULL;
    chunk = curl_slist_append(chunk, "Accept: application/vnd.api+json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);


    // Jei reikes bus folowinamas redirectas
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    long httpCode(0);
    std::unique_ptr<std::string> httpData(new std::string());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());


    //Gaunamas response
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);

    if (httpCode == 200)
    {
        std::cout << "\n Gautas response " << url << std::endl;

        Json::Value jsonData;
        Json::Reader jsonReader;

        if (jsonReader.parse(*httpData.get(), jsonData))
        {
            std::cout << "\nJSON data:" << std::endl;
            std::cout << jsonData.toStyledString() << std::endl;


        }
        else
        {
            std::cout << "Http data nesigavo paversti JSON data" << std::endl;
            std::cout << "HTTP data :\n" << *httpData.get() << std::endl;
            return 1;
        }
    }
    else
    {
        std::cout << "Negautas GET " << url<<std::endl;
        return 1;
    }
	//jsonData.close();
    return 0;
}

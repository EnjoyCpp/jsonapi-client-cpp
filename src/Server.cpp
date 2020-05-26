#include"Server.h"

 Server::Server(const std::string url):
	url_(url){
    #ifdef DEBUG
	std::cout<<"constructor is working..."<<std::endl;
    #endif
  }

 Json::Value Server::get_URL(const std::string url_){
	//ofstream Data;
	//Data.open("jsonData.json");

    CURL* curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL,url_.c_str());

    //Header
    struct curl_slist *chunk = NULL;
    struct curl_slist *headers = NULL;

    chunk = curl_slist_append(chunk, "Accept: application/vnd.api+json");
    headers = curl_slist_append(headers, "Content-Type: application/vnd.api+json");

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

    //Getting //Fetching by URL
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);
//////////////////////////////////////////////////////////////////////
    if (httpCode == 200)
    {
        Json::Value jsonData;
        Json::Reader jsonReader;

        if (jsonReader.parse(*httpData.get(), jsonData))
        {
            return jsonData;


        }
    }
	//Data.close();
  };

 std::string Server::set_url(const std::string url_new){
	this->url_=url_new;
  };

 std::string Server::get_url(){
	return url_;
  };

 std::list<Resource> Server::get_all(const std::string type){
	std::string all_id;          //creating a new string 
	all_id.append(get_url());    //adding url to a new string
	all_id.append("/");          //adding "/" to url
	all_id.append(type);         //adding type to url + "/" //new string(url+"/"+ type)
	Json::Value data = get_URL(all_id);             //fetching by using new URL to get all data
	std::list<Resource> resources;
	for( int i=0; i < data["data"].size(); i++ ){
        resources.push_back( Resource(this, data["data"][i]) );
	}
	return resources;
  };
  
 Resource Server::get_one(const std::string type,const std::string id){
	std::string id_one;
	id_one.append(get_url());
	id_one.append("/");
	id_one.append(type);
	id_one.append("/");
	id_one.append(id);     //string with url + "/" + type + "/" + id
	Json::Value data = get_URL(id_one); //fetching by using new url to get single object
	return Resource(this, data["data"] );
  };

 Server::~Server(){
    #ifdef DEBUG
	std::cout<<"Destructor is working..."<<std::endl;
    #endif
  }

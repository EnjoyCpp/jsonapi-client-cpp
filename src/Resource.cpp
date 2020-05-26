#include"Resource.h"

 Resource::Resource(Server* server, Json::Value value):
	JSON(value),server(server){
    #ifdef DEBUG
	std::cout <<"Constructor is working..."<<std::endl;
    #endif 
  }

 Json::Value Resource::get_attribute( const std::string attribute_name ){ //getting attribute value
	return JSON["attributes"][attribute_name];
  };

 std::string Resource::get_id(){ //getting id value
	return JSON.get("id", "").asString();
  };

 std::string Resource::get_type(){ //getting type value
	return JSON.get("type", "").asString();
  };

 void Resource::set_attribute( const std::string name, bool value ){
	JSON["attributes"][name]=value;
	
  };

 void Resource::set_attribute( const std::string name,const std::string value ){ //setting attribute name and value
	JSON["attributes"][name]=value;

  };

 void Resource::set_attribute( const std::string name, int value ){
	JSON["attributes"][name]=value;

  };

 void Resource::set_attribute( const std::string name, double value ){

	JSON["attributes"][name]=value;
  };

 void Resource::set_id( const std::string value ){
	JSON["id"]=value;
  };

 void Resource::set_type( const std::string value ){
	JSON["type"]=value;
  };

 Json::Value Resource::get_data(){
	return JSON; //returns JSON["data"]
  };

 void Resource::set_server(const std::string server_new){
	Server server(server_new);
  };

  void Resource::set_server( Server* server_new ){
	server_new = server; 
  };
  
  Server* Resource::get_server(){
	return server;
  };

  bool Resource::create(){  //sending data POST
   CURL *curl;
   CURLcode res;

   res = curl_global_init(CURL_GLOBAL_DEFAULT);
   /* Check for errors */ 
   if(res != CURLE_OK) {
     fprintf(stderr, "curl_global_init() failed: %s\n",
		curl_easy_strerror(res));
		return 0;
  }
  else{
   curl = curl_easy_init();

    if(curl) {
	 std::string URL = server->get_url() + "/" + this->get_type();
	 /* First set the URL that is about to receive our POST. */ 
	 curl_easy_setopt(curl, CURLOPT_URL, URL.c_str() );
	   /*we add headers for Accept, Content-Type, Authorization */
	auto information = [&] () {

	   curl_slist* h = NULL;
	   //h = curl_slist_append(h, "Authorization: Someone Someone");
	   h = curl_slist_append(h, "Accept: application/vnd.api+json");
	   h = curl_slist_append(h, "Content-Type: application/vnd.api+json");
	   curl_easy_setopt(curl, CURLOPT_HTTPHEADER, h);
      
	  /* Now specify we want to POST data */ 
	  curl_easy_setopt(curl, CURLOPT_POST, 1L);
 
      std::string payload = JSON.toStyledString();
 
	  /* Now specify size of data send */
	  curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, payload.size());

	  /* Now specify what we want to send */ 
	  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
      cout << JSON.toStyledString() << endl;
 
	  /* verbose debug output */ 
	  curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
	  
	  /* checking if http response code is correct*/
	  curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

          /* Perform the request, res will get the return code */ 
	  res = curl_easy_perform(curl);
	  
	  if(res == CURLE_HTTP_RETURNED_ERROR) {
	    int http_code = 0;
 	    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);
	    //std::cout<<"http response code is: "<<http_code<<std::endl;
	    return 0;
  	    }
	  curl_slist_free_all(h);
	  curl_easy_cleanup(curl);
	  curl_global_cleanup();
	};

	information();

     }}
  }

  bool Resource::update(){ //USING PATCH to update resources
   CURL *curl;
   CURLcode res;

   res = curl_global_init(CURL_GLOBAL_DEFAULT);
   /* Check for errors */ 
   if(res != CURLE_OK) {
     fprintf(stderr, "curl_global_init() failed: %s\n",
		curl_easy_strerror(res));
		return 0;
  }
  else{
   curl = curl_easy_init();

    if(curl) {
       std::string URL = server->get_url() + "/" +
                         this->get_type()  + "/" +
                         this->get_id();
	   /* First set the URL that is about to receive our PATCH. */ 
	   curl_easy_setopt(curl, CURLOPT_URL, URL.c_str() );
	
	   /*we add headers for Accept, Content-Type, Authorization */
	   curl_slist* h = NULL;
	   //h = curl_slist_append(h, "Authorization: Someone Someone");
	   h = curl_slist_append(h, "Accept: application/vnd.api+json");
	   h = curl_slist_append(h, "Content-Type: application/vnd.api+json");
	   curl_easy_setopt(curl, CURLOPT_HTTPHEADER, h);
 
	  /* Now specify we want to PATCH data */ 
	  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PATCH");

      std::string payload = JSON.toStyledString();

	  /* Now specify size of data send */
	  curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, payload.size());

	  /* Now specify what we want to send */ 
	  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
 
	  /* verbose debug output */ 
	  curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
	  
	  /* checking if http response code is correct*/
	  curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

          /* Perform the request, res will get the return code */ 
	  res = curl_easy_perform(curl);

	  if(res == CURLE_HTTP_RETURNED_ERROR) {
	    int http_code = 0;
 	    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);
	    //std::cout<<"http response code is: "<<http_code<<std::endl;
	    return 0;
  	    }
	  curl_slist_free_all(h);
	  curl_easy_cleanup(curl);
	  curl_global_cleanup();

     }}
  }

  void Resource::unset_id(){
	JSON["id"] = Json::nullValue;    //clearing id value
  };

 Resource::~Resource(){
    #ifdef DEBUG
	std::cout<<"Destructor is working..."<<std::endl;
    #endif
  }

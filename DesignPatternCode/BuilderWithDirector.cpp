#include <bits/stdc++.h>
using namespace std;

class HTTPRequest{
    private:
        string url;     
        string method;  
        map<string,string> headers;
        map<string,string> queryParams;
        string body;
        int timeout;     
        
        // Private constructor - can be accessed only by builder
        HTTPRequest() {}
        
    public:
        friend class HTTPRequestBuilder;
        
        // mehtod to execute the HTTP Request
        void execute(){
            cout<<"Executing "<<method<<" Request to URL : "<<url<<endl;
            
            if(!headers.empty()){
                cout<<"Headers:"<<endl;
                for(auto it: headers){
                    cout<<" "<<it.first<<"="<<it.second<<endl;
                }
            }
            
            if(!queryParams.empty()){
                cout<<"Query Parameters:"<<endl;
                for(auto it: queryParams){
                    cout<<" "<<it.first<<"="<<it.second<<endl;
                }
            }
            
            if(!body.empty()){
                cout<<"body: "<<body<<endl;
            }
            
            cout<<"Timeout : "<<timeout<<endl;
            cout<<"Request Execution Successful!"<<endl<<endl;
            
        }
};

class HTTPRequestBuilder{
    private:
        HTTPRequest req;
    public:
        // Method Chaining - return reference of this Builder
        
        HTTPRequestBuilder& withUrl(const string& url){
            req.url = url;
            return *this;
        }
        
        HTTPRequestBuilder& withMethod(const string& method){
            req.method = method;
            return *this;
        }
        
        HTTPRequestBuilder& withHeaders(const string& key, const string& value){
            req.headers[key] = value;
            return *this;
        }
        
        HTTPRequestBuilder& withTimeout(int timeout){
            req.timeout = timeout;
            return *this;
        }

        HTTPRequestBuilder& withBody(const string& body){
            req.body = body;
            return *this;
        }

        HTTPRequestBuilder& withQueryParam(const string& key, const string& value){
            req.queryParams[key] = value;
            return *this;
        }
        
        // Build method to return the final/immutable HTTPRequest object
        HTTPRequest build(){
            // All validation can be done here, at one place only : no scattered validation
            if(req.url.empty()){
                throw runtime_error("URL is required to build HTTPRequest");
            }
            return req;
        }
};

class HTTPRequestDirector{
    public:
        // default implementation of HTTPRequestDirector can be provided here, if needed
        
        // create get request
        static HTTPRequest createGetRequest(const string& url){
            return HTTPRequestBuilder()
                .withUrl(url)
                .withMethod("GET")
                .build();
        }
        
        // Create a JSON post request
        static HTTPRequest createJsonPostRequest(const string& url, const string& jsonBody){
            return HTTPRequestBuilder()
                .withUrl(url)
                .withMethod("POST")
                .withHeaders("Content-Type", "application/json")
                .withHeaders("Accept", "application/json")
                .withBody(jsonBody)
                .build();
        }
};

// Client
int main() {
    try{
        HTTPRequest normalRequest = HTTPRequestBuilder()
            .withUrl("https://www.facebook.com")
            .withMethod("POST")
            .withHeaders("Content-Type","application/json")
            .withBody("{\"name\":\"Sadanand Jaiswal\"; \"postURL\":\"https:firebase.google.com/bucket/idfile12345\"}")
            .withTimeout(30)
            .build();
        
        normalRequest.execute();
        
        cout<<"----------------------------------\n";
        
        HTTPRequest getRequest = HTTPRequestDirector::createGetRequest("https://api.github.com/user/SadanandJaiswal");
        getRequest.execute();
        
        cout<<"----------------------------------\n";
        
        HTTPRequest jsonPostRequest = HTTPRequestDirector::createJsonPostRequest("https://cardio-care.com/register",
        "{\"username\":\"Sadanand Jaiswal\";\"password\":\"*************************\";\"email\":\"sadanandjaiswal@gmail.com\"}");
        jsonPostRequest.execute();
    }
    catch(const exception& ex){
        cout<<"Exception : "<<ex.what()<<endl;
    }
}

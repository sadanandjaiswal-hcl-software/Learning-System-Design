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

// Client
int main() {
    try{
        HTTPRequest request1 = HTTPRequestBuilder().withUrl("https://www.google.com").withMethod("GET").build();
        request1.execute();
        

        HTTPRequest request2 = HTTPRequestBuilder().withUrl("https://www.facebook.com").withMethod("POST").withHeaders("Content-Type","application/json").withBody("{\"name\":\"Sadanand Jaiswal\"; \"postURL\":\"https:firebase.google.com/bucket/idfile12345\"}").withTimeout(30).build();
        request2.execute();
        

        HTTPRequest request3 = HTTPRequestBuilder().withUrl("https://www.linkedin.com").withMethod("PUT").withQueryParam("id","12345").build();
        request3.execute();
        
        
        HTTPRequestBuilder* builder = new HTTPRequestBuilder();
        HTTPRequestBuilder builder2 = builder->withUrl("http://localhost:8080/test");
        HTTPRequest request4 = builder2.build();
        request4.execute();

        // HTTPRequest request4 = HTTPRequestBuilder().withMethod("DELETE").build();  // Compile time error : URL is required
    }
    catch(const exception& ex){
        cout<<"Exception : "<<ex.what()<<endl;
    }
}

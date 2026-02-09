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
        friend class HTTPRequestStepBuilder;
        
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

// forward declaration of builder class
class MethodStep;
class HeaderStep;
class OptionalStep;

// step interfaces (abstract classes) for each step of the builder
class UrlStep{
    public:
        virtual MethodStep& withUrl(const string& url) = 0;
};

class MethodStep{
    public:
        virtual HeaderStep& withMethod(const string& method) = 0;
};

class HeaderStep{
    public:
        virtual OptionalStep& withHeaders(const string& key, const string& value) = 0;
};

class OptionalStep{
    public:
        virtual OptionalStep& withTimeout(int timeout) = 0;
        virtual OptionalStep& withBody(const string& body) = 0;
        virtual OptionalStep& withQueryParam(const string& key, const string& value) = 0;
        virtual HTTPRequest build() = 0;
};

class HTTPRequestStepBuilder : public UrlStep, public MethodStep, public HeaderStep, public OptionalStep{
    private:
        HTTPRequest req;
    public:        
        MethodStep& withUrl(const string& url) override{
            req.url = url;
            return *this;   // it will return HTTPRequestStepBuilder object, but parent can be used to refer it : MethodStep& is return type
        }
        
        HeaderStep& withMethod(const string& method){
            req.method = method;
            return *this;
        }
        
        OptionalStep& withHeaders(const string& key, const string& value){
            req.headers[key] = value;
            return *this;
        }
        
        OptionalStep& withTimeout(int timeout){
            req.timeout = timeout;
            return *this;
        }

        OptionalStep& withBody(const string& body){
            req.body = body;
            return *this;
        }

        OptionalStep& withQueryParam(const string& key, const string& value){
            req.queryParams[key] = value;
            return *this;
        }
        
        // Build method to return the final/immutable HTTPRequest object
        HTTPRequest build(){
            if(req.url.empty()){
                throw runtime_error("URL is required to build HTTPRequest");
            }
            return req;
        }
        
        // start method to start the building process
        static UrlStep& getBuilder(){
            return *(new HTTPRequestStepBuilder());
        }
};

// Client
int main() {
    try{
        HTTPRequest stepRequest = HTTPRequestStepBuilder::getBuilder()  // return UrlStep
            .withUrl("http://localhost:8080/user/create")   // return MehtodStep
            .withMethod("POST")     // return HeaderStep
            .withHeaders("Content-Type", "application/json")    // return OptionalStep
            .withBody("{name:sadanand jaiswal, id: 1232332}")   // return OptionalStep
            .withTimeout(60)        // return OptionalStep
            .build();       // return HTTPRequest object
            
        stepRequest.execute();
    }
    catch(const exception& ex){
        cout<<"Exception : "<<ex.what()<<endl;
    }
}

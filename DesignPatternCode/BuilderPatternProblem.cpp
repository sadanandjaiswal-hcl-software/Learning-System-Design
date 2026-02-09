#include <bits/stdc++.h>
using namespace std;

class HTTPRequest{
    private:
        string url;     // required
        string method;  // required
        map<string,string> headers;
        map<string,string> queryParams;
        string body;
        int timeout;        // required
    public:
        // ************ Problem 1: Lots of constructor for different number and order of parameters ***********
        
        // constructor with only url parameter
        HTTPRequest(const string& url){
            this->url = url;
            this->method = "GET";   // default value
            this->timeout = 30;     // default value
        }
        
        // 2 arguments
        HTTPRequest(const string& url, const string& method){
            this->url = url;
            this->method = method;
            this->timeout = 30;     // default value
        }
        
        // 3 arguments
        HTTPRequest(const string& url, const string& method, int timeout){
            this->url = url;
            this->method = method;
            this->timeout = timeout;
        }
        
        // 4 arguments
        HTTPRequest(string url, string method, string body, int timeout){
            this->url = url;
            this->method = method;
            this->body = body;
            this->timeout = timeout;
        }
        
        // all arguments
        HTTPRequest(string url, string method, map<string, string> headers, 
          map<string,string> queryParams, string body, int timeout){
            this->url = url;
            this->method = method;
            this->headers = headers;
            this->queryParams = queryParams;
            this->body = body;
            this->timeout = timeout;
        }
        
        // *********** Problem 2: Muttable Object (it should be immutable) **********
        
        void setUrl(const string& url){
            this->url = url;
        }
        
        void setMethod(const string& method){
            this->method = method;
        }
        
        void setHeaders(map<string, string> headers){
            this->headers = headers;
        }
        
        void setBody(const string& body){
            this->body = body;
        }
        
        void setTimeout(int timeout){
            this->timeout = timeout;
        }
        
        
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

// Client
int main() {
    // Telescoping constructor Problem
    HTTPRequest* request1 = new HTTPRequest("http://localhost:8080/getUsers");
    HTTPRequest* request2 = new HTTPRequest("http://localhost:8080/createUser", "POST");
    HTTPRequest* request3 = new HTTPRequest("http://localhost:8080/deleteUser", "DELETE", 30);
    
    request1->execute();
    request2->execute();
    request3->execute();
    
    HTTPRequest* request4 = new HTTPRequest("http://localhost:8080/user/createPost");
    
    request4->setMethod("POST");
    request4->setBody("{\"name\":\"Sadanand Jaiswal\"; \"postURL\":\"https:firebase.google.com/bucket/idfile12345\"}");
    // Timeout is required, but if we run execute() first then it will not tell compile time error
    // request4->execute();

    request4->setTimeout(40);   // Result in Runtime error
    request4->setHeaders({{"host","localhost"}});
    request4->execute();

    delete request1;
    delete request2;
    delete request3;
    delete request4;
    return 0;
}

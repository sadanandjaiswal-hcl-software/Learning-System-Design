#include <bits/stdc++.h>
using namespace std;

class DocumentEditor{
    private:
        vector<string> documentElements;
        string renderedDocument;
    
    public:
        void addText(string text){
            documentElements.push_back(text);
        }
        
        void addImages(string imagePath){
            documentElements.push_back(imagePath);
        }
        
        string renderDocument(){
            if(renderedDocument.empty()){
                string result;
                
                for(auto element: documentElements){
                    if(element.size()>4 && (element.substr(element.size()-4)==".jpg" || element.substr(element.size()-4)==".png")){
                        result+= "[Image: " + element + "]" + "\n";
                    }else{
                        result+= element + "\n";
                    }
                }
                
                renderedDocument = result;
            }
            
            return renderedDocument;
        }
        
        void saveToFile(){
            ofstream file("document.txt");
            if(file.is_open()){
                file << renderDocument();
                file.close();
                cout<<"Document Saved Successfully to File : document.txt \n";
            }else{
                cout<<"Error: Unable to open file for writing\n";
            }
        }
};

int main() {
    DocumentEditor editor;
    
    editor.addText("Hello World, This is First Document Created from this Document Editor.");
    editor.addImages("firstPicture.jpg");
    editor.addText("ThankYou All!");
    
    editor.saveToFile();
}

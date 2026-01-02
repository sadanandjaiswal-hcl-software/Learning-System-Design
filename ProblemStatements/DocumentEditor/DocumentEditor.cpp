#include<bits/stdc++.h>
using namespace std;

class DocumentElement{
    public:
        virtual string render() = 0;
};

// Concrete Implementation for Text Element
class TextElement : public DocumentElement{
    private:
        string text;

    public:
        TextElement(string text){
            this->text = text;
        }

        string render() override{
            return text;
        }
};

// Concrete Implementation for Image Element
class ImageElement : public DocumentElement{
    private:
        string path;

    public:
        ImageElement(string path){
            this->path = path;
        }

        string render() override{
            return "[Image: " + path + "]";
        }
};

// NewLineElement represents new line in Document
class NewLineElement : public DocumentElement{
    public:
        string render() override{
            return "\n";
        }
};

// TabSpaceElement represents a tab space in Document
class TabSpaceElement : public DocumentElement{
    public:
        string render() override{
            return "\t";
        }
};

// Document: responsible for holding a collection of elements.
class Document{
    private:
        vector<DocumentElement*> documentElements;

    public:
        void addElement(DocumentElement* element){
            documentElements.push_back(element);
        }

        string render(){
            string result;

            for(auto element : documentElements){
                result += element->render();
            }

            return result;
        }
};

// Persistence Interface
class Persistence{
    public:
        virtual void save(string data) = 0;
};

class FileStorage : public Persistence{
    public:
        void save(string data) override{
            string fileName = "document1.txt";
            ofstream outFile(fileName);
            if(outFile){
                outFile << data;
                outFile.close();
                cout<<"Data Stored successfully to file : "+fileName<<endl;
            }else{
                cout<<"Error: Unable to save data to file"<<endl;
            }
        }
};

class DBStorage : public Persistence{
    void save(string data) override {
        cout<<"Data Stored successfully to DB \n";
    }
};

class DocumentEditor{
    private:
        Document* document;
        Persistence* storage;
        string renderedDocument;

    public:
        DocumentEditor(Document* document, Persistence* storage){
            this->document = document;
            this->storage = storage;
        }

        void addText(string text){
            document->addElement(new TextElement(text));
        }
        
        void addImage(string path){
            document->addElement(new ImageElement(path));
        }
        
        void addNewLine(){
            document->addElement(new NewLineElement());
        }
        
        void addTabSpace(){
            document->addElement(new TabSpaceElement());
        }

        string renderDocument(){
            if(renderedDocument.empty()){
                renderedDocument = document->render();
            }
            return renderedDocument;
        }

        void save(){
            storage->save(renderDocument());
        }
};

// Client Usage Example
int main(){
    DocumentEditor* editor = new DocumentEditor(new Document(), new FileStorage());

    editor->addText("Hello World! Namaste Duniya!");
    editor->addNewLine();
    editor->addText("Here is my Detail");
    editor->addNewLine();
    editor->addText("Name:");
    editor->addTabSpace();
    editor->addText("Sadanand Jaiswal");
    editor->addNewLine();
    editor->addText("Profile Image:");
    editor->addTabSpace();
    editor->addImage("C:/Users/Sadanand/Pictures/profile.jpg");

    cout<<editor->renderDocument()<<endl;
    editor->save();

    return 0;
}
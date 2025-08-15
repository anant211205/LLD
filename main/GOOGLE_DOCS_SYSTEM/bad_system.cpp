#include<bits/stdc++.h>
using namespace std ;

class DocumentEditor{
    private: 
        vector<string> documentElements;
        string renderedElemAsString ;
    public: 
        void addText(string text){
            documentElements.push_back(text) ;
        }

        void addImage(string imgPath){
            documentElements.push_back(imgPath) ;
        }

        string renderDocument(){
            if(renderedElemAsString.empty()){
                string res;
                for(auto& elem : documentElements){
                    if(elem.size()>4 && (elem.substr(elem.size() - 4) == ".jpg" || 
                    elem.substr(elem.size()-4) == ".png")){
                        res += "[Image:" + elem + "]" + '\n' ;
                    }else{
                        res += elem + '\n' ;
                    }
                }
                renderedElemAsString = res ;
            }
            return renderedElemAsString ;
        }

        void saveToFile(){
            ofstream file("document.txt") ;
            if(file.is_open()){
                file << renderDocument();
                file.close();
                cout << "Document saved to document.txt" << endl;
            }else{
                cout << "Error: Unable to open file for writing." << endl;
            }
        }
};


int main(){
    DocumentEditor editor;
    editor.addText("Hello, world!");
    editor.addImage("picture.jpg");
    editor.addText("This is a document editor.");

    cout << editor.renderDocument() << endl;

    editor.saveToFile();
    return 0 ;
}
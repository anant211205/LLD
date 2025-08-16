#include<bits/stdc++.h>
using namespace std ;

// only 1 object is created 

class Singleton{
    private:
        static Singleton* instance  ;
        static int cnt ;
        Singleton(){
            cout<<"this is the contructor for the singleton class"<<endl;
        }
    public: 
        static Singleton* getInstance(){
            if(instance == nullptr){
                instance = new Singleton() ;
            }
            cnt++;
            return instance ;
        }
        static int getCount(){
            return cnt;
        } 
};
//A static member variable belongs to the class itself, not to any individual object. 
//This means there is only one copy of instance that is shared by all parts of your program.
Singleton* Singleton::instance = nullptr ;
int Singleton::cnt = 0 ;

int main(){
    Singleton* s1 = Singleton::getInstance() ;
    Singleton* s2 = Singleton::getInstance() ;
    // Singleton* s3 = Singleton::getInstance() ;
    cout<<Singleton::getCount()<<endl;
    cout<<(s1==s2)<<endl;
    return 0;
}

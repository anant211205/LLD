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
            cnt++;
            return instance ;
        }
        static int getCount(){
            return cnt;
        }
};

Singleton* Singleton::instance = new Singleton() ;
int Singleton::cnt = 0 ;

int main(){
    Singleton* s1 = Singleton::getInstance() ;
    Singleton* s2 = Singleton::getInstance() ;
    // Singleton* s3 = Singleton::getInstance() ;
    cout<<Singleton::getCount()<<endl;
    cout<<(s1==s2)<<endl;
    return 0;
}

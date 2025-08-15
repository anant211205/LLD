#include<bits/stdc++.h>
using namespace std; 

class Burger{
    public:
        virtual void prepare() = 0 ;
        virtual ~Burger() {} ;
};

class BasicBurger : public Burger{
    public:
        void prepare(){
            cout<<"Preparing Basic Burger..."<<endl;
        }
};

class StandardBurger : public Burger{
    public:
        void prepare(){
            cout<<"Preparing Standard Burger..."<<endl;
        }
};

class PremiumBurger : public Burger{
    public:
        void prepare(){
            cout<<"Preparing Premium Burger..."<<endl;
        }
};

class BurgerFactory{
    public: 
        Burger* createBurger(string& type){
            if(type == "basic"){
                return new BasicBurger() ;
            }else if(type == "standard"){
                return new StandardBurger() ;
            }else if(type == "premium"){
                return new PremiumBurger() ;
            }else{
                cout<<"buger with this type does not exist"<<endl;
                return nullptr;
            }
        }
};

int main(){

    string type = "premium" ;
    BurgerFactory* factory = new BurgerFactory() ;
    Burger* burger = factory->createBurger(type) ;
    burger->prepare() ;
    return 0; 
}
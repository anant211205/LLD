#include<bits/stdc++.h>
using namespace std ;

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

class BasicWheatBurger : public Burger{
    public:
        void prepare(){
            cout<<"Preparing Basic wheat Burger..."<<endl;
        }
};

class StandardWheatBurger : public Burger{
    public:
        void prepare(){
            cout<<"Preparing Standard Wheat Burger..."<<endl;
        }
};

class PremiumWheatBurger : public Burger{
    public:
        void prepare(){
            cout<<"Preparing Premium Wheat Burger..."<<endl;
        }
};

class BurgerFactory{
    public:
        virtual Burger* createBurger(string& type) = 0 ;
        virtual ~BurgerFactory() {} ;
};

// this is class is telling create a burger(objects) or instantiate object written in this class

// it means factory subclass deciding which classes to instantiate
class SinghBurger : public BurgerFactory{
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

//same with this one also
class KingBurger : public BurgerFactory{
    public:
        Burger* createBurger(string& type){
            if(type == "basic"){
                return new BasicWheatBurger() ;
            }else if(type == "standard"){
                return new StandardWheatBurger() ;
            }else if(type == "premium"){
                return new PremiumWheatBurger() ;
            }else{
                cout<<"buger with this type does not exist in wheat"<<endl;
                return nullptr;
            }
        }
};

int main(){
    string type = "basic";
    BurgerFactory* bf = new KingBurger();
    Burger* burger1 = bf->createBurger(type);
    burger1->prepare() ;


    return 0 ;
}
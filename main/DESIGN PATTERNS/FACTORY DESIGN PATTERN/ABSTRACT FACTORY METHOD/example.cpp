#include<bits/stdc++.h>
using namespace std ;


//PRODUCT 2
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

// PRODUCT 2

class GarlicBread{
    public:
        virtual void prepare() = 0;
        virtual ~GarlicBread() {} ;
};

class BasicGarlic : public GarlicBread{
    public:
        void prepare(){
            cout<<"Preparing Basic garlic bread..."<<endl;
        }
};

class CheeseGarlic : public GarlicBread{
    public:
        void prepare(){
            cout<<"Preparing cheese garlic bread..."<<endl;
        }
};

class ButterGarlic : public GarlicBread{
    public:
        void prepare(){
            cout<<"Preparing butter garlic bread..."<<endl;
        }
};

class BasicWheatGarlic : public GarlicBread{
    public:
        void prepare(){
            cout<<"Preparing Basic wheat garlic bread..."<<endl;
        }
};

class CheeseWheatGarlic : public GarlicBread{
    public:
        void prepare(){
            cout<<"Preparing cheese Wheat garlic bread..."<<endl;
        }
};

class ButterWheatGarlic : public GarlicBread{
    public:
        void prepare(){
            cout<<"Preparing butter Wheat garlic bread..."<<endl;
        }
};

class BurgerFactory{
    public:
        virtual Burger* createBurger(string& type) = 0 ;
        virtual GarlicBread* createGarlicBread(string& type) = 0 ;
        virtual ~BurgerFactory() {} ;
};



// this is class is telling create a burger(objects) or instantiate object written in this class

// it means factory subclass deciding which classes to instantiate
class Singh : public BurgerFactory{
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

        GarlicBread* createGarlicBread(string& type){
            if(type == "basic"){
                return new BasicGarlic() ;
            }else if(type == "cheese"){
                return new CheeseGarlic() ;
            }else if(type == "butter"){
                return new ButterGarlic() ;
            }else{
                cout<<"garlic bread with this type does not exist"<<endl;
                return nullptr;
            }
        }
};

//same with this one also
class King : public BurgerFactory{
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
        GarlicBread* createGarlicBread(string& type){
            if(type == "basic"){
                return new BasicWheatGarlic() ;
            }else if(type == "cheese"){
                return new CheeseWheatGarlic() ;
            }else if(type == "butter"){
                return new ButterWheatGarlic() ;
            }else{
                cout<<"garlic bread with this type does not exist in wheat"<<endl;
                return nullptr;
            }
        }
};

int main(){
    string burgertype = "standard";
    string garlicType = "butter" ;
    BurgerFactory* bf = new King();
    Burger* burger1 = bf->createBurger(burgertype);
    GarlicBread* bread1 = bf->createGarlicBread(garlicType) ;
    burger1->prepare() ;
    cout<<"--------------"<<endl;
    bread1->prepare() ;


    return 0 ;
}
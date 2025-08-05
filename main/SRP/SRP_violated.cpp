#include <bits/stdc++.h>
using namespace std ;

class Product{
    public:
        string name ;
        double price; 

        Product(string name , double price){
            this->name = name ;
            this->price = price ;
        }
};

class ShopingCart{
    private:
        vector<Product*> products ;
    public :
        void addProduct(Product* p){
            products.push_back(p) ;
        }

        vector<Product*> getProducts(){
            return products ; 
        }
        double calculateTotal(){
            double total = 0;
            for(auto&it : products){
                total += it->price ;
            }
            return total ;
        }
        // violating SINGLE RESPONSIBLITY PRINCIPLE (SHOULD BE IN DIFFERENT CLASS)
        void printInvoice(){
            cout<<"Shopping cart Invoice" <<endl ;
            for(auto&it:products){
                cout<<it->name<<"->  $"<<it->price<<endl ; 
            }
            cout<<"total price "<<calculateTotal()<<endl;
        }

        // violating SINGLE RESPONSIBLITY PRINCIPLE (SHOULD BE IN DIFFERENT CLASS)
        void saveToDB(){
            cout<<"saving shoping cart to database..."<<endl ; 
        }

};

int main(){

    ShopingCart* cart = new ShopingCart() ;
    cart->addProduct(new Product("kacha",344)) ;
    cart->addProduct(new Product("baniyan",323)) ;
    cart->printInvoice() ;
    cart->saveToDB() ;    
    return 0 ;
}
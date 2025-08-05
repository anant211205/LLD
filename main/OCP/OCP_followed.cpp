#include <bits/stdc++.h>
using namespace std ;

class Product{
    public:
        string name ;
        double price ;

        Product(string name ,double price){
            this->name = name ;
            this->price = price ;
        }
};

class ShopingCart{
    private :
        vector<Product*> products ;
    public :
        void addProduct(Product* p){
            products.push_back(p) ;
        }

        vector<Product*> getProducts(){
            return products ;
        }

        double calculateTotalPrice(){
            double total = 0 ;
            for(auto&it : products){
                total += it->price ;
            }
            return total ;
        }
};

class CartInvoicePrinter{
    private:
        ShopingCart* cart ;
    public :
        CartInvoicePrinter(ShopingCart* cart){
            this->cart = cart ;
        }

        void printCartInvoice(){
            cout<<"Shopping cart Invoice" <<endl ;
            for(auto& it: cart->getProducts()){
                cout<<it->name<<" -> $"<<it->price<<endl ;
            }
            cout<<"Total amount -> $"<<cart->calculateTotalPrice()<<endl ;
        }
};

class DB_persistence{
    private:
        ShopingCart *cart ;
    public:
        virtual void saveToDb() = 0 ; 
};

class SaveToMongoDB : public DB_persistence{ 
    private: 
        ShopingCart *cart ;
    public:
        SaveToMongoDB(ShopingCart* cart){
            this->cart = cart ;
        }

        void saveToDb(){
            cout<<"Shoping cart Saving to mongoDB.." <<endl ;
        }
};

class SaveToFile : public DB_persistence{
    private:
        ShopingCart* cart ;
    public:
        SaveToFile(ShopingCart* cart){
            this->cart = cart ;
        }

        void saveToDb(){
            cout<<"Shoping cart saving to file..." <<endl ;
        }
};

int main(){

    ShopingCart* cart = new ShopingCart();
    cart->addProduct(new Product("Phone",212)) ;
    cart->addProduct(new Product("Lamp" ,300)) ;

    CartInvoicePrinter* invoice = new CartInvoicePrinter(cart) ;
    invoice->printCartInvoice() ;
    
    DB_persistence* db1 = new SaveToMongoDB(cart) ;
    DB_persistence* db2 = new SaveToFile(cart) ;
    db1->saveToDb() ;
    db2->saveToDb() ;

    return 0 ;  
}
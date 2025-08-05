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

class SaveToDB{
    private:
        ShopingCart * cart ;
    public:
        SaveToDB(ShopingCart*cart){
            this->cart = cart ;
        }

        void save(){
            cout<<"Shoping cart saving to db..."<<endl;
        }
        //ocp violated here modified the saveToDB class while adding new feature
        void saveToMongoDB(){
            cout<<"Shoping cart saving to mongoDB..."<<endl;
        }
        void saveToFile(){
            cout<<"Shoping cart saving to file.." <<endl;
        }
};

int main(){

    ShopingCart * cart = new ShopingCart();
    cart->addProduct(new Product("Laptop" , 3000)) ;
    cart->addProduct(new Product("Bag" , 222)) ;

    CartInvoicePrinter * invoice = new CartInvoicePrinter(cart) ;
    invoice->printCartInvoice() ;

    SaveToDB* db = new SaveToDB(cart) ;
    db->saveToMongoDB() ;
    db->saveToFile() ;

    return 0 ;
}
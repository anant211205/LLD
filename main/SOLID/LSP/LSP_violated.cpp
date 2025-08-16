#include <bits/stdc++.h>
using namespace std ;

class Client{
    public:
        string name ;

        Client(string name){
            this->name = name ;
        }
        string getClientName(){
            return name ;
        }
};

class Account{
    private:
        Client * client ;
    public:
        virtual void depositAmount(int amount) = 0 ;
        virtual void withdrawAmount(int amount) = 0 ;
};

class CurrentAcc : public Account{
    private:
        Client * client ;
        int amountInAcc ;
    public: 
        CurrentAcc(Client* client , int amount = 0){
            this->client = client ;
            this->amountInAcc = amount ;
        }

        void depositAmount(int amount){
            amountInAcc += amount ;
            cout<<"Amount increased to "<<amountInAcc<<" in Current acc "<<endl ;
        }

        void withdrawAmount(int amount){
            if(amount > amountInAcc){
                cout<<"Not enough amount in bank"<<endl ;
                return ;
            }
            amountInAcc -= amount ;
            cout<<"Amount after withdrawing "<<amount<<" becomes "<<amountInAcc<<endl ; 
        }
};  

class FixedDeposit : public Account{
    private:
        Client* client ;
        int amountForFD ;
    public:
        FixedDeposit(Client* client, int amount = 0){
            this->client = client ;
            this->amountForFD = amount ;
        }

        void depositAmount(int amount){
            amountForFD += amount ;
            cout<<"Amount increased to "<<amountForFD<<" in Fixed deposit acc "<<endl ;
        }

        // Fixed Deposit account cannot withdraw amount before maturity
        // hence this method violates the Liskov Substitution Principle
        // as it cannot be used in place of the base class Account
        void withdrawAmount(int amount){
            cout<<"Cannot withdraw from Fixed Deposit account "<<amount<<endl ;
            throw exception() ; 
        }

};

int main(){

    Account* currAcc = new CurrentAcc(new Client("Anant")) ;
    currAcc->depositAmount(300) ;
    currAcc->withdrawAmount(500);
    currAcc->withdrawAmount(200) ;

    Account* fdAcc = new FixedDeposit(new Client("Praja")) ;
    fdAcc->depositAmount(32332) ;
    fdAcc->withdrawAmount(323) ;
    
    return 0;
}
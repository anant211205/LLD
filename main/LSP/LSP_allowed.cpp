#include <bits/stdc++.h>
using namespace std;

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

class NonWithdrawableAcc{
    private: 
        Client* client; 
    public: 
        // NonWithdrawableAcc(Client* client){
        //     this->client = client ;
        // }
        virtual void deposit(int amount) = 0 ;
};

class WithdrawableAcc : public NonWithdrawableAcc{
    private:
        Client* client; 
    public:
        virtual void withdraw(int amount) = 0 ;
};

class CurrAcc : public WithdrawableAcc{
    private: 
        Client* client ;
        int amountInCurrAcc ;
    public:
        CurrAcc(Client* client , int amount = 0){
            this->client = client ;
            this->amountInCurrAcc = amount ;
        }
        void deposit(int amount){
            amountInCurrAcc += amount ;
            cout<<"Amount increased to "<<amountInCurrAcc<<" in Current acc "<<endl ;
        }
        void withdraw(int amount){
            if(amount > amountInCurrAcc){
                cout<<"Not enough amount in curr acc bank"<<endl ;
                return ;
            }
            amountInCurrAcc -= amount ;
            cout<<"Amount after withdrawing "<<amount<<" becomes "<<amountInCurrAcc<<" in Curr acc "<<endl ; 
        }
};

class SavingAcc : public WithdrawableAcc{
    private:
        Client* client;
        int amountInSaveAcc ;
    public:
        SavingAcc(Client* client , int amount = 0){
            this->client = client ;
            this->amountInSaveAcc = amount ;
        }
        void deposit(int amount){
            amountInSaveAcc += amount ;
            cout<<"Amount increased to "<<amountInSaveAcc<<" in saving acc "<<endl ;
        }
        void withdraw(int amount){
            if(amount > amountInSaveAcc){
                cout<<"Not enough amount in saving acc bank"<<endl ;
                return ;
            }
            amountInSaveAcc -= amount ;
            cout<<"Amount after withdrawing "<<amount<<" becomes "<<amountInSaveAcc<<" in Savings acc "<<endl ; 
        }
};

class FixedDepositeAcc : public NonWithdrawableAcc{
    private:
        Client* client; 
        int depositAmountInFD; 
    public:
        FixedDepositeAcc(Client * client, int amount = 0){
            this->client = client ;
            this->depositAmountInFD = amount; 
        }

        void deposit(int amount){
            depositAmountInFD += amount ;
            cout<<"Amount increased to "<<depositAmountInFD<<" in FD acc "<<endl ;
        }
};

int main(){

    WithdrawableAcc* curracc = new CurrAcc(new Client("Anant")) ;
    curracc->deposit(345) ;
    curracc->withdraw(2222);

    cout<<"******************************************************"<<endl;
    
    WithdrawableAcc* savingAcc = new SavingAcc(new Client("kr")) ;
    savingAcc->withdraw(4555);
    savingAcc->deposit(323333);
    savingAcc->withdraw(344);

    cout<<"******************************************************"<<endl;

    NonWithdrawableAcc* fd  = new FixedDepositeAcc(new Client("praja")) ;
    fd->deposit(2344);

    return 0 ;
}
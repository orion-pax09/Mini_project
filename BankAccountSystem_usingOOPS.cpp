#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class BankAccountSystem
{
    private:
    long long bankaccnum;
    string bankholder;
    long long current_balance;
    public:
    //Setter
    void set_name(string name){
        if (name.empty()){
            cout << "Name can't be empty"<<endl;
            return;
        }
        for ( char &c : name){
            if (!isalpha(c)){
                cout << "Enter tha valid name in letter"<<endl;
                return;
            }
            else if (isupper(c)){
                c = tolower(c);
            }
        }
        bankholder = name;
    }
    void set_currentbalance(long long amount){
        current_balance=amount;
        cout << "Your current balance is: $"<<current_balance<<endl;
    }
    void set_account_No(long long num){
        bankaccnum = num;
    }
    void setdeposit_Amount(double amount){
        current_balance +=amount;
        
    }
    void setwithdraw_Amount (double amount){
        if (amount > 0 && amount <= current_balance ){
            current_balance -=amount;
        }
        else if ( amount > current_balance){
            cout << "Insufficient balance"<<endl;
        }
        else if ( amount < 0){
            cout << "Enter the amount greater than 0"<<endl;
        }
        else{
            cout << "Enter the valid withdraw amount"<<endl;
        }
    }
    //getter
    string get_name(){
        return bankholder;
    }
    long long BANK_ACCOUNT(){
        return bankaccnum;
    }
    long long getcurrentbalance(){
        return current_balance;
    }
    void get_info() const {
        cout << "Account holder's name: "<<bankholder<<endl;
        cout << bankholder <<"'s account number: "<< bankaccnum<<endl;
        cout << bankholder <<"'s current balance: $"<< current_balance<<endl;
    }
};
int main ()
{
    srand(time(0));
    int choice;
    string name;
    int people_no ;
    cout << "Enter the number of people: ";
    cin >> people_no;
    cin.ignore();
    BankAccountSystem* account = new BankAccountSystem [people_no];
    for (int i = 0 ; i < people_no ; i++)
    {
        cout << "Enter the person name: ";
        getline(cin , name);
        account[i].set_name(name);
        account[i].set_currentbalance(1+rand()%30000);
        account[i].set_account_No(1+rand()%50000);
        account[i].get_info();
    }
    cout << "Enter 1 to display bank account information"<<endl;
    cout << "Enter 2 to deposit amount"<<endl;
    cout << "Enter 3 to withdraw amount"<<endl;
    cout << "enter 4 to exit"<<endl;
    cin >> choice;
    cin.ignore();
    string search_name; 
    long long Amount;
    char button;
    while (choice !=4)
    {
        cout << "Enter the account bank holder name: ";
        getline(cin , search_name);
        bool found = false;
        for (int i = 0 ; i < people_no ; i++)
        {
            if (account[i].get_name() == search_name){
                cout << "Account holder matched at "<<i+1<<endl;
                found = true;
                if (choice == 1){
                    account[i].get_info();
                }
                else if (choice == 2){
                    cout << "Current balance is: $"<<account[i].getcurrentbalance()<<endl;
                    cout << "Enter the amount to deposit: ";
                    cin >> Amount;
                    account[i].setdeposit_Amount(Amount);
                    cout << "$"<<Amount<<" has been successfully deposited"<<endl; 
                    cout << "Your current balance: $"<<account[i].getcurrentbalance()<<endl;
                }
                else if (choice == 3){
                    cout << "Current balance is: $"<<account[i].getcurrentbalance()<<endl;
                    cout << "Enter the amount to withdraw: $";
                    cin >> Amount;
                    account[i].setwithdraw_Amount(Amount);
                    cout << "Current balance is: $"<<account[i].getcurrentbalance()<<endl;
                }
                break;
            }
        }
        if(!found){
            cout << "list name is not registered in the account"<<endl;
        }
        cout << "Enter the choice again: ";
        cin >> choice;
        cin.ignore();
    }
    delete [] account;
}


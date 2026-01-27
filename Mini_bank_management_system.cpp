#include <iostream>
#include <string>
using namespace std;
class BankAccountManagementSystem {
private:
    string Account_holder;
    long long account_number;
    double current_balance;
public:
    //Setter
    void setAccountholder(string Account_Holder) {
        if (Account_Holder.length() > 0) {
            Account_holder = Account_Holder;
        }
        else {
            cout << "Enter the valid name of account holder: " << endl;
        }
    }
    void setaccountnumber(long long accountnumber) {
        if (accountnumber < 0) {
            cout << "Enter the valid account number: " << endl;
        }
        else {
            account_number = accountnumber;
        }
    }
    void setcurrentbalance(long long  balance) {
        if (balance < 0) {
            cout << "You have zero balance in your account" << endl;
        }
        else {
            current_balance = balance;
        }
    }
    void setdepositamount(long long  depositamount) {
        if (depositamount > 0) {
            current_balance += depositamount;
        }
        else {
            cout << "Enter the deposit amount" << endl;
        }
    }
    void setwithdrawamount(long long withdramount) {
        if (withdramount <= 0) {
            cout << "Enter the withdraw amount greater than 0";
        }
        else if (withdramount > current_balance) {
            cout << "Insufficient balance" << endl;
        }
        else if (withdramount > 0 && withdramount <= current_balance) {
            cout << "your current balance: $" << current_balance << endl;
            current_balance -= withdramount;
        }
    }
    //Getter
    string getaccountholdername() {
        return Account_holder;
    }
    long long  getaccountnumber() {
        return account_number;
    }
    long long getcurrentbalance() {
        return current_balance;
    }

};
int main() {
    char button;
    cout << "Enter the dot (.) to continue or to exit press comma(,)" << endl;
    cin >> button;
    
        BankAccountManagementSystem person1;
        person1.setAccountholder("Muhammad Hamza Khan");
        person1.setaccountnumber(3310251666049);
        person1.setcurrentbalance(50000.2);
        cout << "Account holder: " << person1.getaccountholdername() << endl;
        cout << person1.getaccountholdername() << "'s account number: " << person1.getaccountnumber() << endl;
        cout << person1.getaccountholdername() << "'s current balance: $" << person1.getcurrentbalance() << endl;
        while (button == '.') {
        long long  deposit_amount;
        cout << "Enter the deposit amount: ";
        cin >> deposit_amount;
        person1.setdepositamount(deposit_amount);
        cout << "Your current balance after depositing amount for  $" << deposit_amount << " :$" << person1.getcurrentbalance() << endl;
        long long withdraw_Amount;
        cout << "Enter the withdraw amount: ";
        cin >> withdraw_Amount;
        person1.setwithdrawamount(withdraw_Amount);
        cout << "Your current balance after withdrawal amount for  $" << withdraw_Amount << " : $" << person1.getcurrentbalance() << endl;
        cout << person1.getaccountholdername() << "'s current balance: $" << person1.getcurrentbalance() << endl;
        cout << "Enter the (.) to continue or else press any button to exit: " << endl;
        cin >> button;


    }
}
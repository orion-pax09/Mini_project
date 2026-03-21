#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <ctime>
using namespace std;
class Account{
    private:
    string Website;
    string Password;
    string username;
    public:
    void setwebsite_name(){
        do
        {
            cout << "Enter the website name: ";
            getline(cin,Website);
            if (Website.empty()){
                cout << "Enter the website name again"<<endl;
            }
        } while (Website.empty());
        
    }
    // encryption
    void set_encryption(){
        string result= "";
        for (int i = 0 ; i < Password.length(); i++){
            if (isupper(Password[i])){
                result += char(int(Password[i]- 65 + 3) % 26 + 'A');
            }
            else if (islower(Password[i])){
                result += char (int (Password[i] - 97 + 3) % 26 + 'a');
            }
            else{
                result +=Password[i];
            }
        }
        Password = result;
    }
void set_Username(){
    do
    {
        cout << "Enter the username: ";
        getline(cin,username);
        if (username.empty()){
            cout <<"Enter the website name again"<<endl;
        }
    } while (username.empty());
}
void pass(int*length,string &pass){
    int  passoption;
    string Pass_custom;     
    while (true)
    {
        cout << "Enter the following choice to set password: "<<endl;
        cout << "1. Enter Auto password: "<<endl;
        cout << "2. Enter the custom password: "<<endl;
        cin >> passoption;
        cin.ignore();
        if (passoption==1){
            cout << "Enter the length of password: ";
            cin >> *length;
            string generated_password=  "";
            for (int i = 0 ; i < *length ; i++){
                generated_password+=pass[rand()%pass.length()];
            }
            Password = generated_password;
            cout << "Password generated: "<<Password<<endl;
            int count=0;
            for (int i = 0 ; i < generated_password.length();i++){
                if ((generated_password)[i]>='A' && (generated_password)[i]<='Z'){
                    count++;
                }
            }
            if (count <=2 || generated_password.length() <=4 ){
                cout << "Password strength: Weak"<<endl;
                break;
            }
            else if (count > 2 || generated_password.length() > 4){
                cout << "Password strength: Strong"<<endl;
                break;
            }
        }
        else if (passoption==2 ){
            cout << "Enter the password: ";
            getline(cin , Pass_custom);
            Password = Pass_custom;
            break;
            }
            else if (passoption < 0 || passoption >2 ){
                cout << "Enter the valid password option."<<endl;
                cout << "Enter 1 to enter auto password"<<endl;
                cout << "Enter 2 to enter custom password"<<endl;
            }
            else if (passoption >= (char)'A'&& passoption <= (char)'Z' || passoption >= (char)'a' && passoption <= (char)'z'){
                cout << "Enter the valid password option: "<<endl;
            }
        }
    }
    string get_websitename(){
        return Website;
    }
    string getusername(){
        return username;
    }
    string get_password(){
        return Password;
    }
    string get_encryption_password(){
        return Password;
    }
};
int main(){
    srand(time(0));
    int* length = new int;
    int*record = new int;
    string name;
    cout << "Enter the number of record you want: ";
    cin >> *record;
    cin.ignore();
    while (true){
    bool Invalid = true;
    if (*record <=0){
        cout << "Enter the valid record: ";
        cin >> *record;
        cin.ignore();
    }
    else{
        break;
    }
}
    string symbol = "ABCDEFGHI!JK@LM#NO$PQ%RS^TU&VW*XY(Za)bc+d9-e8=f7g6h5i4j321klmnopqrstuvwxyz";
    string website_name;
    Account* account = new Account [*record];
    for (int i = 0 ; i < *record ; i++){
        account[i].setwebsite_name();
        account[i].set_Username();
        account[i].pass(length, symbol);
    }
    for (int i = 0 ; i < *record ; i++){
        cout << "-------------Password stored in account No."<<i+1<<"-------------"<<endl;
        cout << "Website: "<<account[i].get_websitename()<<endl;
        cout << "Username: "<<account[i].getusername()<<endl;
        cout << "Password: "<<account[i].get_password()<<endl;
    }
    cout << "Press Enter key to encrypt"<<endl;
    char input = cin.get();
    if (input =='\n'){
        while (true){
            int account_no;
            cout << "Enter the account No. you want to encrypt: "<<endl;
            cin >> account_no;
            cin.ignore();
            if (account_no < 1 || account_no > *record){
                cout << "Invalid account no.Please see menu display";
                continue;
            }
            account[account_no-1].set_encryption();
            cout << "---------- Password encrypted ----------"<<endl;
            cout << account[account_no-1].get_encryption_password()<<endl;
            cout << "The original password was "<< account[account_no-1].get_password()<<endl;
            string button;
            cout <<"Enter any other button to skip encyrption: "<<endl;
            getline(cin , button);
            if (button != ""){
                break;
            }
        }
    }
    delete length;
    length = nullptr;
    delete record;
    record = nullptr;
    delete [] account;
    account = nullptr;
}

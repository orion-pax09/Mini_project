#include <iostream>
#include <vector>
using namespace std;
class Employee{
    private:
    int idname ; 
    double salary;
    public:
    Employee(){
        idname = 0;
        salary = 0.0;
    }
    Employee(int id , double Salary){
        idname = id ;
        salary = Salary;
    }
    Employee operator+(const Employee&obj);
    Employee operator-(const Employee&obj);
    bool operator>(const Employee&obj) const;
    double getsalary() const {
        return salary;
    }
    double getidname() const{
        return idname;
    }
    void display() const{
        cout << "ID: "<< idname <<" | $"<<salary<<endl;
    }

};
Employee Employee::operator+(const Employee& obj) {
    if (idname !=obj.idname){
        return Employee(this->idname , salary + obj.getsalary());
    }
    else{
        cout << "Same id,can't be added";
        return *this;
    }
}
Employee Employee::operator-(const Employee&obj){
    if (idname!=obj.idname){
        return Employee(this->idname , salary - obj.getsalary());
    }
    else{
        cout << "Same id..can't be subtracted"<<endl;
        return *this;
    }
}
bool Employee::operator>(const Employee&obj) const {
    return this->salary > obj.salary;
}
int main(){
    Employee clerk(111,999); Employee driver (222 , 923); Employee secretary(33,400) ; Employee manager(452 , 600);
    vector <Employee>array= {clerk , driver , manager , secretary};
    for (int i = 0 ; i < 4 ; i++){
        array[i].display();
    }
    Employee total= clerk + driver + secretary+ manager;
    cout << "==========Total salaries combination=========="<<endl;
    cout << "Total salary after combination: $"<<total.getsalary()<<endl;
    cout << "========== Salaries subtraction result =========="<<endl;
    Employee sub = clerk - driver - secretary - manager;
    if (sub.getsalary() <= 0){
        cout << "Total salary after subtraction: $0"<<endl;
    }
    else{
        cout << "Total salary after subtraction: $"<<sub.getsalary()<<endl;
    }
    Employee highest = array[0];
    for (int i = 0 ; i < 4 ; i++){
        if (array[i] > highest){
            highest = array[i];
        }
    }
    cout << "========== Highest salary =========="<<endl;
    highest.display();
}
#include <iostream>  
using namespace std;  

class Employee {  
protected:  
    string name;  
    float salary;  

public:  
     
    Employee(string n, float s) {  
        name = n;  
        salary = s;  
    }  
    
      
    void display() {  
        cout << "Name: " << name << endl;  
        cout << "Salary: " << salary << endl;  
    }  
};  

class Manager : public Employee {  
private:  
    float bonus;  

public:  
      
    Manager(string n, float s, float b) : Employee(n, s), bonus(b) {}  

      
    void display() {  
        Employee::display();  
        cout << "Bonus: " << bonus << endl;  
    }  
};  

int main() {  
    string name;  
    float salary, bonus;  

      
    cout << "Enter Employee Name: ";  
    cin >> name;  
    cout << "Enter Employee Salary: ";  
    cin >> salary;  
    cout << "Enter Employee Bonus: ";  
    cin >> bonus;  

      
    Manager m1(name, salary, bonus);  
    m1.display();  

    return 0;  
}  

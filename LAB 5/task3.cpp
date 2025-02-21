#include <iostream>  
#include <string>  

using namespace std;  

class Project; 

class Employee {  
private:  
    string name;  
    string designation;  

public:  
    Employee(string n, string d) : name(n), designation(d) {}  

    string Name() const {  
        return name;  
    }  

    string getDesignation() const {  
        return designation;  
    }  

    void display() const {  
        cout << "Employee Name: " << name << ", Designation: " << designation << endl;  
    }  
};  

class Project {  
private:  
    string title;  
    string deadline;  
    Employee* assignedEmployees[10]; 
    int employeeCount;  

public:  
    Project(string t, string d) : title(t), deadline(d), employeeCount(0) {}  

    void addEmployee(Employee* emp) {  
        if (employeeCount < 10) {  
            assignedEmployees[employeeCount++] = emp;  
        } else {  
            cout << "Cannot add more employees " << endl;  
        }  
    }  

    void displayDetails() const {  
        cout << "Project Title: " << title << ", Deadline: " << deadline << endl;  
        cout << "Assigned Employees:" << endl;  
        for (int i = 0; i < employeeCount; i++) {  
            assignedEmployees[i]->display();  
        }  
    }  
};  

int main() {  
    Employee emp1("Ali", "Devpr");  
    Employee emp2("Bilal", "Desig");  
    
    Project proj1(" A", "2025-12-31");  
    Project proj2("B", "2026-01-15");  

    proj1.addEmployee(&emp1);  
    proj1.addEmployee(&emp2);  
    
    proj2.addEmployee(&emp1);  

    cout << "Details of Project A:" << endl;  
    proj1.displayDetails();  
    
    cout << "\nDetails of Project B:" << endl;  
    proj2.displayDetails();  

    return 0;  
}

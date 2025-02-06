#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    double hoursWorked;
    double hourlyRate;
};

// calculate the total salary 
double calculateSalary(const Employee& emp) {
    return emp.hoursWorked * emp.hourlyRate;
}

int main() {
    int numEmployees;

    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    // allocate memory 
    Employee* employees = new Employee[numEmployees];

   
    for (int i = 0; i < numEmployees; ++i) {
        cout << "Enter details for employee " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore(); 
        getline(cin, employees[i].name);
        cout << "Hours Worked: ";
        cin >> employees[i].hoursWorked;
        cout << "Hourly Rate: ";
        cin >> employees[i].hourlyRate;
    }

    // Calculate and display the total salary 
    cout << "\nEmployee Salaries:\n";
    for (int i = 0; i < numEmployees; ++i) {
        double totalSalary = calculateSalary(employees[i]);
        cout << "Employee: " << employees[i].name << ", Total Salary: $" << totalSalary << "\n";
    }

    // Deallocate memory
    delete[] employees;

    return 0;
}
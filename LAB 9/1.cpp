#include <iostream>  
#include <string>  
using namespace std;  

class Patient {  
protected:  
    string name;  
    string id;  

public:  
    Patient(string n, string i) : name(n), id(i) {}  
    string getName() 
    { 
        return name; 
    }  
    string getId() 
    { 
    return id; 
    }  
    virtual void displayTreatment() = 0;  
    virtual double calculateCost() = 0;  
};  

class InPatient : public Patient {  
public:  
    InPatient(string n, string i) : Patient(n, i) {}  

    void displayTreatment() override {  
        cout << "InPatient Treatment: Room number 1, Daily therapy sessions." << endl;  
    }  

    double calculateCost() override {  
        return 1000.0 + 200.0;   
    }  
};  

class OutPatient : public Patient {  
public:  
    OutPatient(string n, string i) : Patient(n, i) {}  

    void displayTreatment() override {  
        cout << "OutPatient Treatment: Consultations and lab tests." << endl;  
    }  

    double calculateCost() override {  
        return 200.0 + 50.0;  
    }  
};  

int main() {  
    InPatient inpatient("Javed", "IP1");  
    OutPatient outpatient("Asif", "OP3");  

    cout << "Patient: " << inpatient.getName() << " (ID: " << inpatient.getId() << ")" << endl;  
    inpatient.displayTreatment();  
    cout << "Total Cost: $" << inpatient.calculateCost() << endl << endl;  

    cout << "Patient: " << outpatient.getName() << " (ID: " << outpatient.getId() << ")" << endl;  
    outpatient.displayTreatment();  
    cout << "Total Cost: $" << outpatient.calculateCost() << endl;  

    return 0;  
}  

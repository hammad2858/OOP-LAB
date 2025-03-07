#include <iostream>  
using namespace std;  

 
class Account {  
protected:  
    int accountNumber;  
    float balance;  

public:  
     
    Account(int accNum, float bal) : accountNumber(accNum), balance(bal) {}  

     
    void display() {  
        cout << "Account Number: " << accountNumber << endl;  
        cout << "Balance: " << balance << endl;  
    }  
};  

 
class SavingsAccount : public Account {  
protected:  
    float interestRate;  

public:  
      
    SavingsAccount(int accNum, float bal, float intRate)   
        : Account(accNum, bal), interestRate(intRate) {}  

     
    void display() {  
        Account::display();  
        cout << "Interest Rate: " << interestRate << endl;  
    }  
};  

  
class CheckingAccount : public Account {  
protected:  
    float overdraftLimit;  

public:  
    
    CheckingAccount(int accNum, float bal, float overdraft)   
        : Account(accNum, bal), overdraftLimit(overdraft) {}  

    
    void displayDetails()  {  
        Account::display();   
        cout << "Overdraft Limit: " << overdraftLimit << endl;  
    }  
};  

int main() {  
    int accountNumber;  
    float balance, interestRate, overdraftLimit;  

      
    cout << "Enter Savings Account Number: ";  
    cin >> accountNumber;  
    cout << "Enter Savings Account Balance: ";  
    cin >> balance;  
    cout << "Enter Savings Account Interest Rate: ";  
    cin >> interestRate;  

    SavingsAccount savingsAcc(accountNumber, balance, interestRate);  
     
    savingsAcc.display();  

     
    cout << "\nEnter Checking Account Number: ";  
    cin >> accountNumber;  
    cout << "Enter Checking Account Balance: ";  
    cin >> balance;  
    cout << "Enter Checking Account Overdraft Limit: ";  
    cin >> overdraftLimit;  

    CheckingAccount checkingAcc(accountNumber, balance, overdraftLimit);  
    
    checkingAcc.display();  

    return 0;  
}  

#include <iostream>  
#include <string>  

using namespace std;  

class AlarmSystem {  
private:  
    string securityLevel;  

public:  
    AlarmSystem(string level) : securityLevel(level) {}  

    void display() const {  
        cout << "Security Level: " << securityLevel << endl;  
    }  
};  

class SmartHome {  
private:  
    string address;  
    AlarmSystem alarmSystem;   

public:  
    SmartHome(string addr, string alarmLevel)  : address(addr), alarmSystem(alarmLevel) {}  

    void displayDetails() const {  
        cout << "Address: " << address << endl;  
        alarmSystem.display();  
    }  
};  

int main() {  
    SmartHome myHome("123 Street", "High");  

    cout << " Details:" << endl;  
    myHome.displayDetails();  

    return 0;  
}
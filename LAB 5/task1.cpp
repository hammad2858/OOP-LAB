#include <iostream>  
#include <cstring>  

using namespace std;  

class Apartment {  
private:  
    int id;  
    char* address;  
    char* owner; 

public:  
     
    Apartment(int id, const char* addr, const char* own)   
        : id(id) {  
        address = new char[strlen(addr) + 1];  
        strcpy(address, addr);  

        owner = new char[strlen(own) + 1];  
        strcpy(owner, own);  
    }  

   
    Apartment(const Apartment& other)   
        : id(other.id) {  
        address = new char[strlen(other.address) + 1];  
        strcpy(address, other.address);  

        
        owner = other.owner;   
    }  

      
    ~Apartment() {  
        delete[] address;  
        
    }  

     
    void displayDetails() const {  
        cout << "Apartment ID: " << id << endl;  
        cout << "Address: " << address << endl;  
        cout << "Owner: " << owner << endl;  
    }  

   
    void changeOwner(const char* newOwner) {  
        delete[] owner; 
        owner = new char[strlen(newOwner) + 1];  
        strcpy(owner, newOwner);  
    }  
};  

int main() {  

    Apartment apt1(1, "shah latif town", "saim");  

    cout << "Original Aptt Details:" << endl;  
    apt1.displayDetails();  

     
    Apartment apt2(apt1);  
    cout << "Copied Apartment Details :" << endl;  
    apt2.displayDetails();  

  
    apt2.changeOwner("Asif");  
    cout << "After changing owner in Copied Apartment:" << endl;  
    apt2.displayDetails();  

    cout << "Original Apartment Details After Owner Change:" << endl;  
    apt1.displayDetails(); 

    return 0;  
}
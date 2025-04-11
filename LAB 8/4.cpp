#include <iostream>  
#include <string>  
using namespace std;  

class Car {  
private:  
    string model;  
    double price;  

public:  
    Car(const string& m, double p) : model(m), price(p) {}  

       friend class InventoryManager;  

     
    friend void comparePrice(const Car& c1, const Car& c2);  
};  

class InventoryManager {  
public:  
    static void updatePrice(Car& car, double newPrice) {  
        car.price = newPrice;  
    }  

    static void displayDetails(const Car& car) {  
        cout << "Model: " << car.model << ", Price: $" << car.price << endl;  
    }  
};  

void comparePrice(const Car& c1, const Car& c2) {  
    if (c1.price > c2.price) {  
        cout << c1.model << " is more expensive than " << c2.model << endl;  
    } else if (c1.price < c2.price) {  
        cout << c1.model << " is cheaper than " << c2.model << endl;  
    } else {  
        cout << "Both cars have the same price" << endl;  
    }  
}  

int main() {  
    Car car1("Mercedes G65-AMG", 25000.0);  
    Car car2("Bentlay Continental-GT", 27000.0);  

    InventoryManager::displayDetails(car1);  
    InventoryManager::displayDetails(car2);  

    comparePrice(car1, car2);  

    InventoryManager::updatePrice(car1, 26000.0);  
    comparePrice(car1, car2);  

    return 0;  
}  

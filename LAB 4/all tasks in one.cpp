#include <iostream>  
#include <string>  
using namespace std;  

class Car {  
private:  
    string brand;  
    string model;  
    double rentalPrice;  
    bool avail;  
    double totalRevenue;  
    string registrationNumber;  

public:  
    // Task 1: Default Constructor  
    Car() : brand("Unknown"), model("Generic"), rentalPrice(0.0), avail(true), totalRevenue(0.0), registrationNumber("N/A") {}  

    // Task 2: Parameterized Constructor  
    Car(string brand, string model, double rentalPrice, bool avail, string regNumber)  
        : brand(brand), model(model), rentalPrice(rentalPrice), avail(avail), totalRevenue(0.0), registrationNumber(regNumber) {}  

    // Task 3: Copy Constructor  
    Car(const Car &other)  
        : brand(other.brand), model(other.model), rentalPrice(other.rentalPrice), avail(other.avail), totalRevenue(other.totalRevenue), registrationNumber(other.registrationNumber) {}  

    // Task 3: Destructor  
    ~Car() {  
        cout << "Car with registration number " << registrationNumber << " is being removed from memory." << endl;  
    }  

    // Task 1: Method to update car details  
    void updateDetails(string newBrand, string newModel, double newPrice) {  
        brand = newBrand;  
        model = newModel;  
        rentalPrice = newPrice;  
    }  

    // Task 1: check availability  
    bool checkAvailability() const {  
        return avail;  
    }  

    // Task 1:rental request  
    void rentCar(int days) {  
        if (!avail) {  
            cout << "Car is already rented." << endl;  
            return;  
        }  
        double totalCost = rentalPrice * days;  
        if (days > 10) {  
            totalCost *= 0.9; // 10% discount  
        } else if (days > 5) {  
            totalCost *= 0.95; // 5% discount  
        }  
        totalRevenue += totalCost;  
        avail = false;  
        cout << "Car rented for " << days << " days. Total cost: $" << totalCost << endl;  
    }  

    // Task 05:  display all car details  
    void displayDetails() const {  
        cout << "Registration Number: " << registrationNumber << endl;  
        cout << "Brand: " << brand << endl;  
        cout << "Model: " << model << endl;  
        cout << "Rental Price: $" << rentalPrice << endl;  
        cout << "Availability: " << (avail ? "Available" : "Rented") << endl;  
        cout << "Total Revenue: $" << totalRevenue << endl;  
    }  

    // Task 01:  return the car  
    void returnCar() {  
        avail = true;  
        cout << "Car returned. It is now available for rent." << endl;  
    }  

    // Task 04:  update and display revenue  
    void updateRevenue(int days) {  
        if (!avail) {  
            cout << "Car is not available for rent." << endl;  
            return;  
        }  
        double totalCost = this->rentalPrice * days;  
        if (days > 10) {  
            totalCost *= 0.9; // 10% discount  
        } else if (days > 5) {  
            totalCost *= 0.95; // 5% discount 
        }  
        this->totalRevenue += totalCost;  
        this->avail = false;  
        cout << "Car rented for " << days << " days. Total cost: $" << totalCost << endl;  
    }  
};  

int main() {  
    
    Car car1("Toyota", "Corolla", 50.0, true, "bbc928");  
    car1.displayDetails();  

     
    car1.rentCar(7);  
    car1.displayDetails();  

     
    car1.returnCar();  
    car1.displayDetails();  

      
    Car car2 = car1;  
    car2.displayDetails();  

     
    car1.updateDetails("Honda", "Civic", 60.0);  
    car1.displayDetails();  

   
    car2.displayDetails();  

   // update rental 
    car1.updateRevenue(12);  
    car1.displayDetails();  

    return 0;  
}

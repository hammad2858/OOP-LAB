#include <iostream>
using namespace std;
class Vehicle{
    protected:
    string brand;
    int speed;
    
    public:
    Vehicle(string b,int s) : brand(b),speed(s){}
    
    void display(){
        cout<<"Brand : "<<brand<<endl;
        cout<<"Speed : "<<speed<<endl;
    }
};
class Car : public Vehicle{
    protected:
    int seats;
    public:
    Car (string b,int s,int seatcount) : Vehicle(b,s),seats(seatcount){}
    
    void display(){
    Vehicle :: display();
    cout<<"Seats : "<< seats <<endl;
    }
};
class ElectricCar:public Car{
    private:
    int batterylife;
    public:
    ElectricCar(string b,int s,int seatcount,int battery) : Car(b,s,seatcount),batterylife(battery){} 
    void display(){
        Car::display();
        cout << "Battery Life: " << batterylife << " hrs" << endl;
    } 
};

int main(){
    string brand;
    int seats,speed,batteryLife;
    cout << "Enter Brand of the Electric Car: ";  
    cin >> brand;  
    cout << "Enter Speed (in km/h): ";  
    cin >> speed;  
    cout << "Enter Seating Capacity: ";  
    cin >> seats;  
    cout << "Enter Battery Life ) : ";  
    cin >> batteryLife;  
    ElectricCar e1(brand, speed, seats, batteryLife);
    e1.display();
}






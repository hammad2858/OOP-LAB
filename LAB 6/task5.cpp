#include <iostream>  
using namespace std;  

class Device {  
protected:  
    int deviceID;  
    bool status;  

public:  
    Device(int id, bool stat) : deviceID(id), status(stat) {}  

    void display() {  
        cout << "Device ID: " << deviceID << endl;  
        cout << "Status: " << (status ? "Active" : "Inactive") << endl;  
    }  
};  

class SmartPhone : public Device {  
protected:  
    float screenSize;  

public:  
    SmartPhone(int id, bool stat, float size)  
        : Device(id, stat), screenSize(size) {}  

    void display() {  
        Device::display();  
        cout << "Screen Size: " << screenSize << " inches" << endl;  
    }  
};  

class SmartWatch : public Device {  
protected:  
    bool heartRateMonitor;  

public:  
    SmartWatch(int id, bool stat, bool monitor)  
        : Device(id, stat), heartRateMonitor(monitor) {}  

    void display() {  
        Device::display();  
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;  
    }  
};  

class SmartWearable : public SmartPhone, public SmartWatch {  
private:  
    int stepCounter;  

public:  
    SmartWearable(int id, bool stat, float size, bool monitor, int steps)  
        : SmartPhone(id, stat, size), SmartWatch(id, stat, monitor), stepCounter(steps) {}  

    void displayDetails() {  
        SmartPhone::display();   
        SmartWatch::display();  
        cout << "Step Counter: " << stepCounter << endl;  
    }  
};  

int main() {  
    int deviceID, steps;  
    bool status, heartRateMonitor;  
    float screenSize;  

    cout << "Enter Device ID: ";  
    cin >> deviceID;  
    cout << "Enter Status (1 for Active, 0 for Inactive): ";  
    cin >> status;  
    cout << "Enter Screen Size (in inches): ";  
    cin >> screenSize;  
    cout << "Does it have a Heart Rate Monitor? (1 for Yes, 0 for No): ";  
    cin >> heartRateMonitor;  
    cout << "Enter Step Counter: ";  
    cin >> steps;  

    
    SmartWearable device(deviceID, status, screenSize, heartRateMonitor, steps);  

      
     
    device.displayDetails();   

    return 0;  
}  

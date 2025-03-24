#include <iostream>
using namepsace std;

class Device{
    protected:
    int ID;
    string Name;
    bool status;
    string location;
    public:
    Device(int i, string n, string loc = " " ) :ID(i),Name(n),location(loc){}
    
    virtual void turnon(){
         status = true;
         cout<<Name<<"Is now ON"<<endl;
    }
    
    virtual void turnoff(){
         status = false;
         cout<<Name<<"Is now OFF"<<endl;
    }
    
    virtual void displayinfo(){
        cout<<"Device ID : "<< ID <<endl;
        cout<<"Device Name : "<< Name <<endl;
        cout<<"Status : "<< status <<endl;
        cout<<"Location : "<< Location <<endl;
    }
};

class Light : public Device{
    protected:
    int brightness;
    string colormode;
    public:
    Light (int i, string n, string loc,int b,string c) : Device(i,n,loc),brightness(b),colormode(c){}
    
      void displayInfo() override {
        Device::displayInfo();
        cout << "Brightness: " << brightness << endl;
        cout<< "Color Mode : "<<colormode<<endl;
    }
    
};

class Thermostat : public Device{
    protected:
    int temp;
    public:
    Thermostat(int i, string n, string loc,int t):Device(i,n,loc),temp(t){}
    
    virtual void displayInfo() override{
        Device::displayInfo();
        cout << "Current Temperature: " << temp << "°C" << endl;
    }
    
};


#include<iostream>
using namespace std;

class WeatherSensor{
    public:
    virtual void readData()=0;
    virtual void displayReport()=0;
};
class Thermometer:public WeatherSensor{
    protected:
    float temp;
    public:
    Thermometer(float t):temp(t){}
   void readData()override{
    temp = 25;
   }
 void displayReport()override{
    cout<<"Temperature is : "<<temp<<endl;
 }
};
class Barometer : public WeatherSensor{
    protected:
    float pressure;
    public:
    Barometer(float p):pressure(p){}
    void readData()override{
    pressure = 5;
   }
 void displayReport()override{
    cout<<"Pressure is : "<<pressure<<endl;
 }
};
int main(){
    Thermometer t1(25);
    Barometer b1(5);
    t1.readData();
    t1.displayReport();
    b1.readData();
    b1.displayReport();
}
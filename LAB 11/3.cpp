#include<iostream>
#include<exception>

using namespace std;

class InvalidTemperatureException : public exception{};
template <typename T>
T ConvertToFahrenheit(T celsius){
    if(celsius<static_cast<T>(-273.15))
    throw InvalidTemperatureException();
    return (celsius*static_cast<T>(9/5))+static_cast<T>(32);

}


int main (){
    try{
        cout<<"Attempting To Convert --300"<<endl;
        double fahrenheit = ConvertToFahrenheit(-300.0);
        cout<<"Fahrenheit "<< fahrenheit <<endl;

    }

    catch (InvalidTemperatureException e){
        cout<< "caught invalidTempException"<<endl;
        cout<<"What() : "<<e.what()<<endl;
    }
    return 0;
}
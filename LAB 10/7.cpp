#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream outFile("sensor_log.txt");
    if(!outFile){
        cerr << "error opening file to write"<<endl;

    }
    outFile << "Temp : 23.5 C"<<endl;
    streampos pos1 = outFile.tellp();
    cout<<"Write postion after first line"<<pos1<<endl;

    outFile << "Humidity : 61 % "<<endl;
    streampos pos2  = outFile.tellp();
    cout<<"Write position after second line "<<pos2<<endl;

    outFile << "Pressure : 3 atm"<<endl;
    streampos pos3 = outFile.tellp();
    cout<<"Write position after third line"<<pos3<<endl;

    outFile.close();
    
}
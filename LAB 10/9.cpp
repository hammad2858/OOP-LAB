#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream outFile("large_log.txt");
    outFile << "Sensor A : working \n Sensor B : Malfunctioned \n Sensor C : Working"<<endl;
    outFile.close();

    ifstream inFile("large_log.txt");
    if(!inFile){
        cerr<<"error opening file"<<endl;
    }
    char buffer[11];
    buffer[10] = '\0';
    inFile.read(buffer,10);
    buffer[inFile.gcount()] = '\0';
    cout<<"read block"<< buffer <<endl;
    streampos pos1 = inFile.tellg();
    cout<< "position after first read :"<<pos1 <<endl;

    char buffer[11];
    buffer[10] = '\0';
    inFile.read(buffer,10);
    buffer[inFile.gcount()] = '\0';
    cout<<"read block"<< buffer <<endl;
    streampos pos2 = inFile.tellg();
    cout<< "position after first read :"<<pos2 <<endl;

    inFile.close();
    
}
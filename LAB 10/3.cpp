#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main(){
    ifstream file("vehicles.txt");
    string line;
    while(getline(file,line)){
        if(line.empty()||line[0]=='/')continue;
        istringstream iss(line);
        string type,id,name,yearStr,extraData,certification;

        getline(iss,type,',');
        getline(iss,id,',');
        getline(iss,name,',');
        getline(iss,yearStr,',');
        getline(iss,extraData,',');
        getline(iss,certification,',');

        int year = stoi(yearStr);

        cout << "Type: " << type << "\n"
                  << "ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Year (string): " << yearStr << "\n"
                  << "Year (int): " << year << "\n"
                  << "ExtraData: " << extraData << "\n"
                  << "Certification: " << certification<<endl;
                  }

                  file.close();
                  
}

#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream file("vehicles.txt");
    string line;
    
    while(getline(file, line)){
        if(line.empty() || line[0] == '/') continue;

        istringstream iss(line);
        string type, id, name, yearStr, extraData, certification;

        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, yearStr, ',');
        getline(iss, extraData, ',');
        getline(iss, certification, ',');

        int year = stoi(yearStr);
        cout << "ID: " << id << endl;

        if (type == "AutonomousCar") {
            size_t pos = extraData.find(':');
            if (pos != string::npos) {
                string versionStr = extraData.substr(pos + 1);
                float softwareVersion = stof(versionStr);
                cout << "Software Version: " << softwareVersion << "\n";
            }
        }
        else if (type == "ElectricVehicle") {
            size_t pos = extraData.find(':');
            if (pos != string::npos) {
                string batteryStr = extraData.substr(pos + 1);
                int batteryCapacity = stoi(batteryStr);
                cout << "Battery Capacity: " << batteryCapacity << " kWh\n";
            }
        }

       
    }

    file.close();
    return 0;
}

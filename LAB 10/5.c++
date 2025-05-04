#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("vehicles.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '/') continue;

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
        else if (type == "HybridTruck") {
            size_t pipePos = extraData.find('|');
            size_t cargoPos = extraData.find("Cargo:");
            size_t batteryPos = extraData.find("Battery:");

            if (cargoPos != string::npos && pipePos != string::npos) {
                string cargoStr = extraData.substr(cargoPos + 6, pipePos - (cargoPos + 6)); // 6 = length of "Cargo:"
                int cargo = stoi(cargoStr);

                if (batteryPos != string::npos) {
                    string batteryStr = extraData.substr(batteryPos + 8); // 8 = length of "Battery:"
                    int battery = stoi(batteryStr);

                    cout << "Cargo Capacity: " << cargo << " kg\n";
                    cout << "Battery Capacity: " << battery << " kWh\n";
                }
            }
        }
        else {
            cout << "Unknown vehicle type: " << type << endl;
        }

        
    }

    file.close();
    return 0;
}

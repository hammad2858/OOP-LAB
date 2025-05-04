#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Open the existing file
    ifstream inFile("data_records.txt");
    if (!inFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    
    inFile.seekg(18, ios::beg); 

    
    string record;
    getline(inFile, record);
    cout << "Third record: " << record << endl;

    inFile.close();
    return 0;
}

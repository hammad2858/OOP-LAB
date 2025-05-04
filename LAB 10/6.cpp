#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main(){
    InventoryItem itemOut;
    itemOut.itemID = 1;
    strncpy(itemOut.itemName,"Screwdriver",sizeof(itemOut.itemName)-1);
    itemOut.itemName[sizeof(itemOut.itemName)-1]='\0';

    ofstream outFile("inventory.dat",ios::binary);
    if(outFile){
        outFile.write(reinterpret_cast<char*>(&itemOut),sizeof(itemOut));
        outFile.close();
    }
    else{
        cerr<<"Error opening file to write"<<endl;
    }

    InventoryItem itemIn;
    ifstream inFile("inventory.dat",ios::binary);
    if(inFile){
        inFile.read(reinterpret_cast<char*>(&itemIn),sizeof(itemIn));
        inFile.close();
    }
    else{
        cerr<<"Error opening file to read"<<endl;
    }
    cout<<"Loaded Item ID : "<<itemIn.itemID<<endl;
    return 0;
}
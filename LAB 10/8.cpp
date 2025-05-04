#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ofstream outFile("config.txt");
    outFile<<"AAAAA"<<"BBBBB"<<"CCCCC";
    outFile.close();

    fstream file("config.txt",ios::in| ios::out);
    if(!file){
        cerr<<"error opening the file "<<endl;

    }

    file.seekp(5);
    file << "YYYYY";
    file.close();

    ifstream inFile("config.txt");
    string content;
    getline(inFile,content);
    cout<<"updated file content"<<content <<endl;
    inFile.close();
     

}
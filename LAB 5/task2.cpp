#include <iostream>  
#include <cstring>  

using namespace std;  

class Student {  
private:  
    int id;  
    char* name;  
    int* scores; 
    int numScores;  

public:  
     
    Student(int id, const char* name, const int* scoresArray, int num)   
        : id(id), numScores(num) {  
        this->name = new char[strlen(name) + 1];  
        strcpy(this->name, name);  

        scores = new int[numScores];  
        for (int i = 0; i < numScores; ++i) {  
            scores[i] = scoresArray[i];  
        }  
    }  

    
    Student(const Student& other) : id(other.id), numScores(other.numScores) {  
        name = new char[strlen(other.name) + 1];  
        strcpy(name, other.name);  

        scores = new int[numScores];  
        for (int i = 0; i < numScores; ++i) {  
            scores[i] = other.scores[i]; 
    }  

    
    ~Student(){  
        delete[] name;  
        delete[] scores; 
    }  

   
    void displayDetails() const {  
        cout << "Student ID: " << id << endl;  
        cout << "Name: " << name << endl;  
        cout << "Scores: ";  
        for (int i = 0; i < numScores; i++) {  
            cout << scores[i] << (i < numScores - 1 ? ", " : "");  
        }  
        cout << endl;  
    }  
}
};  

int main() {  
    int scoresArray[] = {85, 90, 75};  
    
    
    Student student1(1, "sohail", scoresArray, 3);  

    cout << "Original Student Details:" << endl;  
    student1.displayDetails();  

  
    Student student2(student1);  

    cout << "Copied Student Details :" << endl;  
    student2.displayDetails();  

    int newScores[] = {80, 88, 92};  
    Student student3(2, "sohail", newScores, 3);  

    cout << "Original std aftr Indp Mod:" << endl;  
    student1.displayDetails();  

    cout << "New Student Details:" << endl;  
    student3.displayDetails();  

    return 0;  
}
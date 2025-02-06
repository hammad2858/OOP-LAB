#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    double marks[3]; 
};

// func for avg mrks
double calculateAverage(const Student& student) {
    double sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += student.marks[i];
    }
    return sum / 3;
}

int main() {
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    
    Student* students = new Student[numStudents];

    
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore(); 
        getline(cin, students[i].name);
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "Marks in 3 subjects:\n";
        for (int j = 0; j < 3; ++j) {
            cout << "Subject " << j + 1 << ": ";
            cin >> students[i].marks[j];
        }
    }


    cout << "\nStudent Averages:\n";
    for (int i = 0; i < numStudents; ++i) {
        double average = calculateAverage(students[i]);
        cout << "Student: " << students[i].name << ", Roll Number: " << students[i].rollNumber
             << ", Average Marks: " << average << "\n";
    }

    
    delete[] students;

    return 0;
}
// Hammad siddiqui 24K-0702

#include <iostream>  
#include <string.h>
using namespace std;  


// Func to  register participants  
void registerParticipants(char event1[5][30], char event2[5][30]) {  
    cout << "Register participants for Event 1:\n";  
    for (int i = 0; i < 5; ++i) {  
        cout << "Enter name for participant " << (i + 1) << ": ";  
        cin >> event1[i];  
    }  

    cout << "\nRegister participants for Event 2:\n";  
    for (int i = 0; i < 5; ++i) {  
        cout << "Enter name for participant " << (i + 1) << ": ";  
        cin >> event2[i];  
    }  
}  

// Func to  check attendance  
bool checkAttendance(char event1[5][30], char event2[5][30],  char* name) {  
    for (int i = 0; i < 5; ++i) {  
        if (strcmp(event1[i], name) == 0 || strcmp(event2[i], name) == 0) {  
            return true;  
        }  
    }  
    return false;  
}  

// Func to  calculate  donations  
int calculateTotalDonations() {  
    return 5 * 10* 2; // For both events  
}  

// Func to  display names in reverse  
void displayNamesInReverse(char event[5][30],  char* eventName) {  
    cout << "\nParticipants for " << eventName << " in reverse order:\n";  
    for (int i = 5 - 1; i >= 0; --i) {  
        cout << event[i] << endl;  
    }  
}  

// Func to  display bar chart  
void displayBarChart(int count1, int count2) {  
    cout << "\nEvent Popularity Bar Chart:\n";  
    cout << "Event 1 Participants: ";  
    for (int i = 0; i < count1; ++i) {  
        cout << "*";  
    }  
    cout << " (" << count1 << " participants)\n";  

    cout << "Event 2 Participants: ";  
    for (int i = 0; i < count2; ++i) {  
        cout << "*";  
    }  
    cout << " (" << count2 << " participants)\n";  
}  

int main() {  
    char event1[5][30];  
    char event2[5][30];  

    registerParticipants(event1, event2);  

    char nameToCheck[30];  
    cout << "\nEnter a participant's name to check attendance: ";  
    cin >> nameToCheck;  

    if (checkAttendance(event1, event2, nameToCheck)) {  
        cout << nameToCheck << " is registered for one of the events.\n";  
    } else {  
        cout << nameToCheck << " is not registered for any of the events.\n";  
    }  

    int totalDonations = calculateTotalDonations();  
    cout << "\nTotal donations collected: $" << totalDonations << endl;  

    displayNamesInReverse(event1, "Event 1");  
    displayNamesInReverse(event2, "Event 2");  

    displayBarChart(5, 5); 

    return 0;  
}

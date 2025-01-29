#include <iostream>
#include <string.h>
using namespace std;

const int cities = 4;
const int days = 7;

void inputAQI(int aqi[cities][days]);
void calculateAverageAQI(int aqi[cities][days]);
void identifycriticalpollutiondays(int aqi[cities][days]);
void visualizeData(int aqi[cities][days]);
void generateReport(int aqi[cities][days]);

void inputAQI(int aqi[cities][days]){
    cout<<"Enter the AQI Values for"<<cities<<"Cities Over"<<"Days:\n";
    for (int i=0;i<cities;i++){
        cout<<"City"<<(i+1)<<":\n";
        for (int j=0;j<days;j++){
            cout<<"Days"<<(j+1)<<":";
            cin >> aqi[i][j];
        }// j ends
    }// i ends
}

void calculateAverageAQI(int aqi[cities][days]){
    float avgAQI[cities] = {0};
    int worstindex = 0 ;
    for(int i=0;i<cities;i++){
        int sum = 0;
        for(int j=0;j<days;j++){
            sum += aqi[i][j];
        }// j ends
        avgAQI[i]=sum/days;
        cout<<"AVG AQI For City"<<(i+1)<<":"<<avgAQI[i]<<endl;
        if (avgAQI[i]>avgAQI[worstindex]){
            worstindex=i;
        }// if ends
    }//i ends
     cout << "City with the worst air quality (highest average AQI): City "   
         << (worstindex + 1) << " with average AQI of "   
         << avgAQI[worstindex] << endl;
}

 void  identifycriticalpollutiondays(int aqi[cities][days]) {  
    cout << "Critical Pollution Days (AQI > 150):\n";  
    for (int i = 0; i < cities; i++) {  
        cout << "City " << (i + 1) << ": ";  
        bool hasCriticalDays = false;  
        for (int j = 0; j < days; j++) {  
            if (aqi[i][j] > 150) {  
                cout << "Day " << (j + 1) << " ";  
                hasCriticalDays = true;  
            }  
        }  
        if (!hasCriticalDays) {  
            cout << "None";  
        }  
        cout << endl;  
    }  
}  

void generateReport(int aqi[cities][days]) {  
    cout << "\n*** AQI Report ***\n";  

    for (int i = 0; i < cities; i++) {  
        float weeklyAverage = 0;  
        int maxAQI = aqi[i][0];  
        int minAQI = aqi[i][0];  

        for (int j = 0; j < days; j++) {  
            weeklyAverage += aqi[i][j];  
            if (aqi[i][j] > maxAQI) {  
                maxAQI = aqi[i][j];  
            }  
            if (aqi[i][j] < minAQI) {  
                minAQI = aqi[i][j];  
            }  
        }  
        weeklyAverage /= days;  

        cout << "City " << (i + 1) << ":\n";  
        cout << "  Weekly Average AQI: " << weeklyAverage << endl;  
        cout << "  Highest AQI: " << maxAQI << endl;  
        cout << "  Lowest AQI: " << minAQI << endl;  
    }  

    cout << "\n*** Critical Pollution Days Summary ***\n";  
    for (int i = 0; i < cities; i++) {  
        cout << "City " << (i + 1) << " Critical Pollution Days: ";  
        bool hasCriticalDays = false;  
        for (int j = 0; j < days; j++) {  
            if (aqi[i][j] > 150) {  
                cout << "Day " << (j + 1) << " ";  
                hasCriticalDays = true;  
            }  
        }  
        if (!hasCriticalDays) {  
            cout << "None";  
        }  
        cout << endl;  
    }  
}  

void visualizeData(int aqi[cities][days]) {  
    cout << "AQI Visualization (Each '*' represents an AQI increment of 50):\n";  
    for (int i = 0; i < cities; i++) {  
        cout << "City " << (i + 1) << ": ";  
        for (int j = 0; j < days; j++) {  
            int stars = aqi[i][j] / 50;  
            for (int k = 0; k < stars; k++) {  
                cout << "*";  
            }  
            cout << " ";  
        }  
        cout << endl;  
    }  
}



int main() {  
    int aqi[cities][days];  
    
      
    inputAQI(aqi);  
    
      
    calculateAverageAQI(aqi);  
    
     
    identifycriticalpollutiondays(aqi);  
    
    
    visualizeData(aqi);  
    
     
    generateReport(aqi);  
    
    return 0;  
}
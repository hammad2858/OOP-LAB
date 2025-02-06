#include <iostream>  
#include <string>  

using namespace std;  

// Func to bubble sort  
void bubbleSort(string* arr, int n) {  
    for (int i = 0; i < n - 1; ++i) {  
        for (int j = 0; j < n - i - 1; ++j) {  
            if (arr[j] > arr[j + 1]) {  
                // Swap arr[j] and arr[j + 1]  
                string temp = arr[j];  
                arr[j] = arr[j + 1];  
                arr[j + 1] = temp;  
            }  
        }  
    }  
}  

int main() {  
    int n;  

   
    cout << "Enter the number of strings: ";  
    cin >> n;  

    // allocate memory 
    string* strings = new string[n];  

  
    cout << "Enter " << n << " strings:" << endl;  
    for (int i = 0; i < n; ++i) {  
        cin >> strings[i];  
    }  

    // alphabetically  
    bubbleSort(strings, n);  

    // displaying sorted strings  
    cout << "Sorted strings:" << endl;  
    for (int i = 0; i < n; ++i) {  
        cout << strings[i] << endl;  
    }  

     
    delete[] strings;  

    return 0;  
}
#include <iostream>
using namespace std;

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    
    int* arr = new int[size];

  
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // pointer arithmetic to traverse and display 
    int* ptr = arr;
    cout << "Array elements using pointer arithmetic:\n";
    for (int i = 0; i < size; ++i) {
        cout << *(ptr + i) << " ";
    }
    cout << "\n";

    // Find the sum of the array elements using pointers
    int sum = 0;
    ptr = arr; // Reset pointer to the beginning of the array
    for (int i = 0; i < size; ++i) {
        sum += *(ptr + i);
    }
    cout << "Sum of array elements: " << sum << "\n";

    // Deallocate memory
    delete[] arr;

    return 0;
}
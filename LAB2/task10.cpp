#include <iostream>  

using namespace std;  

int main() {  
    int layers, rows, cols;  

    cout << "Enter dimensions of the 3D array (layers rows cols): ";  
    cin >> layers >> rows >> cols;  

    int ***inventoryMatrix = new int**[layers];  
    for (int i = 0; i < layers; i++) {  
        inventoryMatrix[i] = new int*[rows];  
        for (int j = 0; j < rows; j++) {  
            inventoryMatrix[i][j] = new int[cols];  
        }  
    }  

    cout << "Populate the 3D array:\n";  
    for (int i = 0; i < layers; i++) {  
        for (int j = 0; j < rows; j++) {  
            for (int k = 0; k < cols; k++) {  
                cout << "Enter value for [" << i << "][" << j << "][" << k << "]: ";  
                cin >> inventoryMatrix[i][j][k];  
            }  
        }  
    }  

    cout << "The 3D array is:\n";  
    for (int i = 0; i < layers; i++) {  
        for (int j = 0; j < rows; j++) {  
            for (int k = 0; k < cols; k++) {  
                cout << "inventoryMatrix[" << i << "][" << j << "][" << k << "] = " << inventoryMatrix[i][j][k] << endl;  
            }  
        }  
    }  

    for (int i = 0; i < layers; i++) {  
        for (int j = 0; j < rows; j++) {  
            delete[] inventoryMatrix[i][j];  
        }  
        delete[] inventoryMatrix[i];  
    }  
    delete[] inventoryMatrix;  

    return 0;  
}
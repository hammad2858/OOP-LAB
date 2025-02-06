#include <iostream>  
#include <string>  

using namespace std;  

struct Product {  
    int productID;  
    string name;  
    int quantity;  
    float price;  
};  

int main() {  
    int numProducts;  

    cout << "Enter the number of products: ";  
    cin >> numProducts;  

    Product *inventory = new Product[numProducts];  

    for (int i = 0; i < numProducts; i++) {  
        cout << "Enter details for product " << (i + 1) << ":\n";  
        cout << "Product ID: ";  
        cin >> inventory[i].productID;  
        cout << "Name: ";  
        cin >> inventory[i].name;  
        cout << "Quantity: ";  
        cin >> inventory[i].quantity;  
        cout << "Price: ";  
        cin >> inventory[i].price;  
    }  

    float totalValue = 0;  

    for (int i = 0; i < numProducts; i++) {  
        totalValue += inventory[i].quantity * inventory[i].price;  
    }  

    cout << "Total value of the inventory: " << totalValue << endl;  

    delete[] inventory;  

    return 0;  
}
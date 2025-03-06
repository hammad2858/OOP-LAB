#include <iostream>  
#include <string>  

using namespace std;  

class Product {  
public:  
    int id;  
    string name;  
    int quantity;  

    Product(int id, string name, int quantity)   
        : id(id), name(name), quantity(quantity) {}  
};  

class Warehouse {  
private:  
    Product* products[10];  
    int productCount;  

public:  
    Warehouse() : productCount(0) {}  

    void addProduct(int id, string name, int quantity) {  
        if (productCount < 10) {  
            products[productCount++] = new Product(id, name, quantity);  
        } else {  
            cout << " Warehouse is full." << endl;  
        }  
    }  

    void sortProducts() {  
       
        for (int i = 0; i < productCount - 1; ++i) {  
            for (int j = 0; j < productCount - i - 1; ++j) {  
                if (products[j]->name > products[j + 1]->name) {  
                     
                    Product* temp = products[j];  
                    products[j] = products[j + 1];  
                    products[j + 1] = temp;  
                }  
            }  
        }  
    }  

    void searchById(int id) {  
        for (int i = 0; i < productCount; ++i) {  
            if (products[i]->id == id) {  
                cout << "Product Found: " << endl;  
                cout << "ID: " << products[i]->id << ", Name: " << products[i]->name  
                     << ", Quantity: " << products[i]->quantity << endl;  
                return;  
            }  
        }  
        cout << "Product with ID " << id << " not found." << endl;  
    }  

    ~Warehouse() {  
        for (int i = 0; i < productCount; ++i) {  
            delete products[i]; 
        }  
    }  
};  

int main() {  
    Warehouse warehouse;  

   
    warehouse.addProduct(1, "Chair", 20);  
    warehouse.addProduct(2, "Table", 15);  
    warehouse.addProduct(3, "Laptop", 8);  
    warehouse.addProduct(4, "Head Phones", 50);  
    warehouse.addProduct(5, "Micro-Phone", 30);  

    
    warehouse.sortProducts();  

     
    warehouse.searchById(3);  
    warehouse.searchById(5); 
    return 0;  
}  

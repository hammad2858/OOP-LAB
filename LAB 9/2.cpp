#include <iostream>  
#include <string>  
using namespace std;  

class MenuItem {  
protected:  
    string dishName;  
    double price;  

public:  
    MenuItem(string name, double cost) : dishName(name), price(cost) {}  
    string getDishName() { return dishName; }  
    double getPrice() { return price; }  
    virtual void showDetails() = 0;  
    virtual void prepare() = 0;  
};  

class Appetizer : public MenuItem {  
public:  
    Appetizer(string name, double cost) : MenuItem(name, cost) {}  

    void showDetails() override {  
        cout << "Appetizer: " << getDishName() << endl;  
        cout << "Price: $" << getPrice() << endl;  
        cout << "Details: Chilled to perfection." << endl;  
    }  

    void prepare() override {  
        cout << "Preparation: Chill in the refrigerator for 30 minutes before serving." << endl;  
    }  
};  

class MainCourse : public MenuItem {  
public:  
    MainCourse(string name, double cost) : MenuItem(name, cost) {}  

    void showDetails() override {  
        cout << "Main Course: " << getDishName() << endl;  
        cout << "Price: " << getPrice() << endl;  
        cout << "Details: Grilled to perfection." << endl;  
    }  

    void prepare() override {  
        cout << "Preparation: Grill for 15 minutes on each side, then let it rest." << endl;  
    }  
};  

int main() {  
    Appetizer appetizer("Alfredo Pasta ", 1200);  
    MainCourse mainCourse("Grilled Salmon", 2400);  

    cout << endl;  
    appetizer.showDetails();  
    appetizer.prepare();  
    cout << endl;  

    mainCourse.showDetails();  
    mainCourse.prepare();  

    return 0;  
}  

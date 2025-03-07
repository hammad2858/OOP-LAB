#include <iostream>  
using namespace std;  

class Person {  
protected:  
    string name;  
    int age;  

public:  
    Person(string n, int a) : name(n), age(a) {}  

    void display() {  
        cout << "Name: " << name << endl;  
        cout << "Age: " << age << endl;  
    }  
};  

class Teacher : public Person {  
protected:  
    string subject;  

public:  
    Teacher(string n, int a, string sub) : Person(n, a), subject(sub) {}  

    void display() {  
        Person::display();  
        cout << "Subject: " << subject << endl;  
    }  
};  

class Researcher : public Person {  
protected:  
    string researchArea;  

public:  
    Researcher(string n, int a, string area) : Person(n, a), researchArea(area) {}  

    void display() {  
        Person::display();  
        cout << "Research Area: " << researchArea << endl;  
    }  
};  

class Professor : public Teacher, public Researcher {  
private:  
    int publications;  

public:  
      
    Professor(string n, int a, string sub, string area, int pubs)  
        :  Teacher(n, a, sub), Researcher(n, a, area), publications(pubs) {}  

    void display() {  
        Teacher::display();  
        Researcher::display(); 
        cout << "Publications: " << publications << endl;  
    }  
};  

int main() {  
    string name, subject, researchArea;  
    int age, publications;  

    cout << "Enter Professor's Name: ";  
    cin >> name;  
    cout << "Enter Professor's Age: ";  
    cin >> age;  
    cout << "Enter Subject Taught: ";  
    cin >> subject;  
    cout << "Enter Research Area: ";  
    cin >> researchArea;  
    cout << "Enter Number of Publications: ";  
    cin >> publications;  

    
    Professor prof(name, age, subject, researchArea, publications);  

    
    
    prof.display(); 

    return 0;  
}  

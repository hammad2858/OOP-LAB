#include <iostream>
using namespace std;
class Person{
    protected:
    string name;
    int age;
    double contactNum;
    string Address;
    public:
    Person(string n,int a, double cn, string ad):name(n),age(a),contactNum(cn),Address(ad){}
    virtual void displayInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Contact Number: "<<contactNum<<endl;
        cout<<"Address: "<<Address<<endl;
    }
    void updateInfo(double cont,string addr){
      Address = addr;
      contactNum = cont;
      cout<<"Updated INFO ! "<<endl;
    }
};
class Patient : public Person{
    protected:
    int PatientID;
    string medicalHistory;
    string doctorAssigned;
    public:
    Patient(string n,int a ,double cn,string ad,int id,string mh,string da):Person(n,a,cn,ad),PatientID(id),medicalHistory(mh),doctorAssigned(da){}
    void displayInfo()override{
        Patient::displayInfo();
        cout<<"Patient ID : "<<PatientID<<endl;
        cout<<"Medical History : "<<medicalHistory<<endl;
        cout<<"Doctor Assigned :"<<doctorAssigned<<endl;
    }
};
class Doctor : public Person{
    protected:
    string specialization;
    double consultaionFee;
    string PatientList[10];
    int patientCount;
    public:
    Doctor(string n,int a ,double cn,string ad,string sp,double cf):Person(n,a,cn,ad),specialization(sp),consultaionFee(cf),patientCount(0){}
    void addPatient(string PatName){
        if (patientCount < 10){
         PatientList[patientCount] = PatName;
        }
    }
    void displayInfo() override{
        Person::displayInfo();
        cout<<"Specialization : "<<specialization<<endl;
        cout<<"Consultation Fee : "<<consultaionFee<<endl;
        for(int i = 0;i<10;i++){
            cout<<PatientList[i]<<" , ";
        }
        cout<<endl;
    }
};

class Nurse : public Person{
    protected:
    string assignedWard;
    string shiftTimings;
    public:
    Nurse(string n,int a ,double cn, string ad,string aw, string st):Person(n,a,cn,ad),assignedWard(aw),shiftTimings(st){}
    void displayInfo() override{
        Person::displayInfo();
        cout<<"Assigned Ward : "<<assignedWard<<endl;
        cout<<"Shift Timings : "<<shiftTimings<<endl;
    }
};

class Administrator : public Person{
    protected:
    string department;
    double salary;
    public:
    Administrator(string n,int a ,double cn, string ad, string dp, double sl):Person(n,a,cn,ad),department(dp),salary(sl){}
    void updateInfo(double cont,string addr, double newSalary) {
        Person::updateInfo( cont , addr);
        salary = newSalary;
        cout << "Salary updated to $" << salary << "\n";
    }

    void displayInfo() override{
        Person::displayInfo();
        cout<<"Department : "<<department<<endl;
        cout<<"Salary : "<<salary<<endl;
    }

};
int main(){
    Patient P1("Hammad", 19, 3001233322, "Askari 4", 1, "Autism", "Dr. Javaid");
    Doctor D1("Ahmed", 35, 3004567890, "North Nazimabad", "Pediatrician", 3000);
    Nurse N1("Mohammed", 28, 3005678901, "Phase 6", "A-12", "9:00 AM - 12:00 PM");
    Administrator A1("Ali", 40, 3006789012, "Block 7", "Cardiology", 4000);
    D1.addPatient("John Doe");

    cout << " Patient Info ";
    P1.displayInfo();

    cout << "Doctor Info ";
    D1.displayInfo();

    cout << "Nurse Info ";
    N1.displayInfo();

    cout << "Administrator Info ";
    A1.displayInfo();

    return 0;
}


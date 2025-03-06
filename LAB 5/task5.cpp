// HAMMAD SIDDIQUI
//24K-0702
#include <iostream>
#include <string>
using namespace std;

class Doctor{
    public:
    string name;
    string specialization;
    int experience;
    
    Doctor (string n,string sp,int xp):name(n),specialization(sp),experience(xp){}
};



class Hospital{
    private:
    Doctor *doctors[10];
    int doc_count;
    public:
    Hospital():doc_count(0){}
    
    void add(Doctor*doctor){
        if(doc_count<10){
            doctors[doc_count++] = doctor;
        }
        else{
            cout<<"Cannot add more DOCs"<<endl;
        }
    }
    
    void display(){
        cout<<" Current Doctors : "<<endl;
        for(int i=0;i<doc_count;i++){
            cout<<"Name : "<<doctors[i]->name<<endl;
            cout<<"specialization : "<<doctors[i]->specialization<<endl;
            cout<< "Experience : " <<doctors[i]->experience<<endl;
        }
    }
};

int main()
{
   Doctor d1("Abid","Gynecologist",14);
   Doctor d2("Asad","Urologist",9);
   
   Hospital H;
   
   H.add(&d1);
   H.add(&d2);
   H.display();
    return 0;
}

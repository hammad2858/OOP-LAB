#include "LabCourse.h"
#include<iostream>

LabCourse::LabCourse(string cc, int c,double ls,double ps):
Course(cc,c),labScore(ls),projectScore(ps){}
double LabCourse::CalculateGrade(){
    return (labScore*0.6) + (projectScore*0.4);

}
void LabCourse::displayinfo(){
    cout<<"LabCourse : "<<Coursecode<<endl;
    cout<<"Credits Hours : "<<credits<<endl;
    
}
#include "LectureCourse.h"
#include <iostream>

 LectureCourse::LectureCourse(string cc, int c , double ms,double fs):
Course(cc,c),midScore(ms),finalScore(fs){}
double LectureCourse::CalculateGrade(){
    return (midScore*0.3) + (finalScore*0.7);
}
void LectureCourse::displayinfo(){
    cout<<"Lecture Course :"<<Coursecode<<endl;
    cout<<"Credits : "<<credits<<endl;
}
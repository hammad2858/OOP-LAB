#include<iostream>
#include "LectureCourse.h"
#include "LabCourse.h"

int main(){
    LabCourse Lb1("CL-1002",1,50,69);
    LectureCourse Lc2("CS-1004",3,65,70);
    Lb1.CalculateGrade();
    Lb1.displayinfo();
    Lc2.CalculateGrade();
    Lc2.displayinfo();

    return 0;
}
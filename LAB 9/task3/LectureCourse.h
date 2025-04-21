#pragma once
#include "Course.h"

class LectureCourse : Course{
protected:
double midScore;
double finalScore;
public:
LectureCourse(string cc,int c, double ms,double fs):Course(cc,c),midScore(ms),finalScore(fs){}
double CalculateGrade() override;
void displayinfo()override;
};
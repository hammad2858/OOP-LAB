#pragma once
#include "Course.h"

class LabCourse : public Course{
    protected:
    double labScore;
    double projectScore;
    public:
    LabCourse(string cc, int c,double ls,double ps):
    Course(cc,c),labScore(ls),projectScore(ps){}
    double CalculateGrade() override;
    void displayinfo()override;
};
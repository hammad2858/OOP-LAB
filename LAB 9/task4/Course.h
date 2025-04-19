#pragma once
#include<iostream>
using namespace std;

class Course{
    protected:
     string Coursecode;
     int credits;
     public:
     Course(string cc,int c):Coursecode(cc),credits(c){}
     virtual double CalculateGrade() =0;
     virtual void displayinfo() = 0;
};

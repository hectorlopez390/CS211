/*
This header file declares a class Course. The Course has functions
to set values to data members and print course information.
*/
//Hector Lopez

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
using namespace std;

class Course
{
 private:
  long CourseNum; //Course number
  string CourseName; //Course name
 
 public:
  void setCourse(long cNum, string cName); //Method for setting data members
  void printCourse(); //Method for printing a course.
};

#endif //COURSE_H

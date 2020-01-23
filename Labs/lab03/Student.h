/*
This header file declares a class Student. Student has functions to
set data member values and to print Student information
 */
//Hector Lopez

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Course.h"

class Student
{
 private:
  long StNo; //Student number
  Course Course1; //1st course object
  Course Course2; //2nd course object
  Course Course3; //3rd course object
 public:
  void setStudent(long stNumber, long cNum1, string cName1, long cNum2, string cName2, long cNum3, string cName3); //Method for setting data member values
  void printStudent(); //Method for printing a student
};

#endif //STUDENT_H

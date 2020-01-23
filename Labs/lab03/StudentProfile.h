/*
This header file declares a class StudentProfile. StudentProfile has
functions to set values to Person and Student objects.
 */
//Hector Lopez

#ifndef STUDENTPROFILE_H
#define STUDENTPROFILE_H

#include "Person.h"
#include "Student.h"

class StudentProfile
{
 private:
  Person PersonalInfo; //Person object for personal information
  Student StdInfo; //Student object for student information
 public: 
  //Method for setting personal information 
  void setPersonalInfo(long social, string first, string last, int number, char sex);
  //Method for setting student information
  void setStdInfo(long stNumber, long cNum1, string cName1, long cNum2, string cName2, long cNum3, string cName3);
  //Method for printing a student profile
  void printStudentProfile();
  
};

#endif //STUDENTPROFILE_H

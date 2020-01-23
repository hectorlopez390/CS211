/*
This program file contains the implementation of the StudentProfile class
 */

#ifndef STUDENTPROFILE_CPP
#define STUDENTPROFILE_CPP

#include "StudentProfile.h"

//Method for setting personal information
void StudentProfile::setPersonalInfo(long social, string first, string last, int number, char sex)
{
  PersonalInfo.setPerson(social, first, last, number, sex);
}

//Method for setting student information
void StudentProfile::setStdInfo(long stNumber, long cNum1, string cName1, long cNum2, string cName2, long cNum3, string cName3)
{
  StdInfo.setStudent(stNumber, cNum1, cName1, cNum2, cName2, cNum3, cName3);
}

//Method for printing a student profile
void StudentProfile::printStudentProfile()
{
  PersonalInfo.printPerson();
  StdInfo.printStudent();
}

#endif //STUDENTPROFILE_CPP

/*
This program file contains the implementation of the Student class
 */

#ifndef STUDENT_CPP
#define STUDENT_CPP

#include "Student.h"

//Method for setting data member values
void Student::setStudent(long stNumber, long cNum1, string cName1, long cNum2, string cName2, long cNum3, string cName3)
{
  StNo = stNumber;
  Course1.setCourse(cNum1, cName1);
  Course2.setCourse(cNum2, cName2);
  Course3.setCourse(cNum3, cName3);
}

//Method for printing a student
void Student::printStudent()
{
  cout << "Student Number: " <<StNo << endl;

  Course1.printCourse();
  Course2.printCourse();
  Course3.printCourse();
}
#endif //STUDENT_CPP

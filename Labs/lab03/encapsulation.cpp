/**********************************************************************
Hector Lopez

This program uses the concept of encapsulation by making a collection
of students. The data file "data.txt" contains a set of information
about students and is read by the program and placed into four classes,
StudentProfile, Person, Student, and Course.
**********************************************************************/

#ifndef ENCAPSULATION_CPP
#define ENCAPSULATION_CPP

#include <fstream>
#include "StudentCollection.h"
#include "StudentProfile.h"

int main()
{
  StudentCollection CS211; //Instatiate a student collection for CS211 students
  StudentProfile newStudentProfile; //Instantiate a new student profile
  fstream fin; 

  //declare variables
  int number;
  char sex;
  long stNumber, social, cNum1, cNum2, cNum3;
  string first, last, cName1, cName2, cName3;

  fin.open("data.txt"); //open file to read set of information about students

  fin >> stNumber >> first >> last
      >> number  >> sex >> social
      >> cNum1 >> cName1
      >> cNum2 >> cName2
      >> cNum3 >> cName3;

  while(!fin.eof()) //read information until end of file
    {
      //set new student profile personal information
      newStudentProfile.setPersonalInfo(social, first, last, number, sex);  
      //set new student profile student information
      newStudentProfile.setStdInfo(stNumber, cNum1, cName1, cNum2, cName2, cNum3, cName3);
      //add new student profile to student collection CS211
      CS211.addStudentProfile(newStudentProfile);

      //read next set of student information
      fin >> stNumber >> first >> last
          >> number  >> sex >> social
          >> cNum1 >> cName1
          >> cNum2 >> cName2
          >> cNum3 >> cName3;
    }
  //close file
  fin.close();

  CS211.printCollection(); //print student collection

  return 0;
}

#endif //ENCAPSULATION_CPP

/*
Output:
MacBook-Pro-3:lab3 hector$ g++ encapsulation.cpp StudentCollection.cpp StudentProfile.cpp Person.cpp Student.cpp Course.cpp
MacBook-Pro-3:lab3 hector$ ./a.out
SSN: 789101100
First Name: Jim
Last Name: Klose
Age: 20
Gender: M
Student Number: 123453
Course 1 Number: 133
Course 1 Name: CS111
Course 2 Number: 134
Course 2 Name: CS211
Course 3 Number: 135
Course 3 Name: CS311

SSN: 505025323
First Name: Nancy
Last Name: Brown
Age: 25
Gender: F
Student Number: 77777890
Course 1 Number: 192
Course 1 Name: Chem101
Course 2 Number: 193
Course 2 Name: Chem102
Course 3 Number: 194
Course 3 Name: Chem103

SSN: 125125345
First Name: Fiba
Last Name: Emrar
Age: 23
Gender: F
Student Number: 888110
Course 1 Number: 345
Course 1 Name: Math201
Course 2 Number: 346
Course 2 Name: Math301
Course 3 Number: 347
Course 3 Name: Math401
*/

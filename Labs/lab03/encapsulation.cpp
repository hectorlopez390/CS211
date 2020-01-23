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

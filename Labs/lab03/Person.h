/*
This header file declares a class Person. Person has functions to
set data member values and to print person information
 */
//Hector Lopez

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person
{
 private:
  long SSN; //social security number
  string Fname; //first name
  string Lname; //last name
  int Age;  
  char Gender; 
 public:
  //Methodd for setting data member values
  void setPerson(long social, string first, string last, int number, char sex);
  //Method for printing a person
  void printPerson();
};

#endif //PERSON_H

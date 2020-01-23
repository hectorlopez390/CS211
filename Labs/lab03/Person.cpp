/*
This program file contains the implementation of the Person class
 */

#ifndef PERSON_CPP
#define PERSON_CPP

#include "Person.h"

//Method for setting data member values
void Person::setPerson(long social, string first, string last, int number, char sex)
{
  SSN = social;
  Fname = first;
  Lname = last;
  Age = number;
  Gender = sex;
}

//Method for printing a person
void Person::printPerson()
{
  cout << "SSN: " << SSN << endl;
  cout << "First Name: " << Fname << endl;
  cout << "Last Name: " << Lname << endl;
  cout << "Age: " << Age << endl;
  cout << "Gender: " << Gender << endl;
}

#endif //PERSON_H

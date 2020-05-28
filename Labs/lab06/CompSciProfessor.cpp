#ifndef COMPSCIPROFESSOR_CPP
#define COMPSCIPROFESSOR_CPP
#include "CompSciProfessor.h"

CompSciProfessor::CompSciProfessor()
{
  //initialize attributes to arbitrary numbers
  name = "John Smith";
  email = "johnsmith@university.edu";
  facultyId = 00000;  
}

void CompSciProfessor::setName(string n)
{
  name = n;
}

string CompSciProfessor::getName()
{
  return name;
}

void CompSciProfessor::setEmail(string e)
{
  email = e;
}

string CompSciProfessor::getEmail()
{
  return email;
}

void CompSciProfessor::setFacultyId(long id)
{
  facultyId = id;
}

long CompSciProfessor::getFacultyId()
{
  return facultyId;
}

#endif //COMPSCIPROFESSOR_CPP

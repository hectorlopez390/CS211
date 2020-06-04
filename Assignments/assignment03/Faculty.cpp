#ifndef FACULTY_CPP
#define FACULTY_CPP
#include "Faculty.h"
#include <iostream>

long Faculty::nextFacultyId = 600;

Faculty::Faculty()
{
  id = 0;
  name = "";
  email = "";
  address = "";
  dateOfBirth = "";
  gender = "";
  salary = 0;
  yearOfExp = 0;
  departId = 0;
  nextFacultyId++;
}

Faculty::Faculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId)
{
  id = nextFacultyId;
  name = fName;
  email = fEmail;
  address = fAddress;
  dateOfBirth = fDateOfBirth;
  gender = fGender;
  salary = fSalary;
  yearOfExp = fYearOfExp;
  departId = fDepId;
  nextFacultyId++;
}

float Faculty::getSalary()
{
  return salary;
}

int Faculty::getYearOfExp()
{
  return yearOfExp;
}

long Faculty:: getDepId()
{
  return departId;
}

long Faculty::getNextFacultyId()
{
  return nextFacultyId;
}

void Faculty::print() const
{
  cout << "Faculty ID: " << id << endl;
  cout << "Faculty Name: " << name << endl;
  cout << "Faculty Email: " << email << endl;
  cout << "Faculty Address: " << address << endl;
  cout << "Faculty Date of Birth: " << dateOfBirth << endl;
  cout << "Faulty Gender: " << gender << endl;
  cout << "Salary: " << salary << endl;
  cout << "Years of Experience: " << yearOfExp << endl;
  cout << "Department ID: " << departId << endl;
}
#endif //FACULTY_CPP

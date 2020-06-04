#ifndef STUDENT_CPP
#define STUDENT_CPP
#include "Student.h"
#include <iostream>

long Student::nextStId = 500;

Student::Student()
{
  id = 0;
  name = "";
  email = "";
  address = "";
  dateOfBirth = "";
  gender = "";
  yearOfStudy = 0;
  major = "";
  advisorId = 0;
}

Student::Student(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
  id = nextStId;
  name = sName;
  email = sEmail;
  address = sAddress;
  dateOfBirth = sDateOfBirth;
  gender = sGender;
  yearOfStudy = sYearOfStudy;
  major = sMajor;
  advisorId = sAdvisorId;
  nextStId++;
}

long Student::getAdvisorId()
{
  return advisorId;
}

vector<Course> Student::getCoursesTaken()
{
  return coursesTaken;
}

void Student::setCoursesTaken(vector<Course> courses)
{
  coursesTaken = courses;
}

void Student::print() const
{
  cout << "Student ID: " << id << endl;
  cout << "Student Name; " << name << endl;
  cout << "Student Email: " << email << endl;
  cout << "Student Address: " << address << endl;
  cout << "Student Date of Birth: " << dateOfBirth << endl;
  cout << "Student gender: " << gender << endl;
  cout << "Year of Study: " << yearOfStudy << endl;
  cout << "Major: " << major << endl;
  cout << "Advisor ID: " << advisorId << endl;
}
#endif //STUDENT_CPP

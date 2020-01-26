/*************************************************
Hector Lopez

This program creates a collection of students using 
the concept of classes and object oriented programming. 
The program reads a data file into a vector and prints
each object on the screen.
*************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Person
{
public:
  long SSN;
  string Fname;
  string Lname;
  int Age;
  char Gender;

};

class Course
{
public:
  long CourseNum;
  string CourseName;
};

class Student
{
public:
  long StNo;
  Course Course1;
  Course Course2;
  Course Course3;

};

class StudentProfile
{
public:
  Person PersonalInfo;
  Student StdInfo;

};

class StudentCollection
{
public:
  vector<StudentProfile> CS211;

};

void printStudentProfile(StudentCollection);

int main()
{
  fstream fin;
  StudentCollection Students;
  StudentProfile newStudentProfile;

  fin.open("data.txt");  

  while(!fin.eof())
    {
      fin >> newStudentProfile.PersonalInfo.SSN;
      fin >> newStudentProfile.PersonalInfo.Fname;
      fin >> newStudentProfile.PersonalInfo.Lname;
      fin >> newStudentProfile.PersonalInfo.Age;
      fin >> newStudentProfile.PersonalInfo.Gender;
      fin >> newStudentProfile.StdInfo.StNo;
      fin >> newStudentProfile.StdInfo.Course1.CourseNum;
      fin >> newStudentProfile.StdInfo.Course1.CourseName;
      fin >> newStudentProfile.StdInfo.Course2.CourseNum;
      fin >> newStudentProfile.StdInfo.Course2.CourseName;
      fin >> newStudentProfile.StdInfo.Course3.CourseNum;
      fin >> newStudentProfile.StdInfo.Course3.CourseName;
      Students.CS211.push_back(newStudentProfile);
    }

  printStudentProfile(Students);

  return 0;
}

void printStudentProfile(StudentCollection Students)
{
  for(int i = 0; i < Students.CS211.size(); i++)
    {
      cout << "SSN: " << Students.CS211[i].PersonalInfo.SSN << endl;
      cout << "First Name: " << Students.CS211[i].PersonalInfo.Fname << endl;
      cout << "Last Name: " << Students.CS211[i].PersonalInfo.Lname << endl;
      cout << "Age: " << Students.CS211[i].PersonalInfo.Age << endl;
      cout << "Gender: " << Students.CS211[i].PersonalInfo.Gender << endl;
      cout << "Student Number: " << Students.CS211[i].StdInfo.StNo << endl;
      cout << "Course 1 Number: " << Students.CS211[i].StdInfo.Course1.CourseNum << endl;
      cout << "Course 1 Name: " << Students.CS211[i].StdInfo.Course1.CourseName << endl;
      cout << "Course 2 Number: " << Students.CS211[i].StdInfo.Course2.CourseNum << endl;
      cout << "Course 2 Name: " << Students.CS211[i].StdInfo.Course2.CourseName << endl;
      cout << "Course 3 Number: " << Students.CS211[i].StdInfo.Course3.CourseNum << endl;
      cout << "Course 3 Name: " << Students.CS211[i].StdInfo.Course3.CourseName << endl;
      cout <<endl;
    }
}

/*
Output:
MacBook-Pro-3:lab2 hector$ g++ classes.cpp
MacBook-Pro-3:lab2 hector$ ./a.out
SSN: 123453
First Name: Jim
Last Name: Klose
Age: 20
Gender: M
Student Number: 789101100
Course 1 Number: 133
Course 1 Name: CS111
Course 2 Number: 134
Course 2 Name: CS211
Course 3 Number: 135
Course 3 Name: CS311

SSN: 77777890
First Name: Nancy
Last Name: Brown
Age: 25
Gender: F
Student Number: 505025323
Course 1 Number: 192
Course 1 Name: Chem101
Course 2 Number: 193
Course 2 Name: Chem102
Course 3 Number: 194
Course 3 Name: Chem103

SSN: 888110
First Name: Fiba
Last Name: Emrar
Age: 23
Gender: F
Student Number: 125125345
Course 1 Number: 345
Course 1 Name: Math201
Course 2 Number: 346
Course 2 Name: Math301
Course 3 Number: 347
Course 3 Name: Math401

SSN: 888110
First Name: Fiba
Last Name: Emrar
Age: 23
Gender: F
Student Number: 125125345
Course 1 Number: 345
Course 1 Name: Math201
Course 2 Number: 346
Course 2 Name: Math301
Course 3 Number: 347
Course 3 Name: Math401
*/

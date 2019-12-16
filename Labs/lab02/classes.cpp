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

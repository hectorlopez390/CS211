/*
This program file contains the implementation of the Employee class
 */

#ifndef EMPLOYEE_CPP
#define EMPLOYEE_CPP

#include "Employee.h"

//Initialize static variables
int Employee::totalNumOfEmployees = 0;
int Employee::nextEmpId = 1000;
int Employee::nextOfficeNo = 10;

//Default constructor        
Employee::Employee(): officeNo(nextOfficeNo), empId(nextEmpId)
{
  //set attributes      
  name = "Unknown";
  deptNo = 0;
  empPosition = 'E';
  yearOfExp = 0;
  salary = 0;

  //all static attributes incremented by 1                                                           
  totalNumOfEmployees++;
  nextEmpId++;
  nextOfficeNo++;
}

//destructor
Employee::~Employee()
{
  totalNumOfEmployees--;
}

//Second constructor with parameters
Employee::Employee(string theName, int theDeptNo, char theEmpPosition, int theYearOfExp): officeNo(nextOfficeNo), empId(nextEmpId)
{
  //set attributes
  name = theName;
  deptNo = theDeptNo;
  empPosition = theEmpPosition;
  yearOfExp = theYearOfExp;
  salary = 0;

  //all static attributes incremented by 1
  totalNumOfEmployees++;
  nextEmpId++;
  nextOfficeNo++;
}

//Method to print employee information
void Employee::Print() const
{
  cout << endl;
  cout << "Name: " << name << endl;
  cout << "Office Number: " << officeNo << endl;
  cout << "Employee Number: " << empId << endl;
  cout << "Department Number: " << deptNo << endl;
  cout << "Employee Position: " << empPosition << endl;
  cout << "Years of Experience: " << yearOfExp << endl;
  cout << "Salary: " << salary << endl;

  cout << "Total Number of Employees: " << totalNumOfEmployees << endl;
  cout << "Next Employee Number: " << nextEmpId << endl;
  cout << "Next Office Number: " << nextOfficeNo << endl;
}

//Method for getting employee information from user
void Employee::GetInfo()
{
  cout << endl;
  cout << "Enter employee name: ";
  getline(cin, name);

  cout << "Enter employee position: " ;
  cin >> empPosition;

  cout << "Enter years of experience: ";
  cin >> yearOfExp;
}
#endif //EMPLOYEE_CPP

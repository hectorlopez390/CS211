/*
This header file declares a class Employee. Employee has functions to
set attributes, print attributes, and get information from user.
 */
//Hector Lopez

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

class Employee
{
  friend void SetSalary(Employee& e);

 private:
  string name;
  const long officeNo;
  const long empId;
  int deptNo;
  char empPosition; // ‘E’: entry level, ‘M’: manager, ‘D’: Director, ‘P’:Project_leader 
  int yearOfExp;
  float salary;
  static int totalNumOfEmployees;
  static int nextEmpId;
  static int nextOfficeNo;

 public:
  Employee(); //constructor
  ~Employee(); //destructor
  Employee(string theName, int theDeptNo, char theEmpPosition, int theYearOfExp); //second constructor
  void Print() const; //method for printing
  void GetInfo(); //method for user input
};

#endif //EMPLOYEE_H

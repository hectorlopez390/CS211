/***************************************************************
Hector Lopez

This program uses the concept of constant objects, constant
class members, friend functions, and static attributes.The driver 
program creates an employee object which then prints information 
given by the constructor, and creates a second employee object
wchich then prints information given by the user.

***************************************************************/

#ifndef CONSTFRIENDSTATIC_CPP
#define CONSTFRIENDSTATIC_CPP

#include "Employee.h"

//stand alone function sets salary of employee according to rules
void SetSalary(Employee& e)
{
  if(e.empPosition == 'E' && e.yearOfExp < 2) //if position is entry and years of experience is less than 2
    e.salary = 50000;
  if(e.empPosition == 'E' && e.yearOfExp >= 2) //if position is entry and years of experience is greater than or equal to 2
    e.salary = 55000;
  if(e.empPosition == 'P' && e.yearOfExp < 4) //if postion is project leader and years of experience is less than 4
    e.salary = 60000;
  if(e.empPosition == 'P' && e.yearOfExp >= 4) //if position is project leader and years of experience is greater than or equal to 4
    e.salary = 65000;
  if(e.empPosition == 'M') //if position is manager
    e.salary = 70000;
  if(e.empPosition == 'D') //if position is director
    e.salary = 80000;
}

int main()
{
  Employee emp1; //instantiate first employee object
  emp1.Print(); //print first employee object

  Employee emp2("Unknown", 10, '?', 0); //instantiate second employee object with parameters
  emp2.GetInfo(); //get information from user
  SetSalary(emp2); //set second employee salary
  emp2.Print(); //print second employee object

  return 0;
}

#endif //CONSTFRIENDSTATIC_CPP

/*
Output:
MacBook-Pro-3:lab4 hector$ g++ Employee.cpp constFriendStatic.cpp
MacBook-Pro-3:lab4 hector$ ./a.out

Name: Unknown
Office Number: 10
Employee Number: 1000
Department Number: 0
Employee Position: E
Years of Experience: 0
Salary: 0
Total Number of Employees: 1
Next Employee Number: 1001
Next Office Number: 11

Enter employee name: Adam Smith
Enter employee position: P
Enter years of experience: 7

Name: Adam Smith
Office Number: 11
Employee Number: 1001
Department Number: 10
Employee Position: P
Years of Experience: 7
Salary: 65000
Total Number of Employees: 2
Next Employee Number: 1002
Next Office Number: 12
*/

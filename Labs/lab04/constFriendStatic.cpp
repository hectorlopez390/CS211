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

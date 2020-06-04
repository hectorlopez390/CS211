#ifndef DEPARTMENT_CPP
#define DEPARTMENT_CPP
#include <iostream>
#include "Department.h"

long Department::nextDepartId = 100;

Department::Department()
{
  name = "";
  location = "";
  chairId = 0;
  id = 0;
  nextDepartId = 0;
}

Department::Department(string depName, string depLoc, long depChairId)
{
  name = depName;
  location = depLoc;
  chairId = depChairId;
  id = nextDepartId;
  nextDepartId++;
}

void Department::setDepartmentInfo(string depName, string depLoc, long depChairId)
{
  // id = depId;
  name = depName;
  location = depLoc;
  chairId = depChairId;
}

long Department::getId()
{
  return id;
}

string Department::getName()
{
  return name;
}

string Department::getLocation()
{
  return location;
}
void Department::setChairId(long depChairId)
{
  chairId = depChairId;
}
long Department::getChairId()
{
  return chairId;
}

long Department::getNextDepId()
{
  return nextDepartId;
}

void Department::print() const
{
  cout << "Department ID: " << id << endl;
  cout << "Department Name: " << name << endl;
  cout << "Department Location: " << location << endl;
  cout << "Department Chair ID: " << chairId << endl;
}
#endif //DEPARTMENT_CPP

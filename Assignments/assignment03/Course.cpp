#ifndef COURSE_CPP
#define COURSE_CPP
#include "Course.h"
#include <iostream>

long Course::nextCRN = 200;

Course::Course()
{
  CRN = 0;
  maxAvailableSeats = 0;
  name = "";
  departId = 0;
  assignedSeats = 0;
  isTaughtBy = 0;
  nextCRN++;
}
Course::Course(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
  CRN = nextCRN;
  maxAvailableSeats = cMaxSeat;
  name = cName;
  departId = cDepId;
  assignedSeats = 0;
  isTaughtBy = cTaughtBy;
  nextCRN++;
}

long Course::getCRN()
{
  return CRN;
}

int Course::getMaxAvailableSeats()
{
  return maxAvailableSeats;
}

string Course::getName()
{
  return name;
}

long Course::getDepartId()
{
  return departId;
}

long Course::getAssignedSeats()
{
  return assignedSeats;
}

void Course::setIsTaughtBy(long cTaughtBy)
{
  isTaughtBy = cTaughtBy;
}

long Course::getIsTaughtBy()
{
  return isTaughtBy;
}

long Course::getNextCRN()
{
return nextCRN;
}

void Course::print() const
{
  cout << "Course Number: " << CRN << endl;
  cout << "Max Available Seats: " << maxAvailableSeats << endl;
  cout << "Course Name: " << name << endl;
  cout << "Course Department ID: " << departId << endl;
  cout << "Assigned Seats: " << assignedSeats << endl;
  cout << "Taught By: " << isTaughtBy << endl;
}
#endif //COURSE_CPP

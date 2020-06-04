#ifndef FACULTY_H
#define FACULTY_H
#include "UniversityMember.h"

class Faculty: public UniversityMember
{
 protected:
  float salary;
  int yearOfExp;
  long departId;
  static long nextFacultyId;
 public:
  Faculty();
  Faculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId);
  void setFacultyInfo(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId);
  float getSalary();
  int getYearOfExp();
  long getDepId();
  long getNextFacultyId();
  void print() const;
};

#endif //FACULTY_H

#ifndef ADJUNCTPROF_CPP
#define ADJUNCTPROF_CPP
#include "AdjunctProf.h"

AdjunctProf::AdjunctProf()
{
  //initialize the attributes to arbitrary numbers
  degree = 'B';
  NoOfTA = 0;
  NoOfCourses = 0;
}

void AdjunctProf::setDegree(char d)
{
  degree = d;
}

char AdjunctProf::getDegree()
{
  return degree;
}

void AdjunctProf::setNoOfTA(int ta)
{
  NoOfTA = ta;
}

int AdjunctProf::getNoOfTA()
{
  return NoOfTA;
}

void AdjunctProf::setNoOfCourses(int noc)
{
  NoOfCourses = noc;
}

int AdjunctProf::getNoOfCourses()
{
  return NoOfCourses;
}

void AdjunctProf::print() const
{
  cout << "Name: " << name << endl;
  cout << "Email: " << email << endl;
  cout << "Faculty ID: " << facultyId << endl;
  cout << "Degree: " << degree << endl;
  cout << "Number of TAs: " << NoOfTA << endl;
  cout << "Number of Courses: " << NoOfCourses << endl;
}

float AdjunctProf::findSalary() const
{
  //calculate salary based on degree and attributes
  if(degree == 'B')
    {
      return ((NoOfTA * 1500) + (NoOfCourses * 3000));
    }
   else if(degree == 'M')
    {
      return((NoOfTA * 2000) + (NoOfCourses * 4000));
    }
   else
    {
      return((NoOfTA * 2500) + (NoOfCourses * 5000));
    }
}

#endif //ADJUNCTPROF_CPP 

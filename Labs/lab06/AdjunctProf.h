#ifndef ADJUNCTPROF_H
#define ADJUNCTPROF_H
#include "CompSciProfessor.h"

//specialized class Adjunct Professor
class AdjunctProf: public CompSciProfessor
{
 private: //three attributes of its own
  char degree; //'B' for bachelor degree, 'M' for Master Degree, 'P' for PhD
  int NoOfTA; //number of TAs professor is doing for the courses
  int NoOfCourses; //number of courses professor is currently teaching in department
 public:
  AdjunctProf(); //default constructor
  
  //set and get functions
  void setDegree(char d);
  char getDegree();
  void setNoOfTA(int ta);
  int getNoOfTA();
  void setNoOfCourses(int noc);
  int getNoOfCourses();
  
  void print() const; //constant method that prints both specialized and inherited attributes
  float findSalary() const; //constant method that calculates the salary of adjunct professor
};

#endif //ADJUNCTPROF_H

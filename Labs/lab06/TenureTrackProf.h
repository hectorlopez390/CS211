#ifndef TENURETRACKPROF_H
#define TENURETRACKPROF_H
#include "CompSciProfessor.h"

//specialized class TenureTrackProf
class TenureTrackProf: public CompSciProfessor
{
 private: //has two attributes of its own
  char rank;
  int YearOfExp;
 public:
  TenureTrackProf(); //default constructor

  //set and get functions
  void setRank(char r);
  char getRank();
  void setYearOfExp(int yoe);
  int getYearOfExp();

  
  void print() const; //constant method for printing both specialized and inherited attributes
  float findSalary() const; //constant method that calculates the salary of tenure track professor
};
#endif //TENURETRACKPROF_H

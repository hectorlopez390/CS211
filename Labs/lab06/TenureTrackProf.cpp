#ifndef TENURETRACKPROF_CPP
#define TENURETRACKPROF_CPP
#include "TenureTrackProf.h"

TenureTrackProf::TenureTrackProf()
{
  rank = 'A';
  YearOfExp = '0';;
}

void TenureTrackProf::setRank(char r)
{
  rank = r;
}

char TenureTrackProf::getRank()
{
  return rank;
}

void TenureTrackProf::setYearOfExp(int yoe)
{
  YearOfExp = yoe;
}

int TenureTrackProf::getYearOfExp()
{
  return YearOfExp;
}

void TenureTrackProf::print() const
{
  cout << "Name: " << name << endl;
  cout << "Email: " << email << endl;
  cout << "Faculty ID: " << facultyId << endl;
  cout << "Rank: " << rank << endl;
  cout << "Years of Experience: " << YearOfExp << endl;
}

float TenureTrackProf::findSalary() const
{
  if(rank == 'A')
    {
      return (65000 + (1500 * YearOfExp));
    }
  else if(rank == 'S')
    {
      return (80000 + (1500 * YearOfExp));
    }
  else
    {
      return (90000 + (1500 * YearOfExp));
    }
}

#endif //TENURETRACKPROF_CPP

#ifndef COMPSCIPROFESSOR_H
#define COMPSCIPROFESSOR_H
#include <iostream>
using namespace std;

//base class
class CompSciProfessor
{
 protected: 
  string name;
  string email;
  long facultyId;
 public:
  CompSciProfessor(); //default constructor
  
  //set and get functions
  void setName(string n);
  string getName();
  void setEmail(string e);
  string getEmail();
  void setFacultyId(long id);
  long getFacultyId();
};

#endif //COMPSCIPROFESSOR_H

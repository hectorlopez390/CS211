/*
This header file declares a class StudentCollection. StudentCollection
has functions to add a new student profile and to print student 
collection.
*/
//Hector Lopez

#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H

#include <vector>
#include "StudentProfile.h"

class StudentCollection
{
 private:
  vector<StudentProfile> StCollection; //vector of student profiles
 public:
  //Method for adding a new student profile
  void addStudentProfile(StudentProfile newStudentProfile);
  //Method for printing student collection
  void printCollection();

};


#endif //STUDENTCOLLECTION_H

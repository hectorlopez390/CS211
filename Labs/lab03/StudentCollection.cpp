/*
This program file contains the implementation of the class StudentCollection.
*/

#ifndef STUDENTCOLLECTION_CPP
#define STUDENTCOLLECTION_CPP

#include "StudentCollection.h"

//Method for adding a new student profile
void StudentCollection::addStudentProfile(StudentProfile newStudentProfile)
{
  StCollection.push_back(newStudentProfile);
}

//Method for printing student collection
void StudentCollection::printCollection()
{
  for(int i = 0; i < StCollection.size(); i++)
    {
      StCollection[i].printStudentProfile();
      cout << endl;
    }  
}
#endif //STUDENTCOLLECTION_CPP

/*
This program file contains the implementation of the Course class.
 */

#ifndef COURSE_CPP
#define COURSE_CPP

#include "Course.h"

//This method assigns values to the Course object
void Course::setCourse(long cNum,string cName) 
{
  CourseNum = cNum;
  CourseName = cName;
}

//Method for printing Course number and name
void Course::printCourse()
{
  static int count = 1; //initialize 1st course output number

  cout << "Course " << count << " Number: " << CourseNum << endl;
  cout << "Course " << count << " Name: " << CourseName << endl;

  if(count > 2) //Each student has only 3 courses
    count = 1;
  else
    count++;
}

#endif //COURSE_CPP

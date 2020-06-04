#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include "UniversityMember.h"
#include "Course.h"

class Student: public UniversityMember
{
 protected:
  int yearOfStudy;
  string major;
  long advisorId;
  vector<Course> coursesTaken;
  static long nextStId;
 public:
  Student();
  Student(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);
  void setStudentInfo(int sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);
  int getYearOfStudy();
  string getMajor();
  long getAdvisorId();
  vector<Course> getCoursesTaken();
  void setCoursesTaken(vector<Course> courses);
  void print() const;
};
#endif //STUDENT_H

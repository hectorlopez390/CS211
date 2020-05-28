/**********************************************************************
Hector Lopez
This program creates a parent class called CompSciProfessor. Each 
professor has name, email, and facultyId. The CompSciProfessor class
is specialized into two more classes:AdjunctProf and TenureTrackProf
classes. Main program creates two objects, 1 of AdjunctProf and 1 of 
TenureTrackrof. Information of both professors is printed along with
calculated salary.
**********************************************************************/

#ifndef MAIN_CPP
#define MAIN_CPP
#include "AdjunctProf.h"
#include "TenureTrackProf.h"

int main()
{

  AdjunctProf AdamSmith;
  AdamSmith.setName("Adam Smith");
  AdamSmith.setFacultyId(12345);
  AdamSmith.setEmail("asmith@csusm.edu");
  AdamSmith.setNoOfCourses(1);
  AdamSmith.setNoOfTA(2);
  AdamSmith.print();
  cout << "Salary: " << AdamSmith.findSalary() << endl;
  cout << endl;

  TenureTrackProf JimAnderson;
  JimAnderson.setName("Jim Anderson");
  JimAnderson.setFacultyId(54321);
  JimAnderson.setEmail("janderson@csusm.edu");
  JimAnderson.setRank('S');
  JimAnderson.setYearOfExp(8);
  JimAnderson.print();
  cout << "Salary: " << JimAnderson.findSalary() << endl;
  cout << endl;

  return 0;
}

#endif //MAIN_CPP

/*
Output:
MacBook-Pro-3:lab6 hector$ g++ CompSciProfessor.cpp AdjunctProf.cpp TenureTrackProf.cpp main.cpp
MacBook-Pro-3:lab6 hector$ ./a.out
Name: Adam Smith
Email: asmith@csusm.edu
Faculty ID: 12345
Degree: B
Number of TAs: 2
Number of Courses: 1
Salary: 6000

Name: Jim Anderson
Email: janderson@csusm.edu
Faculty ID: 54321
Rank: S
Years of Experience: 8
Salary: 92000
*/

/**********************************************************************
Hector Lopez
This program implements a small university. The University has the 
following coponents: Department, Student, Faculty, and Course. The 
program reads a transaction file containing 17 different commands, each
with its own set of data. When reading the transaction file, the program
will modify, create, or list University components.

**********************************************************************/

#ifndef MAIN_CPP
#define MAIN_CPP
#include <iostream>
#include "University.h"

//----------------------------------------------------------------------------

int main() 
{
  University csusm;
  csusm.ProcessTransactionFile("TransactionFile.txt");
   
}
//----------------------------------------------------------------------------


#endif //MAIN_CPP

/*
Output:
MacBook-Pro-3:assignment3 hector$ g++ Course.cpp Department.cpp Faculty.cpp Student.cpp University.cpp UniversityMember.cpp main.cpp
MacBook-Pro-3:assignment3 hector$ ./a.out
Department ComputerScience created.

Department Education created.

Department Business created.

Department Engineering created.

Department Biology cannot be created: Chair ID is invalid.

Listing Departments...

Department ID: 100
Department Name: ComputerScience

Department ID: 101
Department Name: Education

Department ID: 102
Department Name: Business

Department ID: 103
Department Name: Engineering

Faculty John_Smith created.

Faculty Bob_Anderson created.

Faculty Sue_Clark created.

Faculty Abu_Talib created.

Faculty Nancy_Bank created.

Faculty Susan_Brown created.

Faculty Ahmad_Saleh created.

Faculty Beth_Card created.

Faculty Joe_Abraham created.

Faculty Andy_Chan cannot be created: Department ID 130 does not exist.

Listing Faculties...

Faculty ID: 600
Faculty Name: John_Smith

Faculty ID: 601
Faculty Name: Bob_Anderson

Faculty ID: 602
Faculty Name: Sue_Clark

Faculty ID: 603
Faculty Name: Abu_Talib

Faculty ID: 604
Faculty Name: Nancy_Bank

Faculty ID: 605
Faculty Name: Susan_Brown

Faculty ID: 606
Faculty Name: Ahmad_Saleh

Faculty ID: 607
Faculty Name: Beth_Card

Faculty ID: 608
Faculty Name: Joe_Abraham

Faculties in Department 100: 

Faculty ID: 600
Faculty Name: John_Smith

Faculty ID: 601
Faculty Name: Bob_Anderson

Faculty ID: 602
Faculty Name: Sue_Clark

Faculties in Department 101: 

Faculty ID: 603
Faculty Name: Abu_Talib

Faculty ID: 604
Faculty Name: Nancy_Bank

Faculty ID: 605
Faculty Name: Susan_Brown

Faculties in Department 102: 

Faculty ID: 606
Faculty Name: Ahmad_Saleh

Faculty ID: 607
Faculty Name: Beth_Card

Faculty ID: 608
Faculty Name: Joe_Abraham

Cannot list faculties: Department ID 130 does not exist.

Student Kathy_Chen created.

Student Kelly_Wong created.

Student Layla_Esmail cannot be created: Advisor ID 910 does not exist.

Listing Students...

Student ID: 500
Student Name: Kathy_Chen

Student ID: 501
Student Name: Kelly_Wong

Students of Faculty 600: 

Student ID: 500
Student Name: Kathy_Chen

Student ID: 501
Student Name: Kelly_Wong

Cannot list students: Faculty ID 650 does not exist.

Course CS111 created.

Course CS211 created.

Course CS311 created.

Course Ed100 created.

Course Ed200 created.

Course Ed300 created.

Course Bus101 created.

Course Bus102 created.

Course Bus103 created.

Course Bio103 cannot be created: Faculty ID 706 does not exist.

Listing Courses...

Course ID: 200
Course Name: CS111

Course ID: 201
Course Name: CS211

Course ID: 202
Course Name: CS311

Course ID: 203
Course Name: Ed100

Course ID: 204
Course Name: Ed200

Course ID: 205
Course Name: Ed300

Course ID: 206
Course Name: Bus101

Course ID: 207
Course Name: Bus102

Course ID: 208
Course Name: Bus103

Courses taught by Faculty 606: 

Course ID: 206
Course Name: Bus101

Course ID: 207
Course Name: Bus102

Cannot list courses taught by faculty: Faculty ID 706 does not exist.

Courses offered by Department 100: 

Course ID: 200
Course Name: CS111

Course ID: 201
Course Name: CS211

Course ID: 202
Course Name: CS311

Courses offered by Department 101: 

Course ID: 203
Course Name: Ed100

Course ID: 204
Course Name: Ed200

Course ID: 205
Course Name: Ed300

Courses offered by Department 102: 

Course ID: 206
Course Name: Bus101

Course ID: 207
Course Name: Bus102

Course ID: 208
Course Name: Bus103

Cannot list courses: Department ID 130 does not exist.

Course 200 added for student: 500

Course 201 added for student: 500

Course 202 added for student: 500

Cannot add course: Course ID 230 does not exist.

Courses taken by Student 500: 

Course ID: 200
Course Name: CS111

Course ID: 201
Course Name: CS211

Course ID: 202
Course Name: CS311

Cannot list courses taken by student: Student ID 520 does not exist.

Courses taken by Student 500: 

Course ID: 200
Course Name: CS111

Course ID: 201
Course Name: CS211

Course ID: 202
Course Name: CS311

Faculty 600 assigned as Chair for Department: 100

Cannot assign department chair: Faculty ID 610 does not exist.

Cannot assign department chair: Department ID 110 does not exist.

Instructor 600 assigned to course: 202

Courses taught by Faculty 600: 

Course ID: 200
Course Name: CS111

Course ID: 201
Course Name: CS211

Course ID: 202
Course Name: CS311

*/

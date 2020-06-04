#ifndef UNIVERSITY_CPP
#define UNIVERSITY_CPP
#include "University.h"
#include <fstream>
#include <iostream>

using namespace std;

bool University::failure = false;
bool University::success = true;

//----------------------------------------------------------------------------

University::University()
{
  
}
//----------------------------------------------------------------------------

University::~University()
{
  
}
//----------------------------------------------------------------------------
bool University::checkIfDepartmentExists(long depId)
{
  for(int i = 0; i < Departments.size(); i++)
    {
      if(Departments[i].getId() == depId)
	return success;
    }
  return failure;
}
//----------------------------------------------------------------------------
bool University::checkIfDepartmentExists(string sMajor)
{
  for(int i = 0; i < Departments.size(); i++)
    {
      if(Departments[i].getName() == sMajor)
        return success;
    }
  return failure;
}
//----------------------------------------------------------------------------
bool University::checkIfCourseExists(long courseId)
{
  for(int i = 0; i < Courses.size(); i++)
    {
      if(Courses[i].getCRN() == courseId)
	return success;
    }
  return failure;
}
//----------------------------------------------------------------------------
bool University::checkIfStudentExists(long studentId)
{
  for(int i = 0; i < Students.size(); i++)
    {
      if(Students[i].getId() == studentId)
	return success;
    }
  return failure;
}
//----------------------------------------------------------------------------
bool University::checkIfFacultyExists(long facultyId)
{
  for(int i = 0; i < Faculties.size(); i++)
    {
      if(Faculties[i].getId() == facultyId)
	return success;
    }
  return failure;
}
//----------------------------------------------------------------------------
bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{
  if(depChairId != 0) //if depChairId is known 
    {
      if(!checkIfFacultyExists(depChairId)) //check if depChairId is valid existing faculty
	{
	  cout << "Department " << depName << " cannot be created: Chair ID is invalid." << endl;
	  return failure;
	}
    }     
  Department newDepartment(depName, depLoc, depChairId); //create department object
  Departments.push_back(newDepartment); //add new department to departments vector
  return success;
}
//----------------------------------------------------------------------------

bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
  if(sMajor != "") //if student has chosen a major
    {
      if(!checkIfDepartmentExists(sMajor)) //check if sMajor is valid existing department name
	{
	  cout << "Student " << sName << " cannot be created: " << sMajor << " is not an existing department." << endl;
	  return failure;
	}
    }

  if(sAdvisorId !=0) //if student has choses an advisor
    {
      if(!checkIfFacultyExists(sAdvisorId)) //check if sAdvisorId is valid existing faculty
	{
	  cout << "Student " << sName << " cannot be created: Advisor ID " << sAdvisorId << " does not exist." << endl;
	  return failure;
	}
    }
  
  //create student object
  Student newStudent(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);
  Students.push_back(newStudent); ///add new student to students vector
  return success;
}
//----------------------------------------------------------------------------

bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
  if(cTaughtBy != 0) //if someone is assigned to teach this course
    {
      if(!checkIfFacultyExists(cTaughtBy)) //check if cTaughtBy is valid existing faculty
	{
	  cout << "Course " << cName << " cannot be created: Faculty ID " << cTaughtBy << " does not exist." << endl;
	  return failure;
	}
    }
  
  if(!checkIfDepartmentExists(cDepId)) //check if cDepId is valid existing department
    {
      cout << "Course " << cName << " cannot be created: Department ID " << cDepId << " does not exist." << endl;
      return failure;
    }
  
  Course newCourse(cName, cDepId, cTaughtBy, cMaxSeat); //create course object
  Courses.push_back(newCourse); //add new course to courses vector
  return success;
} 
//----------------------------------------------------------------------------
bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId)
{
  if(!checkIfDepartmentExists(fDepId)) //check if fDepId is valid existing department
    {
      cout << "Faculty " << fName << " cannot be created: Department ID " << fDepId << " does not exist." << endl;
      return failure;
    }
 
  Faculty newFaculty(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId); //create faculty object
  Faculties.push_back(newFaculty); //add new faculty to faculty vector
  return success;
}
//----------------------------------------------------------------------------

bool University::ListCoursesTaughtByFaculty(long facultyId)
{
  if(!checkIfFacultyExists(facultyId)) //check if facultyId is valid existing faculty
    {
      cout << "Cannot list courses taught by faculty: Faculty ID " << facultyId << " does not exist." << endl;
      return failure;
    }
  cout << "Courses taught by Faculty " << facultyId << ": " << endl;

  for(int i = 0; i < Courses.size(); i++) //go through courses vector
    {
      if(Courses[i].getIsTaughtBy() == facultyId) //if facutlyId matches
	{
	  cout << endl;
	  //print course id and course name
	  cout << "Course ID: " << Courses[i].getCRN() << endl;
	  cout << "Course Name: " << Courses[i].getName() << endl;
	}
    }
  return success;
}
//----------------------------------------------------------------------------

bool University::ListCoursesTakenByStudent(long studentId)
{
  if(!checkIfStudentExists(studentId)) //check if studentId is valid existing student
    {
      cout << "Cannot list courses taken by student: Student ID " << studentId << " does not exist." << endl;
      return failure;
    }
  
  cout << "Courses taken by Student " << studentId << ": " << endl;

  for(int i = 0; i < Students.size(); i++) //go through students vector
    {

      if(Students[i].getId() == studentId) //if studentId matches
	{
	  vector<Course> currentCourses = Students[i].getCoursesTaken(); //copy contents of vector coursesTaken
	  for(int j = 0; j < currentCourses.size(); j++) //step through student courses vector
	    {
	      cout << endl;
	      //print course id and course name
	      cout << "Course ID: " << currentCourses[j].getCRN() << endl; 
	      cout << "Course Name: " << currentCourses[j].getName() << endl;
	    }
	} //end if
    } //end for
  return success;
}
//----------------------------------------------------------------------------

bool University::ListFacultiesInDepartment (long departId)
{
  if(!checkIfDepartmentExists(departId)) //check if departId is valid existing department
    {
      cout << "Cannot list faculties: Department ID " << departId << " does not exist." << endl;
      return failure;
    }

  cout << "Faculties in Department " << departId << ": " << endl;

  for(int i = 0; i < Faculties.size(); i++) //go through faculties vector
    {
      if(Faculties[i].getDepId() == departId) //if departId matches
	{
	  cout << endl;
	  //print faculty id and name
	  cout << "Faculty ID: " << Faculties[i].getId() << endl;
	  cout << "Faculty Name: " << Faculties[i].getName() << endl;
	}
    }
  return success;
}
//----------------------------------------------------------------------------

bool University::ListStudentsOfAFaculty(long facultyId)
{
  if(!checkIfFacultyExists(facultyId)) //check if facultyId is valid existing faculty
    {
      cout << "Cannot list students: Faculty ID " << facultyId << " does not exist." << endl;
      return failure;
    }
 
  cout << "Students of Faculty " << facultyId << ": " << endl;
  
  for(int i = 0; i < Students.size(); i++) //go through students vector
    {
      {
	if(Students[i].getAdvisorId() == facultyId) //if course is taught by faculty
	  {
	    //print student id and name
	    cout << endl;
	    cout << "Student ID: " << Students[i].getId() << endl;
	    cout << "Student Name: " << Students[i].getName() << endl;
	  }
      } // end for
    } //end for

  return success;
}
//----------------------------------------------------------------------------

bool University::ListCoursesOfADepartment(long departId)
{
  if(!checkIfDepartmentExists(departId)) //check if departId is valid existing department
    {
      cout << "Cannot list courses: Department ID " << departId << " does not exist." << endl;
      return failure;
    }
  
  cout << "Courses offered by Department " << departId << ": " << endl;

  for(int i = 0; i < Courses.size(); i++) //go through courses vector
    {
      if(Courses[i].getDepartId() == departId) //if course department id matches
	{
	  cout << endl;
	  cout << "Course ID: " << Courses[i].getCRN() << endl;
	  cout << "Course Name: " << Courses[i].getName() << endl;
	}
    }

  return success;
}
//----------------------------------------------------------------------------

bool University::AddACourseForAStudent(long courseId, long stId)
{
  if(!checkIfCourseExists(courseId)) //check if courseId is valid existing course
    {
      cout << "Cannot add course: Course ID " << courseId << " does not exist." << endl;
      return failure;
    }

  if(!checkIfStudentExists(stId)) //check if stId is valid existing student
    {
      cout << "Cannot add course: Student ID " << stId << " does not exist." << endl;
      return failure;
    }

  int courseIndex;
  for(int h = 0; h < Courses.size(); h++) //go through courses vector
    {
      if(Courses[h].getCRN() == courseId) //if courseId matches
	{
	  courseIndex = h; //set courseIndex
	}
    }

  if((Courses[courseIndex].getMaxAvailableSeats() - Courses[courseIndex].getAssignedSeats()) < 1) //if not enough available seats
    {
      cout << "Cannot add course " << courseId << " for Student " << stId << ": not enough seats in class." << endl;
      return failure;
    }
  else
    {
      for(int i = 0; i < Students.size(); i++) //go through students vector
	{
	  if(Students[i].getId() == stId) //if stId matches
	    {
	      vector<Course> currentCourses = Students[i].getCoursesTaken(); //copy contents of vector coursesTaken
	      
	      for(int j = 0; j < currentCourses.size(); j++)
		{
		  if(currentCourses[j].getCRN() == Courses[courseIndex].getCRN()) //if courseId matches CRN already in coursesTaken
		    {
		      cout << "Cannot add course " << courseId << " for Student " << stId << ": Student already registered for course. " << endl;
		      return failure;
		    }
		}
	      currentCourses.push_back(Courses[courseIndex]); //insert course in vector copy
	      Students[i].setCoursesTaken(currentCourses); //set overridden vector as student coursesTaken  
	    } //end if
	} //end for
    } //end else

  return success;
} 
//----------------------------------------------------------------------------

bool University::AssignDepartmentChair(long facultyId, long departId)
{
  if(!checkIfFacultyExists(facultyId)) //check if facultyId is valid existing faculty
    {
      cout << "Cannot assign department chair: Faculty ID " << facultyId << " does not exist." << endl;
      return failure;
    }
  if(!checkIfDepartmentExists(departId)) //check if departId is valid existing faculty
    {
      cout << "Cannot assign department chair: Department ID " << departId << " does not exist." << endl;
      return failure;
    }
 
  for(int i = 0; i < Departments.size(); i++) //go through departments vector
    {
      if(Departments[i].getId() == departId) //if departId matches
	{
	  Departments[i].setChairId(facultyId); //assign facultyId as department chair
	}
    }
  return success;
}
//----------------------------------------------------------------------------

bool University::AssignInstructorToCourse (long facultyId, long courseId)
{
  if(!checkIfCourseExists(courseId)) //check if courseId is valid existing course
    {
      cout << "Cannot assign instructor to course: Course ID " << courseId << " does not exist." << endl;
      return failure; 
    }
  if(!checkIfFacultyExists(facultyId)) //check if facultyId is valid existing course
    {
      cout << "Cannot assign instructor to course: Faculty ID " << facultyId << " does not exist." << endl;
      return failure;
    }

  for(int i = 0; i < Courses.size(); i++) //go through courses vector
    {
      if(Courses[i].getCRN() == courseId) //if courseId matches
	{
	  Courses[i].setIsTaughtBy(facultyId);  //assign facultyId to course
	}
    }
  return success;
}
//----------------------------------------------------------------------------
bool University::ListDepartments()
{
  cout << "Listing Departments..." << endl;
  for(int i = 0; i < Departments.size(); i++)
    {
      cout << endl;
      cout << "Department ID: " << Departments[i].getId() << endl;
      cout << "Department Name: " << Departments[i].getName() << endl;
    }
  return success;
}
//----------------------------------------------------------------------------

bool University::ListStudents()
{
  cout << "Listing Students..." << endl;
  for(int i = 0; i < Students.size(); i++)
    {
      cout << endl;
      cout << "Student ID: " << Students[i].getId() << endl;
      cout << "Student Name: " << Students[i].getName() << endl; 
    }
  return success;
}
//----------------------------------------------------------------------------
bool University::ListCourses()
{
  cout << "Listing Courses..." << endl;
  for(int i = 0; i < Courses.size(); i++)
    {
      cout << endl;
      cout << "Course ID: " << Courses[i].getCRN() << endl;
      cout << "Course Name: " << Courses[i].getName() << endl;
    }
  return success;
}
//----------------------------------------------------------------------------
bool University::ListFaculties()
{
  cout << "Listing Faculties..." << endl;
  for(int i = 0; i < Faculties.size(); i++)
    {
      cout << endl;
      cout << "Faculty ID: " << Faculties[i].getId() << endl;
      cout << "Faculty Name: " << Faculties[i].getName() << endl;
    }
  return success;
}
//----------------------------------------------------------------------------
//this method processes the text file containing commands
bool University::ProcessTransactionFile (string fileName)
{
  ifstream fin;
  string command;

  long stId, facultyId, depId, depChairId, CRN, taughtBy, advisorId;
  string name, depLoc, email, address, dateOfBirth, gender, major;
  int maxSeat, yearOfStudy, yearOfExp;
  float salary;
   
  fin.open(fileName);

  if(fin)
    {
      while(fin >> command) //read command
	{
	  //depending on command, read in the next or next few data members 
	  //and call function accordingly.
	      
	  if(command == "CreateNewDepartment")
	    {
	      fin >> name >> depLoc >> depChairId;
	      if(CreateNewDepartment(name, depLoc, depChairId))
		cout << "Department " << name << " created." << endl;
	    }
	  if(command == "CreateNewStudent")
	    {
	      fin >> name >> email >> address >> dateOfBirth >> gender >> yearOfStudy >> major >>  advisorId;
	      if(CreateNewStudent(name, email, address, dateOfBirth, gender, yearOfStudy, major, advisorId))
		cout << "Student " << name << " created." << endl;
	    }
	  if(command == "CreateNewCourse")
	    {
	      fin >> name >> depId >> taughtBy >> maxSeat;
	      if(CreateNewCourse(name, depId, taughtBy, maxSeat))
		cout << "Course " << name << " created." << endl;
	    }
	  if(command == "CreateNewFaculty")
	    {
	      fin >> name >> email >> address >> dateOfBirth >> gender >> salary >> yearOfExp >> depId;
	      if(CreateNewFaculty(name, email, address, dateOfBirth, gender, salary, yearOfExp, depId))	
		cout << "Faculty " << name << " created." << endl;
	    }
	  if(command == "ListCoursesTaughtByFaculty")
	    {
	      fin >> facultyId;
	      ListCoursesTaughtByFaculty(facultyId);
	    }
	  if(command == "ListCoursesTakenByStudent")
	    {
	      fin >> stId;
	      ListCoursesTakenByStudent(stId);
	    }
	  if(command == "ListFacultiesInDepartment")
	    {
	      fin >> depId;
	      ListFacultiesInDepartment(depId);
	    }
	  if(command == "ListStudentsOfAFaculty")
	    {
	      fin >> facultyId;
	      ListStudentsOfAFaculty(facultyId);
	    }
	  if(command == "ListCoursesOfADepartment")
	    {
	      fin >> depId;
	      ListCoursesOfADepartment(depId);
	    }
	  if(command == "AddACourseForAStudent")
	    {
	      fin >> CRN >> stId;
	      if(AddACourseForAStudent(CRN, stId))
		cout << "Course " << CRN << " added for student: " << stId << endl;
	    }
	  if(command == "AssignDepartmentChair")
	    {
	      fin >> facultyId >> depId;
	      if(AssignDepartmentChair(facultyId, depId))
		cout << "Faculty " << facultyId << " assigned as Chair for Department: " << depId << endl;
	    }
	  if(command == "AssignInstructorToCourse")
	    {
	      fin >> facultyId >> CRN;
	      if(AssignInstructorToCourse(facultyId, CRN))
		cout << "Instructor " << facultyId << " assigned to course: " << CRN << endl;
	    }
	  if(command == "ListDepartments")
	    {
	      ListDepartments();
	    }
	  if(command == "ListStudents")
	    {
	      ListStudents();
	    }
	  if(command == "ListCourses")
	    {
	      ListCourses();
	    }
	  if(command == "ListFaculties")
	    {
	      ListFaculties();
	    }
	  cout << endl;
	}
    }
  else 
    {
      cout << "File \"" << fileName << "\" could not be opened." << endl;
      return failure;
    }
  return success;
  
}
//-------------------------------------------------------------------------
#endif //UNIVERSITY_CPP   

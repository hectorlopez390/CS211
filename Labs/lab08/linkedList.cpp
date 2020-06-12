//*******************************************************************************************
//Hector Lopez
//CS 211 - Lab 8
//This program creates a linked list of students. The program contains 4 functions for
//inserting into certain place in the linked list and functions for printing, removing, and 
//searching.
//*******************************************************************************************

#include <iostream>
#include<string>
#include<fstream>
using namespace std;

class Node;
typedef Node* NodePtr;

class LL;
class Node
{
  friend class LL;
private:
  int stId;
  string stName;
  string stEmail;
  int stAge;
  NodePtr nextStudent;
};

class LL
{
private:
  NodePtr  top;
  void destroy();

public:
  LL();
  LL(const LL& source);
  ~LL();
  void insertDataFromFile();
  void print();
  bool insertAfterFirst(int id, string name, string email, int age);
  bool insertBeforeFirst(int id, string name, string email, int age);
  bool insertAfterLast(int id, string name, string email, int age);
  bool insertBeforeLast(int id, string name, string email, int age);
  bool remove(int);
  bool search(int St_id);
};
//--------------------------------------------
//--------------------------------------------
// the default constructor
LL::LL()
{
  top = NULL;
}
//--------------------------------------------
//--------------------------------------------
// the copy constructor
LL::LL(const LL& L1)
{
  //preforms a deep copy of linked list L1 in order

  NodePtr curr = L1.top; //creates pointer for first student node
  destroy(); //free any storage used by target linked list

  while(curr != NULL) //while pointer does not point to null
    {
      //set student info
      insertAfterLast(curr -> stId, curr -> stName, curr -> stEmail, curr -> stAge); passes current student node info
      curr = curr -> nextStudent; //next student in linked list
    }
}

//--------------------------------------------
//--------------------------------------------
// the destructor
LL::~LL()
{
  destroy();
}

//--------------------------------------------
//--------------------------------------------
// Read a transaction file and insert the data into it
// after reading a set of data you can call any of the 
// insert functions to insert the node into the linked list 
void LL::insertDataFromFile()
{
  //declare student info variables
  int id, age;
  string name, email;

  ifstream fin;
  fin.open("transactionFile.txt"); //open transaction file

  if(fin)
    {
      cout << "Inserting data from file into linked list..." << endl;
      fin >> id >> name >> email >> age;
      while(!fin.eof()) //while not end of file, read 4 variables at a time
	{
	  insertAfterLast(id, name, email, age); //creates linked list of students in order of the transactionFile
	  fin >> id >> name >> email >> age; //reads next set of information
	}
    }
  
  else
    {
      cout << "Could not open file." << endl;
      exit(0);
    }
}
//--------------------------------------------
//--------------------------------------------
// search for a student with a specific student id
// return true if the student is found and return 
// false instead
bool LL::search(int St_id)
{
  cout << "Searching for Student ID: " << St_id << "..." << endl; 
  NodePtr curr = top; // create current pointer for first student

  while(curr != NULL) //while pointer curr does not point to null
    {
      if(curr -> stId == St_id) //if student is found, return true
	return true;
      
      else
	curr = curr -> nextStudent; //points to next student
    }

    return false;
}
//--------------------------------------------
//--------------------------------------------
void LL::print()
{
  NodePtr curr = top; //create current pointer for first student

  cout << "Printing linked list... " << endl;

  while(curr != NULL) //while pointer curr does not point to null
    {
      //print student info
      cout << "Student ID: " << curr -> stId << endl;
      cout << "Student Name: " << curr -> stName << endl;
      cout << "Student Email: " << curr -> stEmail << endl;
      cout << "Student Age " << curr -> stAge << endl;
      cout << endl;
      curr = curr -> nextStudent; //point to next student
    }
  cout << endl;
}

//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node after the first
// node in the linked list. Note that if the linked 
// list is empty, the new node that you plan to insert 
// becomes the only node in the linked list

bool LL::insertAfterFirst(int id, string name, string email, int age)
{
  NodePtr newStudent = new Node; //creates pointer for and a new student node

  //set new student info
  newStudent -> stId = id;
  newStudent -> stName = name;
  newStudent -> stEmail = email;
  newStudent -> stAge = age;

  if (top == NULL) //if list is empty
    {
      top = newStudent; //new student becomes first and only node
      newStudent -> nextStudent = NULL; //next student null since only node in linked list
    }
 
  else
    {
      NodePtr curr = top; //create current pointer for first student
      newStudent -> nextStudent = curr -> nextStudent; //new student's next student points to second student node
      curr -> nextStudent = newStudent; //first student's next student  points to new student
    }
  return true;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node before the first
// node in the linked list. Note that if the linked 
// list is empty, the new node that you plan to insert 
// becomes the only node in the linked list

bool LL::insertBeforeFirst(int id, string name, string email, int age)
{ 
  NodePtr newStudent = new Node; //creates pointer and a new student node

  //set new student info
  newStudent -> stId = id;
  newStudent -> stName = name;
  newStudent -> stEmail = email;
  newStudent -> stAge = age;

  if(top == NULL) //if list is empty
    {
      top = newStudent; //new student becomes first and only node
      newStudent -> nextStudent = NULL; //next student null since only node in linked list
    }
 
  else
    {
      NodePtr curr = top; //create current pointer for first student
      newStudent -> nextStudent = curr; //new student's next student points to first student
      top = newStudent; //new student becomes first student
    }

  return true;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node after the last
// node in the linked list. Note that if the linked 
// list is empty, the new node that you plan to insert 
// will becomes the only node in the linked list

bool LL::insertAfterLast(int id, string name, string email, int age)
{
  NodePtr newStudent = new Node; //creates pointer and a new student node

  //set new student info
  newStudent -> stId = id;
  newStudent -> stName = name;
  newStudent -> stEmail = email;
  newStudent -> stAge = age;

  if(top == NULL) //if list is empty
    {
      top = newStudent; //new student becomes first and only node
      newStudent -> nextStudent = NULL; //next student null since only node in linked list
    }

  else
    {

      NodePtr curr = top;

      while(curr -> nextStudent != NULL) //while nextStudent is not null
	{
	  curr = curr -> nextStudent; //move current pointer to next student
	}

      curr -> nextStudent = newStudent; //last node points to new student
      newStudent -> nextStudent = NULL; //new student's next student set to null
    }


  return true;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node before the last
// node in the linked list. Note that if the linked 
// list is empty, the new node that you plan to insert 
// becomes the only node in the linked list

bool LL::insertBeforeLast(int id, string name, string email, int age)
{
  NodePtr newStudent = new Node; //creates pointer and a new student node

  //set new student info
  newStudent -> stId = id;
  newStudent -> stName = name;
  newStudent -> stEmail = email;
  newStudent -> stAge = age;
  
  if(top == NULL) //if list is empty
    {
      top = newStudent; //new student becomes first and only node
      newStudent -> nextStudent = NULL; //next student null since only node in linked list
    }

  else
    {
      NodePtr curr = top; //create current pointer for first student

      while(curr -> nextStudent -> nextStudent != NULL) //double reference while nextStudent's next student is not null
	{
	  curr = curr -> nextStudent; //move current pointer to next student
	}

      newStudent -> nextStudent = curr -> nextStudent; // new student's next student  points to last node
      curr -> nextStudent = newStudent; //node before last node points to new student
    }

  return true;
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id
// if the id does not exist, you need to return false.

bool LL::remove(int id)
{
  cout << "Removing Student: " << id << " from linked list..." << endl;

  NodePtr curr = top; //create current pointer for first student
  NodePtr temp;; //create temporary node for student deletion
  while(curr != NULL) //while current pointer is not null
    {
      if(top -> stId == id) //if first student matches id
	{
	  temp = top;  //temp points to first student
	  top = top -> nextStudent; //top becomes next student
	  delete temp; //delete student node that matched id
	  return true;
	}

      else if(curr -> nextStudent -> stId == id) //double reference, if next student node matches id
	{
	  temp = curr -> nextStudent;  //temp points to next student
	  curr -> nextStudent = curr -> nextStudent -> nextStudent; //double reference current pointer points to  next student's next student
	  delete temp; //delete student node that matched id
	  return true;
	}
      else
	curr = curr -> nextStudent; //move current pointer to next student
    }

  return false; //studen id not found
}
//--------------------------------------------
//--------------------------------------------

// deallocate the nodes in a linked list
void LL::destroy()
{
  //deep delete linked list
  NodePtr temp, curr; //create temporary and current pointers

  curr = top; //current pointer points to first student node

  while(curr != NULL) //while current is not last node
    {
      temp = curr; //temp points to current node
      curr = curr -> nextStudent; //current node set to next student
      delete temp; //delete temporary node(was current node)
    }
  top = NULL;
}

//--------------------------------------------

int main()
{
  LL list1;
  list1.insertDataFromFile();
  list1.print();
  list1.insertAfterFirst(54321, "Jim", "jim@csusm.edu", 25);
  list1.insertBeforeFirst(54123, "Joe", "joe@csusm.edu", 35);
  list1.insertAfterLast(63421, "Adam", "adam@csusm.edu", 20);
  list1.insertBeforeLast(66641, "Nancy", "nancy@csusm.edu", 27);
  list1.print();

  bool  found = list1.search(12321);
  if (found)
    cout << "the record was found" << endl << endl;
  else
    cout << "the record was not found" << endl << endl;
  list1.remove(54321);
  list1.print();

  LL list2(list1);
  list2.print();
  return 0;

}
//--------------------------------------------

/*
Output:
MacBook-Pro-3:lab8 hector$ g++ linkedList.cpp
MacBook-Pro-3:lab8 hector$ ./a.out
Inserting data from file into linked list...
Printing linked list... 
Student ID: 76543
Student Name: Mary
Student Email: mary@csusm.edu
Student Age 19

Student ID: 98765
Student Name: Kathy
Student Email: kathy@csusm.edu
Student Age 30

Student ID: 16438
Student Name: Flora
Student Email: flora@csusm.edu
Student Age 25

Student ID: 43260
Student Name: Peter
Student Email: peter@csusm.edu
Student Age 29

Student ID: 87590
Student Name: Kim
Student Email: kim@csusm.edu
Student Age 31


Printing linked list... 
Student ID: 54123
Student Name: Joe
Student Email: joe@csusm.edu
Student Age 35

Student ID: 76543
Student Name: Mary
Student Email: mary@csusm.edu
Student Age 19

Student ID: 54321
Student Name: Jim
Student Email: jim@csusm.edu
Student Age 25

Student ID: 98765
Student Name: Kathy
Student Email: kathy@csusm.edu
Student Age 30

Student ID: 16438
Student Name: Flora
Student Email: flora@csusm.edu
Student Age 25

Student ID: 43260
Student Name: Peter
Student Email: peter@csusm.edu
Student Age 29

Student ID: 87590
Student Name: Kim
Student Email: kim@csusm.edu
Student Age 31

Student ID: 66641
Student Name: Nancy
Student Email: nancy@csusm.edu
Student Age 27

Student ID: 63421
Student Name: Adam
Student Email: adam@csusm.edu
Student Age 20


Searching for Student ID: 12321...
the record was not found

Removing Student: 54321 from linked list...
Printing linked list... 
Student ID: 54123
Student Name: Joe
Student Email: joe@csusm.edu
Student Age 35

Student ID: 76543
Student Name: Mary
Student Email: mary@csusm.edu
Student Age 19

Student ID: 98765
Student Name: Kathy
Student Email: kathy@csusm.edu
Student Age 30

Student ID: 16438
Student Name: Flora
Student Email: flora@csusm.edu
Student Age 25

Student ID: 43260
Student Name: Peter
Student Email: peter@csusm.edu
Student Age 29

Student ID: 87590
Student Name: Kim
Student Email: kim@csusm.edu
Student Age 31

Student ID: 66641
Student Name: Nancy
Student Email: nancy@csusm.edu
Student Age 27

Student ID: 63421
Student Name: Adam
Student Email: adam@csusm.edu
Student Age 20


Printing linked list... 
Student ID: 54123
Student Name: Joe
Student Email: joe@csusm.edu
Student Age 35

Student ID: 76543
Student Name: Mary
Student Email: mary@csusm.edu
Student Age 19

Student ID: 98765
Student Name: Kathy
Student Email: kathy@csusm.edu
Student Age 30

Student ID: 16438
Student Name: Flora
Student Email: flora@csusm.edu
Student Age 25

Student ID: 43260
Student Name: Peter
Student Email: peter@csusm.edu
Student Age 29

Student ID: 87590
Student Name: Kim
Student Email: kim@csusm.edu
Student Age 31

Student ID: 66641
Student Name: Nancy
Student Email: nancy@csusm.edu
Student Age 27

Student ID: 63421
Student Name: Adam
Student Email: adam@csusm.edu
Student Age 20



*/



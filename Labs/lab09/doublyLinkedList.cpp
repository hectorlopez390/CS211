//********************************************************************************************
// CS 211 - Lab 9
// *Hector Lopez
// This program creates a doubly linked list of students, with functions to modify the linked list,
// insert students in a specific place in the linked list, and search or print the linked list.The
// final linked list printed is a deep copy of the first linked list created.
//********************************************************************************************



#include <iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

class Node;
typedef Node* NodePtr;

class DLL;
class Node
{
  friend class DLL;
private:
  int stId;
  string stName;
  string stEmail;
  int stAge;
  NodePtr next;
  NodePtr prev;

};

class DLL
{
private:
  NodePtr  top;
  bool destroy();

public:
  DLL();
  DLL(const DLL& source);
  ~DLL();
  bool insertDataFromFile();
  void print();
  bool search(int id);
  bool insertOnTheTop(int id, string name, string email, int age);
  bool insertAtTheBottom(int id, string name, string email, int age);
  bool insertAfterTheFirstNode(int id, string name, string email, int age);
  bool insertBeforeTheLastNode(int id, string name, string email, int age);
  bool deleteFirstNode();
  bool deleteLastNode();
  bool deleteTheStudentWithId(int id);
};
//--------------------------------------------
//--------------------------------------------
// the default constructor
DLL::DLL()
{
  top = NULL;
}
//--------------------------------------------
//--------------------------------------------
// the copy constructor
DLL::DLL(const DLL& source)
{
  destroy(); //free any storage used by target linked list

  NodePtr atop = source.top; //set pointer equal to first student node for copy

  if(atop == NULL) // if doubly linked list is empty
    {
      return;
    }

  if(atop -> next == NULL) //if doubly linked list only contains one student node
    {
      //copy student info 
      top -> next = NULL;
      top -> prev = NULL;
      top -> stId = atop -> stId;
      top -> stName = atop -> stName;
      top -> stEmail = atop -> stEmail;
      top -> stAge = atop -> stAge;
    

      insertOnTheTop(atop -> stId, atop -> stName, atop -> stEmail, atop -> stAge); //insert first student node at top

      return;
    }
  
  NodePtr curr = atop; //create current pointer for first student node to copy

  while(curr != NULL) //while not end of linked list
    {  
      insertAtTheBottom(curr -> stId, curr -> stName, curr -> stEmail, curr -> stAge); //insert student node at bottom 
      curr = curr -> next; //move pointer to next student
    } //while not end of linked list
  
  return;
}

//--------------------------------------------
//--------------------------------------------
// the destructor
DLL::~DLL()
{
  destroy();
}

//--------------------------------------------
//--------------------------------------------
// Read a transaction file and insert the data into it
// after reading a set of data. Use insertOnTheTop function
// to insert the followingg into the doubly linked list

/*76543Marymary@csusm.edu19
  98765Kathykathy@csusm.edu30
  16438Floraflora@csusm.edu25
  43260Peterpeter@csusm.edu29
  87590kimkim@csusm.edu31
*/
bool DLL::insertDataFromFile()
{
  //declare variables to store information from file
  ifstream fin;
  int id, age;
  string name, email;

  cout << "Reading information from transactionFile.txt into linked list..." << endl;

  fin.open("transactionFile.txt");
  if(fin) //if file could be opened
    {
      fin >> id >> name >> email >> age; //read first set of information
      
      while(!fin.eof()) //create nodes until end of file
	{
	  insertAtTheBottom(id, name, email, age);
	  fin >> id >> name >> email >> age;
	}
    }

  else
    {
      cout << "Could not open file." << endl;
      return false;
    }

  return true;
}
//--------------------------------------------
//--------------------------------------------
// print the linked list
void DLL::print()
{
  NodePtr curr = top; //create pointer for first student node

  cout << "Printing linked list..." << endl;

  while(curr != NULL) //while not end of linked list
    {
      //print student info
      cout << "Student ID: " << curr -> stId << endl;
      cout << "Student Name: " << curr -> stName << endl;
      cout << "Student Email: " << curr -> stEmail << endl;
      cout << "Student Age: " << curr -> stAge << endl;
      curr = curr -> next; //move pointer to next student
      cout << endl;
    }
  cout << endl;
  return;
}
//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list
bool DLL::search(int id)
{
  NodePtr curr = top;

  while(curr != NULL)
    { 
      if(curr -> stId == id)
	return true;

      curr = curr -> next;
    }
  
  return false;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the DLL
bool DLL::insertOnTheTop(int id, string name, string email, int age)
{
  NodePtr newStudent = new Node;

  //set new student information
  newStudent -> stId = id;
  newStudent -> stName = name;
  newStudent -> stEmail = email;
  newStudent -> stAge = age;

  if(top == NULL) //if linked list is empty
    {
      top = newStudent; //new student becomes first and only student
      newStudent -> prev = NULL;
      newStudent -> next = NULL;
    }

  else
    {
      top -> prev = newStudent; 
      newStudent -> prev = NULL;
      newStudent -> next = top; //top becomes second student
      top = newStudent; //new student becomes first student
    }
  return true;
}
//--------------------------------------------
//--------------------------------------------
bool DLL::insertAtTheBottom(int id, string name, string email, int age)
{
  NodePtr newStudent = new Node; //create node for new student

  //set new student information
  newStudent -> stId = id;
  newStudent -> stName = name;
  newStudent -> stEmail = email;
  newStudent -> stAge = age;

  if(top == NULL) //if linked list is empty
    {
      top = newStudent; //set new student as first and only node in linked list
      newStudent -> prev = NULL;
      newStudent -> next = NULL;
    }

  else
    {
      NodePtr curr = top; //create pointer for first student

      while(curr -> next != NULL) //while pointer curr does not point to last student
	{
	  curr = curr -> next; //move to next student
	}
      curr -> next = newStudent; //place new student at the end of linked list
      newStudent -> prev = curr;
      newStudent -> next = NULL;
    }
  return true;
}
//--------------------------------------------
//--------------------------------------------
bool DLL::insertAfterTheFirstNode(int id, string name, string email, int age)
{
  NodePtr newStudent = new Node;

  //set new student information
  newStudent -> stId = id;
  newStudent -> stName = name;
  newStudent -> stEmail = email;
  newStudent -> stAge = age;

  if(top == NULL) //if linked list is empty
    {
      top = newStudent; //set new student as first and only node in linked list
      newStudent -> prev = NULL;
      newStudent -> next = NULL;
    }

  else
    {
      newStudent -> prev = top;
      newStudent -> next = top -> next;
      top -> next = newStudent; //insert new student after first student node
    }

  return true;
}
//--------------------------------------------
//--------------------------------------------
bool DLL::insertBeforeTheLastNode(int id, string name, string email, int age)
{
  NodePtr newStudent = new Node;

  //set new student information
  newStudent -> stId = id;
  newStudent -> stName = name;
  newStudent -> stEmail = email;
  newStudent -> stAge = age;

  if(top == NULL)
    {
      top = newStudent; //set new student as first and only node in linked list
      newStudent -> prev = NULL;
      newStudent -> next = NULL;
    }

  else
    {
      NodePtr curr = top; //create current pointer for first student

      while(curr -> next != NULL) // while not pointing to last node
	{
	  curr = curr -> next; //move pointer to next student
	}

      //allocate new student node
      newStudent -> next = curr; 
      newStudent -> prev = curr -> prev;
      curr -> prev -> next  = newStudent;
      curr -> prev = newStudent;
    }

  return true;
}
//--------------------------------------------
//--------------------------------------------
bool DLL::destroy()
{
  NodePtr curr = top; //create pointer for first student node
  NodePtr temp; //create temporary pointer for deletion

  while(curr != NULL)
    {
      temp = curr; //set temporary to current pointer
      curr = curr -> next; //delete current pointer
      delete temp; //delete temporary pointer
    }

  top = NULL;

  return true;
}
//--------------------------------------------
//--------------------------------------------
bool DLL::deleteFirstNode()
{
  if(top == NULL)
    {
      return true;
    }

  NodePtr temp = top; //create temporary pointer for deletion
  top = temp -> next; //top becomes second node
  top -> prev = NULL;
  delete temp; //delete first node

  return true;
}
//--------------------------------------------
//--------------------------------------------
bool DLL::deleteLastNode()
{
  if(top == NULL)
    {
      return true;
    }

  NodePtr curr = top; //create pointer for first student node
  NodePtr before, after; //create nodes for connection after deletion

  if(curr -> next != NULL) //if not pointing to last node in linked list
    {
      curr = curr -> next; //move pointer to next student node
    }

  //connect current prev and current next node
  before = curr -> prev; 
  after = curr -> next;
  before -> next = after;
  after -> prev = before;
 
  delete curr; //delete current node

  return true;
}
//--------------------------------------------
//--------------------------------------------
bool DLL::deleteTheStudentWithId(int id)
{

  cout << "Removing student: " << id << "..." << endl;

  NodePtr curr = top; //create pointer for first student node
  NodePtr before, after; //create nodes for connection after deletion



  while(curr != NULL) //while not end of linked list
    {
      if(top -> stId == id)
	{
	  curr = top;
	  top = top -> next;
	  delete curr;
	  return true;
	}

      else if(curr -> stId == id) //if student id matches current student node id
	{
	  //connect current prev and current next node
	  before = curr -> prev;
	  after = curr -> next;
	  before -> next = after;
	  after -> prev = before;

	  delete curr; //delete current node
	  return true;
	}
      curr = curr -> next;
    }

  return false;
}
//--------------------------------------------
//--------------------------------------------


int main()
{
  DLL list1;
  list1.insertDataFromFile();
  list1.print();
  list1.insertAfterTheFirstNode(54321, "Jim", "jim@csusm.edu", 25);
  list1.insertOnTheTop(54123, "Joe", "joe@csusm.edu", 35);
  list1.insertAtTheBottom(63421, "Adam", "adam@csusm.edu", 20);
  list1.insertBeforeTheLastNode(66641, "Nancy", "nancy@csusm.edu", 27);
  list1.print();
  bool  found = list1.search(12321);
  if (found)
    cout << "the record was found" << endl;
  else
    cout << "the record was not found" << endl;
  
  list1.deleteTheStudentWithId(54321);
  list1.print();

  DLL list2(list1);
  list2.print();
  return 0;
}
//--------------------------------------------

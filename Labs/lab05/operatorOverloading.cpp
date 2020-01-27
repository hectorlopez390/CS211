/**********************************************************************
Hector Lopez

This program uses the concept of operator overloading. Four functions
overload 4 operators to divide, subtract, multiply, input, and output
2 different objects. The objects in this program are matrices A and B
that are input from two user defined files.
**********************************************************************/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class TheMatrix;

// Function Prototype Section
TheMatrix operator/ (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix operator- (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix operator+ (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix operator* (const TheMatrix& M1, const TheMatrix& M2);
ifstream& operator>> (ifstream& is, TheMatrix& myMatrix); 
ostream& operator<< (ostream& is, const TheMatrix& myMatrix);

// End of prototype section

class TheMatrix
{
  //make stand alone functions friend of class
  friend TheMatrix  operator/ (const TheMatrix& M1, const TheMatrix& M2);
  friend TheMatrix  operator- (const TheMatrix& M1, const TheMatrix& M2);
  friend TheMatrix operator+ (const TheMatrix& M1, const TheMatrix& M2);
  friend TheMatrix operator* (const TheMatrix& M1, const TheMatrix& M2);
  friend ifstream& operator>> (ifstream& is, TheMatrix& myMatrix);
  friend ostream& operator<< (ostream& is, const TheMatrix& myMatrix);

public:
  int  M[5][5];// 5 by 5 matrix of integer
  
  TheMatrix();
  ~TheMatrix();
  
};

//------------------------------------------
// Deconstructor
TheMatrix::~TheMatrix()
{

}

//------------------------------------------
//Default Constructor
TheMatrix::TheMatrix()
{
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      M[i][j] = 0;
}

//------------------------------------------
// This routine asks the user to enter a file name and grab the
// data from there to place it into a matrix
// the matrix filled up with the data is returned
ifstream& operator>> (ifstream& is, TheMatrix& myMatrix) 
{
  string fileName;
  cout << "Enter a file name -> ";
  cin >> fileName;
  is.open(fileName.data());
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      is >> myMatrix.M[i][j];
  return is;
}

//------------------------------------------
// This routine prints the matrix to 
// the output stream (in this case screen). 
// This prints in a form of 5 rows by 5 columns  

ostream& operator<< (ostream& os, const TheMatrix& myMatrix) 
{
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      {
	static int count = 0; //counter for output indentation of 5x5 matrix

	if(count > 4)
	  {        
	    cout << endl;
	    count = 0;
	  }
	
	os << myMatrix.M[i][j] << " ";
	count ++;
      }
  cout << endl;
  return os;
}
//------------------------------------------
// This routine adds two matrices and creates a new matrix 
// of the addition of the two matrices M1 and M2
TheMatrix operator+ (const TheMatrix& M1, const TheMatrix& M2)
{
  TheMatrix Result;
  for (int i = 0; i < 5;i++)
    for (int j = 0; j< 5; j++)
      Result.M[i][j] = M1.M[i][j]+M2.M[i][j];
  return(Result);
}

//------------------------------------------
// This routine subtracts two matrices and creates a new matrix
// of the addition of the two matrices M1 and M2
TheMatrix  operator- (const TheMatrix& M1, const TheMatrix& M2)
{
  TheMatrix Result;
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      Result.M[i][j] = M1.M[i][j] - M2.M[i][j];
  return(Result);
}

//------------------------------------------
// This routine multiplies two matrices
TheMatrix  operator* (const TheMatrix& M1, const TheMatrix& M2)
{
  TheMatrix Result;
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      Result.M[i][j] = M1.M[i][j] * M2.M[i][j];
  return(Result);
}

//------------------------------------------
// The following routine divides two matrices
// sets the result value to zero if the division by zero occurs
TheMatrix  operator/ (const TheMatrix& M1, const TheMatrix& M2)
{
  TheMatrix Result;
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      {
	if(M2.M[j][j] == 0)
	  Result.M[i][j] = 0;
	else
	  Result.M[i][j] = M1.M[i][j] / M2.M[i][j];
      }
  return(Result);
}

//------------------------------------------

int main()
{
  TheMatrix A, B, AddAB, MulAB, SubAB, DivAB;
  ifstream fin1, fin2;

  fin1 >> A;  // This code calls the function operator>> to grab information from a file and place it into Matrix A  
  fin2 >> B;  // This code calls the function operator>> to grab information from a file and place it into Matrix B  
  
  AddAB = A + B; // call a function to operator+  to add Matrix A and B together and place the result into Matrix AddAB
  SubAB = A - B; // call a function to operator-  to subtract Matrix A from Matrix B  and place the result into Matrix SubAB
  MulAB = A * B; // call a function to operator*  to multiply Matrix A and B together and place the result into Matrix MulAB
  DivAB = A / B; // call a function to operator/  to divide Matrix A by matrix B and place the result into Matrix DivAB
  
  cout << "Matrix A: " << endl;
  cout << A << endl; // call the function operator<< to print matrix A
  cout << "Matrix B: ";
  cout << B << endl; // call the function operator<< to print matrix B
  cout << "A + B: ";
  cout << AddAB << endl; // call the function operator<< to print matrix AddAB
  cout << "A - B: ";
  cout << SubAB << endl; // call the function operator<< to print matrix SubAB
  cout << "A * B: ";
  cout << MulAB << endl; // call the function operator<< to print matrix MulAB
  cout << "A / B: ";
  cout << DivAB << endl; // call the function operator<< to print matrix DivAB
  
  return 0;
}

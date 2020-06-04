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

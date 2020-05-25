/**********************************************************************
Hector Lopez
This object-oriented program creates a dictionary by processing a 
transaction file that contains commands. The dictionary has 26 files
for each letter of the alphabet. 
**********************************************************************/

#ifndef MAIN_CPP
#define MAIN_CPP

#include "Dictionary.h"

int main()
{
  Dictionary DictForCS211;
  DictForCS211.ProcessTransactionFile();
  return 0;
}

#endif // MAIN_CPP

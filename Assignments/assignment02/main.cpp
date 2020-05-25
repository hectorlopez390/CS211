/**********************************************************************
Hector Lopez
This object-oriented program creates a dictionary by processing a 
transaction file that contains commands: Add word, Insert file to
dictionary, Print file, Delete word, Spell check file, and Search word. 
The dictionary has 26 files for each letter of the alphabet. 
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

/*
Output:
MacBook-Pro-3:assignment2 hector$ g++ main.cpp Dictionary.cpp
MacBook-Pro-3:assignment2 hector$ ./a.out
Enter a transaction file: transactionFile.txt
"student" added to dictionary.
"teacher" added to dictionary.
"cs211" added to dictionary.
Processing words from file "data.txt" to insert into Dictionary...
Words from file "data.txt" processed successfully.
Printing file S.txt in dictionary...
student systems successful suffer sufficiently 
semantics system static show second 
serializability support 
"student" deleted from dictionary.
"hello" added to dictionary.
Spell checking file "myEssay.txt"...
Spelling error. "concrrent" not found in dictionary.
Spelling error. "themeselves" not found in dictionary.
Spelling error. "diferent" not found in dictionary.
Spelling error. "wich" not found in dictionary.
Spelling error. "analyziz" not found in dictionary.
Spelling error. "enhanc" not found in dictionary.
Spelling error. "transactian" not found in dictionary.
Spelling error. "relatted" not found in dictionary.
Cannot delete "play" because word does not exist in dictionary.
Searching for "medical" in dictionary...
"medical" not found in dictionary.
Searching for "cs211" in dictionary...
"cs211" found in dictionary.
Printing file C.txt in dictionary...
cs211 current concurrency changes consistency 
computationally context correctness criterion conflict 
control 
Printing file H.txt in dictionary...
have has how histories hello 
Printing file T.txt in dictionary...
teacher to transaction that typically 
the transactions themselves this these 
than tractable third they 
*/

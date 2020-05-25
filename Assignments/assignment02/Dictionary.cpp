/*
This program file contains the implementation of the Dictionary Class
*/
#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP

#include <fstream>
#include "Dictionary.h"

bool SearchForWord(string);

bool Dictionary::failure = false;
bool Dictionary::success = true;

Dictionary::Dictionary(): maxWordsInDict(10000), maxWordsPerFile(100)
{
  // This routine sets the following values to the following attributes   
  totalWordsInDict = 0;
  for(int count = 0; count < 26; count++)
    {
      numOfWordsInFile[count] = 0;
    }
  //numOfWordsInFile[0] = 0 referring to A.txt                             
  //numOfWordsInFile[1] = 0 referring to B.txt                             

  //numOfWordsInFile[25] = 0 referring to Z.txt
}

//------------------------------------------------------------------
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords): maxWordsInDict(dictMaxWords), maxWordsPerFile(fileMaxWords)
{
  // This routine sets the following values to the following attributes
  totalWordsInDict = 0;  
  for(int count = 0; count < 26; count++)
    {
      numOfWordsInFile[count] = 0;
    }
  // numOfWordsInFile[0] = 0; //referring to A.txt                       
  // numOfWordsInFile[1] = 0; //referring to B.txt                              


  // numOfWordsInFile[25] = 0; //referring to Z.txt                 
                                                    

}

//------------------------------------------------------------------       
/* This routine opens the appropriate file and tries to add the 
   word passed to the function to the file.
*/
bool Dictionary:: AddAWord(string word)
{
  if(!SearchForWord(word)) //checks if word doesn't exist in dictionary
    {
      if(totalWordsInDict + 1 > maxWordsInDict)
	{
	  cout << "Cannot add word because max word in dictionary cannot be exceeded." << endl;
	  return(Dictionary::failure);
	}
      else
	{
	  string fileName = "#.txt"; //replaces the # sign with appropiate letter.
	  fileName[0] = toupper(word[0]); 

	  ofstream fout;
	  fout.open(fileName.data(), ios::app); //ios::app appends the word rather than overwrite it in file
	  word[0] = tolower(word[0]);
	  fout << word << endl;

	  char letter = fileName[0];
	  int letterNum = letter - 65; //converts ascii value into position of letter in alphabet

	  totalWordsInDict++;
	  numOfWordsInFile[letterNum]++;

	  return(Dictionary::success);
	}
    }
  else
    {
      cout << "Cannot add \"" << word << "\" because word already exists in dictionary." << endl;
      return(Dictionary::failure);
    }
}
//------------------------------------------------------------------
/* This routine opens the appropriate file where the word that you
   are looking for might be kept, places the words from the file in
   a vector, deletes the word if found, and places modified vector
   back into file.
*/
bool Dictionary::DeleteAWord(string word)
{
  if(SearchForWord(word)) //check if word exists in dictionary
    {
      string fileName = "#.txt"; //replaces the # sign with appropiate letter 
      fileName[0] = toupper(word[0]);
      vector<string> words;
      string currentWord;

      ifstream fin;
      ofstream fout;

      fin.open(fileName);

      while (fin >> currentWord) //read words from letter file into vector
	{
	  words.push_back(currentWord);
	}
      for(int index = 0; index < words.size(); index++)
	{
	  if(words[index] == word)
	    {
	      words.erase(words.begin()+index); 
	    }
	}

      fout.open(fileName.data(), ios::trunc); //ios::trunc overwrites file
      for(int index = 0; index < words.size(); index++)
	{
	  fout << words[index] << endl;
	}
      char letter = fileName[0];
      int letterNum = letter - 65; //converts ascii value into position of letter in alphabet            

      totalWordsInDict--;
      numOfWordsInFile[letterNum]--;

      cout << "\"" << word << "\" deleted from dictionary." << endl;
      return(Dictionary::success);
    }
  else
    {
      cout << "Cannot delete \"" << word << "\" because word does not exist in dictionary." << endl;
      return(Dictionary::failure);
    }
}
//------------------------------------------------------------------
/*
This routine opens the appropiate file where the word that you are looking
for might be kept. If the word cannot be found in the appropiate file, this
routine returns failure. Otherwise if the word does exist in the appropiate 
file, it returns success.
*/
bool Dictionary::SearchForWord(string word)
{
  string fileName = "#.txt";
  fileName[0] = toupper(word[0]);
  vector<string> words;
  string currentWord;

  ifstream fin;
  
  fin.open(fileName.data());

  while(fin >> currentWord) //read words from file into vector 
    {
      words.push_back(currentWord);
    }
  for(int index = 0; index < words.size(); index++) //loop steps through vector
    {
      if(words[index] == word)
	{
	  return(Dictionary::success); //word found 
	}
    }
  return(Dictionary::failure); //word not found
}

//------------------------------------------------------------------
/* This routine opens the file fileName, read the words one by one and
   prints them on the screen. Only prints 5 words per line.
 */
bool Dictionary::PrintAFileInDict(string filename)
{
  int count = 0;
  ifstream fin;
  fin.open(filename.data());

  vector<string> words;
  string currentWord;

  if(fin)
    {
      cout << "Printing file " << filename << " in dictionary..." << endl;
      while(fin >> currentWord) //read words into vector until end of dictionary file
	{
	 
	  if(count > 4) //prints 5 words per line
	    {
	      cout << endl;
	      count = 0;
	    }
	  cout << currentWord << " "; //output words contained in dictionary file
	  count ++;
	}
      cout << endl;
      return(Dictionary::success);
    }
  else
    {
      cout << "File \"" << filename << "\" could not be opened, it does not exist." << endl;
      return(Dictionary::failure);
    }
}
//------------------------------------------------------------------
/* This routine opens the file fileName, read the words one by one 
and does the spell checking of the words. Every word is seached and 
those that are not in the dictionary are reported on the screen
*/
bool Dictionary::SpellChecking(string fileName)
{
  ifstream fin;
  fin.open(fileName.data());

  string currentWord;

  if(fin)
    {
      cout << "Spell checking file \"" << fileName << "\"..." << endl;

      while(fin >> currentWord)
	{
	  for(int i = 0; i < currentWord.length(); i++) //turns word to lowercase
            {
              currentWord[i] = tolower(currentWord[i]);
            }

	  if(!SearchForWord(currentWord)) //if word is not found in dictionary
	    {
	      cout << "Spelling error. \"" << currentWord << "\" not found in dictionary." << endl;
	    }
	}
      return(Dictionary::success);
    }
  else
    {
      cout << "File \"" << fileName << "\" could not be opened, it does not exist." << endl;
      return(Dictionary::failure);
    }
}
//------------------------------------------------------------------
/* This routine opens the file fileName, read the words one by one 
   and try to insert them into the dictionary. 
*/
bool Dictionary::InsertWordsIntoDict(string fileName)
{
  ifstream fin;
  fin.open(fileName.data());

  cout << "Processing words from file \"" << fileName << "\" to insert into Dictionary..." << endl;
  
  if(fin)
    {
      string currentWord;
      
      while(fin >> currentWord)
	{
	  for(int i = 0; i < currentWord.length(); i++) //turns word to lowercase
	    {
	      currentWord[i] = tolower(currentWord[i]);
	    }
	  if(!SearchForWord(currentWord)) //if word is not found in dictionary
	    AddAWord(currentWord); //insert word in dictionary
	}
      cout << "Words from file \"" << fileName << "\" processed successfully." << endl;
      return(Dictionary::success);
    }
  else
    {
      cout << "File \"" << fileName << "\" could not be opened, it does not exist." << endl;
      return(Dictionary::failure);
    }
}
//------------------------------------------------------------------
/* In this routine, asks the user to enter a transaction 
   file. A transaction file has two information per line. The first 
   information is a command telling the programmer what to do. The second 
   information is the data associated with the command
*/
void Dictionary::ProcessTransactionFile()
{
  ifstream fin;
  string transactionFile;
  string command;
  string data;


  cout << "Enter a transaction file: ";
  cin >> transactionFile;

  fin.open(transactionFile.data());

  if(fin)
    {
      while(fin >> command >> data) //reads two peaces of information
	{
	  if(command == "AddW")
	    {
	      if(AddAWord(data))
		cout << "\"" << data << "\" added to dictionary." << endl;
	    }
	  if(command == "DeleteW")
	    DeleteAWord(data);
	  if(command == "SearchW")
	    {
	      cout << "Searching for \"" << data << "\" in dictionary..." << endl;
	      if(SearchForWord(data))
		cout << "\"" << data << "\" found in dictionary." << endl;
	      else
		cout << "\"" << data << "\" not found in dictionary." << endl;
	    }
	  if(command == "PrintF")
	    PrintAFileInDict(data);
	  if(command == "SpellCheck")
	    SpellChecking(data);
	  if(command == "InsertF")
	    InsertWordsIntoDict(data);
	}
    }
  else
    {
      cout << "Transaction file does not exist. Please try again." << endl;
      exit(0);
    }
}

#endif //DICTIONARY_CPP

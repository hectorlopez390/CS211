/******************************************************
Hector Lopez

This program allows a user to encrypt a text file using
either ROT encryption method or cryptogram encryption 
method. The program also allows the user to decrypt a 
text file using the same methods. Encryptions and 
decryptions are saved to text files.
*******************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class EncryptDecrypt //class for encyption and decryption
{
private:
  string fileAsString; //string stores text from file
  vector<string> fileAsVector; //vector stores files being opened and read
public:
  EncryptDecrypt(){}; 

  string copyToString(string filename); //method to open key file and copy contents to a string
  vector<string> fileToVector(string filename); //method to open file and copy contents to vector
  void vectorToFile(const vector<string>& V, string filename); //method to copy vector to a file
  void displayVector(const vector<string>& V); //method for displaying a vector
  void encryptROT(); //encrypts data using ROT method
  void decryptROT(); //decrypts data using ROT method
  void encryptCryptogram(); //encrypts data using cryptogram method
  void decryptCryptogram(); //decrypts data using cryptogram method
};

//method implementation
string EncryptDecrypt::copyToString(string filename) 
{
 ifstream fin;
  
 fin.open(filename); //open input file using parameter filename

  if(!fin)
    {
      cout << endl;
      cout << "The file could not be opened. Try again." << endl;
      exit(1);
    }
  else
    {
      while(!fin.eof()) //data saved to string fileAsString until end of file
	fileAsString.push_back(fin.get()); 
      fin.close();
	
    }
  return fileAsString;
}

vector<string> EncryptDecrypt::fileToVector(string filename)
{
  ifstream fin;
  string word;

  fin.open(filename); //open input file using parameter filename
  if(!fin)
    {
      cout << endl;
      cout << "The file could not be opened. Try again." << endl;
      exit(1);
    }
  else
    {
      while(fin>>word) //data saved to vector fileAsVector until end of file
	fileAsVector.push_back(word); 
      fin.close();
    }
  return fileAsVector;
}

void EncryptDecrypt::vectorToFile(const vector<string>& V, string filename)
{
  ofstream fout;

  fout.open(filename); //open output file using parameter filename
  
  if(!fout)
    {
      cout << endl;
      cout << "The file could not be opened. Try again." << endl;
      exit(1);
    }
  else
    {
      for(int i = 0; i < V.size(); i++)  
	fout << V[i] << " "; //data from vector is saved to ouput file until end of vector
      fout.close();
    }
  return;
}

void EncryptDecrypt::displayVector(const vector<string>& V)
{
  for(int i = 0; i < V.size(); i++) //output vector V for confirmation
    {
      cout << V[i] << " ";
    }
  cout << endl;
}

void EncryptDecrypt::encryptROT() //encrypt using ROT method
{
  int rot = 0; //declare rot variable
  string filename = "Original.txt"; //file of original text
  string saveFile = "EncryptRot.txt"; //file encrypted text will be saved to

  vector<string> V = fileToVector(filename); //loads original text file into vector V
  vector<string> encrypted; //declare vector to store encrypted text

  cout << "Enter encryption key number for ROT: ";
  cin >> rot;
  cout << endl;

  //loop to read single element in vector V and store in string word
  for(int i = 0; i < V.size(); i++) 
    {
      string word = V[i];

      for(int j = 0; j < word.length(); j++) //loop to read single element in string word and store in int letter
	{
	  word[j] = tolower(word[j]); //turns single character element in string word to lowercase

	  int letter = word[j];

	  if(letter > 96 && letter < 123) //if lowercase letter
	    {
	      letter = letter + rot; //alphabet letter rotated to the left by rot number

	      if(letter > 122) //if letter surpasses z, begin at a
		word[j] = letter - 26; 

	      else
		word[j] = letter;
	    }
	
	  else //else not lower case letter (symbols)
	    word[j] = letter;
	}
      string encWord = word;
      encrypted.push_back(encWord); //store encrypted word in vector encrypted
    }

  vectorToFile(encrypted, saveFile); //save vector encrypted to file "EncryptRot.txt"
  displayVector(encrypted); //output vector encrypted for confirmation

  cout << endl << "Encryption comlpeted..." << endl;
  return;
}

void EncryptDecrypt::decryptROT() //decrypt using ROT method
{
  int rot = 0; //declare rot variable
  string filename = "EncryptRot.txt"; //file of ROT encrypted text
  string saveFile = "DecryptRot.txt"; //file decrypted text will be saved to

  vector<string> V = fileToVector(filename); //loads ROT encrypted text into vector V
  vector<string> decrypted; //declare vector to store decrypted text

  cout << "Enter encryption key number for ROT: ";
  cin >> rot;
  cout << endl;

  //loop to read single element in vector V and store in string word
  for(int i = 0; i < V.size(); i++) 
    {
      string word = V[i];

      for(int j = 0; j < word.length(); j++) //loop to read single element in string word and store in int letter
	{
	  int letter = word[j];

	  if(letter > 96 && letter < 123) //if lowercase letter
	    {
	      letter = letter - rot; //alphabet letter rotated back to the right by rot number

	      if(letter < 97) //if letter surpasses a begin at z
		word[j] = letter + 26;
	      else
		word[j] = letter;
	    }
	  else //else not lowercase letter (symbols)
	    word[j] = letter;
	}
      string decWord = word;
      decrypted.push_back(decWord); //store decrypted word in vector decrypted
    } 
  vectorToFile(decrypted, saveFile); //save vector decrypted to file "DecryptRot.txt"
  displayVector(decrypted); //output vector decrypted for confirmation

  cout << endl << "Decryption completed..." << endl;
}

void EncryptDecrypt::encryptCryptogram()
{
  string filename = "Original.txt"; //file of original text
  string keyFile = "CryptoKey.txt"; //string holds cryptogram 
  string saveFile = "EncryptCrypto.txt"; //file encrypted text will be saved to

  string key = copyToString(keyFile); //loads cryptogram into string
  vector<string> V = fileToVector(filename); //loads original text into vector V
  vector<string> encrypted; //declare vector to store encrypted text

  cout << endl;

  //loop to read single element in vector V and store in string word
  for(int i = 0; i < V.size(); i++)
    {
      string word = V[i]; 

      for(int j = 0; j < word.length(); j++) //loop to read single element in string word and store in int letter
	{
	  word[j] = tolower(word[j]); //turns single character element in string word to lowercase

	  int letter = word[j];

	  if(letter > 96 && letter < 123) // if lowercase letter
	    word[j] = key[letter - 97]; //replace element in string word with element from cryptogram
	    
	  else //else not lowercase letter (symbols)
	    word[j] = letter; 
	}
      string encWord = word;
      encrypted.push_back(encWord); //store encrypted word in vector encrypted
    }
  vectorToFile(encrypted, saveFile); //save encrypted vector to file "EncryptCrypto.txt"
  displayVector(encrypted); //display vector encrypted for confirmation

  cout << endl << "Encryption completed..." << endl;
  return;
}

void EncryptDecrypt::decryptCryptogram()
{
  string filename = "EncryptCrypto.txt"; //file of encrypted text
  string keyFile = "CryptoKey.txt"; //string holds cryptogram
  string saveFile = "DecryptCrypto.txt"; //file decrypted text will be saved to

  string key = copyToString(keyFile); //loads cryptogram into string
  vector<string> V = fileToVector(filename); //loads encrypted text into vector V
  vector<string> decrypted; //declares vector to store decrypted text

  cout << endl;

  //loop to read single element in vector V and store in string word 
  for(int i = 0; i < V.size(); i++) 
    {
      string word = V[i];

      for(int j = 0; j < word.length(); j++) ////loop to read single element in string word and store in int letter
	{
	  int letter = word[j]; 

	  if(letter > 96 && letter < 123) // if lowercase letter
	    {
	      for(int k = 0; k < key.length(); k++) //loop to read single element in cryptogram
		{
		  if (key[k] == letter) //if letter in cryptogram equals letter
		    word[j] = k + 97; //replace element in string word with original alphabet character
		}
	    }
	  else //else not lowercase letter (symbols)
	    word[j]= letter;
	}
      string decWord = word;
      decrypted.push_back(decWord); //store decrypted word in vector decrypted
    }
  vectorToFile(decrypted, saveFile); //save decrypted vector to file "DecryptCrypto.txt"
  displayVector(decrypted); //display vector decrypted for confirmation
                                                                                                        
  cout << endl << "Decryption completed..." << endl;
  return;
}

//declare functions
void menu();
void encryptMenu();
void decryptMenu();

int main()
{
  menu(); //begin menu loop
  cout << "\nGoodbye.\n" << endl;
  return 0;
}

void menu()
{
  bool exit = false; //variable for exiting program
  int choice = 0; //initialize variable for user input

  while(exit == false) //loop for menu selection
    {
      //user options
      cout << endl;
      cout << "1. Encrypt Data" << endl;              
      cout << "2. Decrypt Data" << endl;
      cout << "3. Exit" << endl;
      cout<< "Select a choice.(1, 2, or 3): ";
      cin >> choice; //user input
      
      switch(choice) //switch for encryption or decryption
	{
	case 1: //encryption
	  {
	    encryptMenu(); 
	    break;
	  }
	case 2: //decryption
	  {
	    decryptMenu();
	    break;
	  }
	case 3: //exit program 
	  {
	    exit = true;
	    break;
	  }
	default: //display error message if integer is not entered
	  {
	    cout << "Invalid choice. Try again." << endl;
	    break;
	  }
	}
    }
  return;
}

void encryptMenu() //submenu for encyption
{
  EncryptDecrypt Encrypt;//instantiate an object for encryption
  int choice = 0; //initialize variable for user input

  //user options
  cout << endl;
  cout << "1. Encrypt using ROT method" << endl;    
  cout << "2. Encrypt using cryptogram" << endl;
  cout << "3. Cancel" << endl;
  cout<< "Select a choice.(1, 2, or 3): ";
  cin >> choice; //user input   

  switch(choice) //switch for type of encryption                                                                                                                                
    {
    case 1: //function call for encryption using ROT method 
      {
	Encrypt.encryptROT();
	break;
      }
    case 2: //function call for encryption using cryptogram method                        
      {
	Encrypt.encryptCryptogram();
	break;
      }
    case 3: //Cancel out of encryption menu                                                                              
      {
	break;
      }
    default: //display error message if integer is not entered
      {
	cout << "Invalid choice. Try again." << endl;
	break;
      }
    }
  return;
}

void decryptMenu() //submenu for decryption
{
  EncryptDecrypt Decrypt; //instantiate an object
  int choice = 0;

  //user options
  cout << endl;
  cout << "1. Decrypt using ROT method" << endl;    
  cout << "2. Decrypt using cryptogram" << endl;
  cout << "3. Cancel" << endl;
  cout<< "Select a choice.(1, 2, or 3): ";
  cin >> choice; //user input 

  switch(choice) //switch for type of decryption                                                                                                                                    
    {
    case 1: //function call for decryption using ROT method        
      {
        Decrypt.decryptROT();
        break;
      }
    case 2: //function call for decryption using cryptogram method      
      {
        Decrypt.decryptCryptogram();                                                                                                                                         
	break;
      }
    case 3: //cancel out of menu                                                                                                             
      {
        break;
      }
    default: //display error message if integer is not entered
      {
        cout << "Invalid choice. Try again." << endl;
        break;
      }
    }
  return;
}

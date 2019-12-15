/*****************************************************************
Hector Lopez

This program uses the concept of vector and string 
to process a transaction file with commands for inserting
a word into a position in the vector, deleting a word from
a position in the vector, and printing the vector and vector size. 
*****************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

void print(vector<string>);
void insert(vector<string>&, string, int);
void remove(vector<string>&, int);

int main()
{
  vector<string> V;
  string command, word;
  int index;
  fstream fin;

  fin.open("data.txt");

  fin >> command;

  while(!fin.eof())
    {
      
      if(command == "Print")
	{
	  print(V);
	}
      else if
	(command == "Insert")
	{
	  fin >> word >> index;
	  insert(V, word, index);
	}
      else 
	{
	  fin >> index;
	  remove(V, index);
	}

      cout << "Size of Vector:" << V.size() << endl;

      fin >> command;
    }
  return 0;
}

void print(vector<string> V)
{
  cout << "Printing.." << endl;
  for(int i = 0; i < V.size(); i++)
    {
      cout << V[i] << " ";
    }
  cout << endl;
}

void insert(vector<string>& V, string word, int index)
{
  if(index > V.size())
    cout << "Insert not possible, position is beyond the size of the vector." << endl;
  else
    {
      V.insert(V.begin()+index, word);
      cout << "Inserting..." << endl;
    }
}

void remove(vector<string>& V, int index)
{
  if(index > V.size())
    cout << "Delete not possible, position is beyond the size of the vector." << endl;
  else
    {
      cout << "Deleteting..." << endl;
      V.erase(V.begin()+index);
    }
}

/**********************************************************************
Hector Lopez
This recursive program finds out if num is a FIbonacci number or not
using 30 fibonacci numbers
**********************************************************************/

#include <iostream> 
using namespace std;

int fib(int num)
{
  if(num <= 1)
    return num;
  
  else 
    return (fib(num - 1) + fib(num - 2));
}

bool fibResult(int num)
{

  for(int i = 0; i < 30; i++) //compares to first 30 fibonacci numbers
    {
      if(num == fib(i))  //if number matches fibonacci sequence
	return true;
    }
  
  return false;
}


int main()
{
  int num = 0;

  while(num >=0)
    {
      cout << "Enter a number(enter a negative number to quit): ";
      cin >> num;

      if(fibResult(num))
	{
	  cout << "Yes, you got it, " << num << " is a Fibonacci number" << endl;
	}
      else
	{
	  if(num > 0)
	    cout << "!!!!! Sorry " << num << " is not a Fibonacci number" << endl;
	}
    }
  cout << "(*Thanks - Have a good Day*)" << endl;

  return 0;
}

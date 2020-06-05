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

/*
Output: 

MacBook-Pro-3:lab7 hector$ g++ fibonacciNumber.cpp
MacBook-Pro-3:lab7 hector$ ./a.out
Enter a number(enter a negative number to quit): 14
!!!!! Sorry 14 is not a Fibonacci number
Enter a number(enter a negative number to quit): 13
Yes, you got it, 13 is a Fibonacci number
Enter a number(enter a negative number to quit): 22
!!!!! Sorry 22 is not a Fibonacci number
Enter a number(enter a negative number to quit): 23
!!!!! Sorry 23 is not a Fibonacci number
Enter a number(enter a negative number to quit): 21
Yes, you got it, 21 is a Fibonacci number
Enter a number(enter a negative number to quit): -1
(*Thanks - Have a good Day*)

*/

/**********************************************************************
Hector Lopez 
This program uses a recursive function gcd that returns the greatest 
common divisor of x and y.                                  
**********************************************************************/
#include <iostream>
using namespace std;

int gcd(int x, int y)
{
  if(y == 0)
    return x;
  else
    return gcd(y, x%y);
}

int main()
{

  int x, y;

  cout << "Enter two numbers separated by a space to find their greatest common divisor: ";

  cin >> x >> y;
  cout << endl;

  cout << "Greatest Common Divisor of " << x << " and " << y << " : " << gcd(x,y);
  cout << endl;
  return 0;
}

#include <iostream>
using namespace std;

int main()
{
  int number;
  int factorial = 1;
  cout << "Enter your number: "<< endl;
  cin >> number;
  for (int i = 1; i <= number; i++)
  {
    factorial = factorial*i;



  }
  cout << number << " factorial is "<< factorial << endl;

}

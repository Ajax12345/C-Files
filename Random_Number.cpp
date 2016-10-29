#include <iostream>
using namespace std;
int james(int b, int a);
int main()
{
  while (true)
  {
  int number1, number2, random;
  char ans;
  cout << "Enter your numbers :" << endl;
  cin >> number1 >> number2;
  random = james(number2, number1);
  cout << "Your random number in the range "<< number1 << ", "<< number2 << " is "<< random << endl;
  cout << "Do you want to play again? "<< endl;
  cin >> ans;
  if (ans == 'y' || ans == 'Y')
  {
    continue;
  }
  else
  {
    break;
  }

  }
  cout << "Thank you for playing!" << endl;
}

int james(int b, int a)
{

  int random_number = rand() % b + a;
  return random_number;
}

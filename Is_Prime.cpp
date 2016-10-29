#include <iostream>
using namespace std;

int main()
{
  int x;
  char ans;
  while (true)
  {
    cout << "Enter your number: "<< endl;
    cin >> x;
    if (x == 0 || x == 1)
    {
      cout << x << " is neither prime nor composite"<< endl;
    }
    else if (x > 1)
    {
      for (int i = 2; i < x; i++)
      {
        if (x%i == 0)
        {
          cout << x << "is not prime" << endl;
          break;
        }
        else if (x%i != 0)
        {
          cout << x << "is prime" << endl;
          break;
        }
      }
    }
    cout << "Do you want to play again?" << endl;
    cin >> ans;
    if (ans == 'y')
    {
      continue;
    }
    else
    {
      cout << "Thank you for playing"<< endl;
      break;
    }

  }
}

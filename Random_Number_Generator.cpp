#include <iostream>
void james();
using namespace std;

int main()
{
  james();
}

void james()
{
  int random;
  random = rand() % 10 + 1;

  while (true)
  {
    int guess;
    cout << "Enter your guess: "<< endl;
    cin >> guess;
    if (guess == random)
    {
    cout << "Correct!!!"<< endl;
    break;
    }
    else
    {
      cout << "try again!!"<< endl;
    }

  }
}

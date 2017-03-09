#include <iostream>
#include <fstream>
#include <cmath>
/*
This is the alternative version of the Archery Problem using just for loops. It calculates the same score as the project using arrays
*/
using namespace std;

int main()
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(5);
  ifstream input;
  input.open("scores.txt");
  double distance;
  int archer_score = 0, best_archer = 0;
  double a, b;
  for (int i = 0; i < 4; i ++)
  {
    int archer_so_far = 0;
    for (int c = 0; c < 10; c++)
    {
      input >> a >> b;


      distance = sqrt(pow(a, 2)+pow(b, 2));
      cout << distance<< endl;

      if (distance <= 0.5)
      {
        archer_so_far += 2;


      }
      else if (distance > 0.5 && distance <= 1)
      {
        archer_so_far += 1;

      }

    }

    cout << "so far, the score is "<< archer_so_far<< endl;

    if (archer_so_far > archer_score)
    {
      archer_score = archer_so_far;
      best_archer = i+1;
    }

    archer_so_far = 0;
  }

  cout << "The best score is "<<archer_score<< " and the best archer is "<< best_archer<< endl;

  input.close();
}

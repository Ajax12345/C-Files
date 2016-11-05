//This program calculates the mean, min, max, and standard deviation of a set of data
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int N, set = 0, max = 0, maximum, min = 10, minimum, range;
  double average, ssdev = 0;
  double standard_deviation;
  cout << "Enter your number of numbers: ";
  cin >> N;
  int setofnumbers[N]; //this loop allows users to enter their list of data
  for (int i = 0; i < N-1; i++)
  {
    cout << "Enter your number: ";
    cin >> setofnumbers[i];

  }

  for (int i = 0; i < N-1; i++) //this loop calculates the average
  {
    set = setofnumbers[i] + set;

  }
  average = (double)set/(double)N; //average calculator


  for (int i = 0; i < N-1; i++) //this loop calculates the standard deviation
  {
    ssdev = pow(((double)setofnumbers[i]-average), 2.0) + ssdev;
  }
  standard_deviation = pow((ssdev/((double)N-1)), 0.50);

  for (int i = 0; i < N-1; i++) //this loop finds the maximum number of the data set
  {
    if (setofnumbers[i] > max)
    {
      max = setofnumbers[i];

    }
  }
    maximum = max;

    for (int i = 0; i < N - 1; i++) //this loop finds the minimum number in the data set
    {
      if (setofnumbers[i] < min)
      {
        min = setofnumbers[i];

      }

    }
    minimum = min;

    range = maximum - minimum;

    cout << "Mean: "<< average << endl;
    cout << "Max: "<< maximum << endl;
    cout << "Min: "<< minimum << endl;
    cout << "Range: "<< range << endl;
    cout << "Standard Deviation: "<< standard_deviation << endl;

}

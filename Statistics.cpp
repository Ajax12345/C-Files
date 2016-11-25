//This program calculates the mean, min, max, and standard deviation of a set of data
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
  ifstream inputfile;
  int set = 0, max = 0, maximum, min = 10, minimum, range, count = 0, counter = 0, number, numberofnumbers;
  double average, ssdev = 0;
  double standard_deviation;
  cout << "Please enter the number of numbers in your data file: "<< endl;
  cin >> numberofnumbers;

  if (inputfile.fail())
  {
    cout << "Failure to open";
    exit(1);
  }

  inputfile.open("/Users/davidjpetullo/Documents/Final_Output.txt");


  int setofnumbers[numberofnumbers];
  while(!inputfile.eof())
  {
    inputfile >> setofnumbers[count];
    count++;
  }
  count = count - 1;

  for (int i = 0; i < count; i++) //this loop calculates the average
  {
    set = setofnumbers[i] + set;


  }

  average = (double)set/(double)count; //average calculator


  for (int i = 0; i < count-1; i++) //this loop calculates the standard deviation
  {
    ssdev = pow(((double)setofnumbers[i]-average), 2.0) + ssdev;
  }
  standard_deviation = pow((ssdev/((double)count-1)), 0.50);

  for (int i = 0; i < count-1; i++) //this loop finds the maximum number of the data set
  {
    if (setofnumbers[i] > max)
    {
      max = setofnumbers[i];

    }
  }
  maximum = max;

  for (int i = 0; i < count - 1; i++) //this loop finds the minimum number in the data set
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

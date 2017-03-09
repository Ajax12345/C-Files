/James Petullo
//Dr. Joyce Brown
//Assignment 6
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double CalcAve2(int nbr, int& sum2, int& kount2)
{

   sum2 = sum2 + nbr;
   kount2++;
   double average = (double)sum2/(double)kount2;
   return average;

}

  int main()
  {
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(3);
  fstream in_stream;
  int count2 = 0, number, result = 0, count = 0;
  double increasing;

  in_stream >> number;
  in_stream.open("/Users/davidpetullo/Documents/Practice_Array.txt");
  // This is how my computer outputted its full path. I programmed this assignment on a non-Assumption college machine, hence the difference in path format. 
  if (in_stream.fail())
  {
    cout << "The file failed to open.\n";
    exit(1);
  }
  in_stream >> number;
  while (number != 999)
  {
  if (number < 100)
  {
    increasing = CalcAve2(number, result, count);
    cout<< setw(5)<< number << setw(20)<<increasing << endl;

  }

  else
  {

    cout << setw(40)<<number << endl;
    count2++;

  }
  in_stream >> number;
  }

  cout << "There are "<<count2 << " three-digit ages."<< endl;
  in_stream.close();

return 0;



}

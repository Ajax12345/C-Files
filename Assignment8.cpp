//So far, this is the best code
#include <iostream>
#include <fstream>
#include <iomanip>
void reverse(int data_array[], int number, int marker, std::ofstream& output_file);
using namespace std;

int main()
{
  int count = 0;
  int my_array[800];
  ifstream datafile;
  ofstream output;
  datafile.open("/Users/davidpetullo/Documents/first.txt");
  output.open("/Users/davidpetullo/Documents/New_Output.txt");
  if(datafile.fail())
  {
    cout << "Datafile opening failure"<< endl;
    exit(1);
  }

  while (!datafile.eof())
  {
    datafile >> my_array[count];
    count++;

  }

  int new_count = count-1;


  int flag = 1;
  reverse(my_array, new_count, flag, output);
  //output << endl;

  if (new_count % 2 == 0) //used to be count + 1 % 2 == 0
  {
    output << endl;
    output << endl;
    output << "There was no middle number. Highest subscript was "<< new_count - 1 << endl;
  }
  else if (new_count% 2 != 0)
  {
    int middle_number = my_array[((new_count+1)/2) - 1];
    output << endl;
    output << endl;
    output << "There is a middle number and it was "<< middle_number<<". The Highest subscript was "<< new_count-1 << endl;
  }
  output << endl; //was not here before

  int new_position = 0;
  int new_range = new_count/2;
  int new_array[400];

  for (int i = 0; i < new_count; i++)
  {
    new_array[new_position] = my_array[i] + my_array[new_count - i-1];
    if ((my_array[i] == my_array[new_count-i-1]) && (new_count%2 != 0))
    {
      new_array[i] = my_array[i];
    }

    new_position++;

  }
  if (new_count%2 != 0)
  {
    new_range = (new_count + 1)/2;
  }
  int new_flag = -1;

  reverse(new_array, new_range, new_flag, output);
  //on these lines, I find the highest subscript and last integer in the new array
  output << endl;
  output << endl;
  output << "New array has highest subscript "<< new_range-1 << " and the last integer in the new array is "<< new_array[new_range - 1] << endl;


  datafile.close();
  output.close();


}

void reverse(int data_array[], int number, int marker, ofstream& output_file)
{
  int lines_printed = 0;

  if (marker > 0)
  {

    for (int i = number-1; i >= 0; i--)
    {
      output_file << data_array[i] << setw(5);
      lines_printed++;
      if (lines_printed%20 == 0)
      {
        output_file << "\n";
      }

    }
  }
  else if (marker < 0)
  {
    for (int i = 0; i < number; i++)
    {
      output_file << data_array[i] << setw(5);
      lines_printed++;
      if (lines_printed%20 == 0)
      {
        output_file << "\n";
      }

    }

  }

}

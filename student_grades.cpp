#include <iostream>
#include <fstream>
#include <cmath>
//James Petullo
//Dr. Brown
using namespace std;
int StudentQuizAverage(int data[][15], int index, int size);
int FinalAverage(int data[][15], int index, int quiz_average);
void PrintAverage(int final_grade, int index);

int main()
{
  ifstream input;
  input.open("first.txt");
  int grades[26][15];
  int length_array[26];
  int n;
  int count = 0, counter = 0;
  if (input.fail())
  {
    cout << "Fatal Error. Please check your file"<< endl;
    exit(1);
  }

  cout << "Student Test and Quiz Data"<< endl;

  while (!input.eof())
  {


    input >> n;
    if (n > 10 && counter < 2)
    {


      grades[count][counter] = n;


      cout << n<< " ";
      counter++;
      length_array[count] = counter;

    }

    else if (n < 11 && counter >= 1)
    {

      grades[count][counter] = n;
      length_array[count] = counter;


      cout << n << " ";
      counter++;
      length_array[count] = counter+1;

    }


    else
    {

      count++;
      counter = 0;
      grades[count][counter] = n;

      counter++;
      length_array[count] = counter+1;
      //counter = 0;

      cout << endl;
      cout << n << " ";


    }

  }

  cout << endl;

  cout << endl;

  for (int i = 0; i < count+1; i++)
  {
    int the_size = length_array[i];

    int student_quiz_average;

    student_quiz_average = StudentQuizAverage(grades, i, the_size);

    cout << "Student "<< i+1 << "'s"<< " overal quiz grade is "<< student_quiz_average<< endl;
  }

  cout << endl;

  for (int i = 0; i < count+1; i++)
  {
    int the_size = length_array[i];

    int student_quiz_average;
    int student_total_average;
    student_quiz_average = StudentQuizAverage(grades, i, the_size);


    student_total_average = FinalAverage(grades, i, student_quiz_average);
    PrintAverage(student_total_average, i);


  }



}




int StudentQuizAverage(int data[][15], int index, int size)
{
  int number = 0;
  int running_total = 0;
  double total_average;

 for (int i = 2; i< size-1; i++)
 {
   running_total += data[index][i];
   number++;
 }
 total_average = (double)running_total/(double)number;

 //return round(total_average);
 return (int)(total_average+0.5);
}



int FinalAverage(int data[][15], int index, int quiz_average)
{
  quiz_average *= 10;

  double total_average = ((double)data[index][0]+(double)data[index][1]+(double)quiz_average)/3;

  return (int)(total_average+0.5);
}

void PrintAverage(int final_grade, int index)
{
  cout << "Student "<< index+1<< "'s overall average is "<< final_grade<< endl;
}

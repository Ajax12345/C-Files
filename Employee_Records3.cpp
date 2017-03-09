#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//James Petullo

// 26 February 2017


class Employee
{
  public:

    Employee()
    {

    }
    void SetPersonalData(ifstream& input_file)
    {
      //double pday1, pday2, pday3, pday4, pday5, pfinal_pay;
      double the_total_pay;


      input_file>> ID;
      input_file >> dependants;
      input_file >> type;



      InputHrs(input_file);


      the_total_pay = GetPayCheck();

      cout << "ID number "<<GetId() << " : $"<<the_total_pay<< endl;




    }
    int GetId()
    {
      return ID;
    }
    double GetTotalHours()
    {

      double day_sum;
      day_sum = day1 + day2 + day3 + day4+day5;
      return day_sum;


    }
    double GetPayCheck()
    {
      double final_salary;
      final_salary = CalculatePayCheck();
      return final_salary;

    }
  private:
    int n, ID, dependants;
    double day1, day2, day3, day4, day5, final_pay;
    char type;
    double the_total_hours;

    double CalculatePayCheck()
    {
      double ideal_pay, deductions, the_final_salary;
      ideal_pay = SumUpHours();
      deductions = CalcDeductions(ideal_pay);
      the_final_salary = ideal_pay - deductions;
      return the_final_salary;

    }
    double CalcDeductions(double grosspay)
    {
        double total_income;

        double tax_withholdings, health_insurance, total_deductions;
        tax_withholdings = grosspay*0.22;
        health_insurance = 15.25*dependants;
        total_deductions = tax_withholdings + health_insurance;
        return total_deductions;
    }
    double SumUpHours()
    {
      double the_days;
      the_days = GetTotalHours();
      if (type == 'W')
      {
        return 41.75*the_days;
      }
      else
      {
        return 0.55*41.75*the_days;
      }
    }

    void InputHrs(ifstream& input_file)
    {


      input_file >> day1>>day2>>day3>>day4>>day5;


    }


};

int main()
{
  Employee the_employee;
  ifstream input;
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  int n;

  input.open("first.txt");
  if (input.fail())
  {
    cout << "Fatal Error"<< endl;
    exit(1);
  }
  input >> n;
  for (int i = 0; i < n; i++)
  {
    the_employee.SetPersonalData(input);
  }




  input.close();
}

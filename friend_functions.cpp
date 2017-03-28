#include <iostream>
using namespace std;
//James Petullo
//Dr. Brown

class Rational
{
public:
  Rational()
  {
    denominator = 1;
    numerator = 0;
    sign = '+';
  }
  void PrintFraction()
  {

    if (sign == '+')
    {
      //cout << numerator<< slash << denominator<< endl;
      cout << numerator << "/"<<denominator<< endl;
    }
    else
    {

      cout << sign<<abs(numerator)<< "/"<<abs(denominator) << endl;
    }
  }
  friend bool Equivalent(Rational fract1, Rational fract2);
  void Setter(int denom1, int num1)
  {
    if (denom1 < 0 || num1 < 0)
    {
      sign = '-';
    }
    else
    {
      sign = '+';
    }
    denominator = denom1;
    numerator = num1;
  }

private:
  int denominator, numerator;
  char sign;

};

bool Equivalent(Rational fract1, Rational fract2)
{

  if (fract2.numerator*fract1.denominator == fract2.denominator*fract1.numerator)
  {
    return true;
  }
  else
  {
    return false;
  }
}
int main()
{
  Rational rational, rational1;
  int den1, numer1, den2, numer2;
  cout << "Enter the numerator and denominators for you fractions. The form is (numerator denominator): "<< endl;

  cin >> numer1 >> den1>> numer2 >> den2;

  rational.Setter(den1, numer1);
  rational1.Setter(den2, numer2);
  rational.PrintFraction();
  rational1.PrintFraction();

  if (Equivalent(rational, rational1))
  {
    cout << "The fractions are equal"<< endl;
  }
  else
  {
    cout << "The fractions are not equal"<< endl;
  }

}

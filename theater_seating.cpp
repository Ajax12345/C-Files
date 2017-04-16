#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;

class Theater
{
public:
  bool is_available(int row, int column)
  {
    return (theater[row][column] != '*');
  }
  void transaction(int row, int column, int row_price)
  {
    total_profit += row_price;
    theater[row][column] = '*';
    cout << "Your total bill is $"<< row_price<< " for theater "<< seat_names[row]<< " seats"<< endl;
    cout << "Thank you for your business and enjoy the show"<< endl;
  }
  void show_sales_report()
  {
    cout << "Total sales for this show is $"<< total_profit<< endl;
  }
  void show_seating()
  {
    cout << "Here is the currect theater seating:"<< endl;
    for (int i = 0; i< 15; i++)
    {
      for (int b = 0; b < 30; b++)
      {
        cout << theater[i][b];
      }
      cout << endl;
    }

  }
private:
  char theater[15][30] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  };
  double total_profit = 0;
  map<int, string>seat_names = {{0, "elevated-backrow"}, {1, "backrow2"}, {2, "backrow3"}, {3, "laysoin"}, {4, "special"}, {5, "middle"}, {6, "middle"}, {7, "middle"}, {8, "middle"}, {9, "middle"}, {10, "middle"}, {11, "front"}, {12, "front"}, {13, "front"}, {14, "front"}};


};

int main()
{
  Theater the_theater;
  char ans;
  ifstream input;
  vector<int>prices;
  input.open("first.txt");
  int n;
  while(!input.eof())
  {
    input >> n;
    prices.push_back(n);
  }
  while (true)
  {
    cout << "Welcome to our theater. Type 'a' to request a seat. To view the sales report, type 's'. To view the seating chart so far, type c "<< endl;
    cin >> ans;
    if (ans == 'a')
    {
      int x, y;
      while (true)
      {
        cout << "Enter the desired row and column of your seat. "<< endl;
        cin >> x >> y;
        bool flag = the_theater.is_available(x-1, y-1);
        if (flag)
        {
          string answer;
          cout << "The desired seat is available. Do you wish to proceed?"<< endl;
          cin >> answer;
          if (answer == "yes" || answer == "Yes")
          {
            the_theater.transaction(x-1, y-1, prices[y-1]);
            string new_answer;
            cout << "Would you like to book another seat?"<< endl;
            cin >> new_answer;
            if (new_answer == "yes")
            {
              continue;
            }
            else
            {
              break;
            }
          }
          else
          {
            cout << "thank you for your interest"<< endl;
            break;
          }
        }
        else
        {
          string new_user_answer;
          cout << "I am sorry, that seat is not available. Would you like to pick another seat? "<< endl;
          cin >> new_user_answer;
          if( new_user_answer == "yes")
          {
            continue;
          }
          else
          {
            break;
          }

        }
      }
    }
    else if (ans == 's')
    {
      the_theater.show_sales_report();
    }
    else if (ans == 'c')
    {
      the_theater.show_seating();
    }
    string final_answer;
    cout << "Do you want to view another item?"<< endl;
    cin >> final_answer;
    if (final_answer == "yes")
    {
      continue;
    }
    else
    {
      break;
    }
  }
}

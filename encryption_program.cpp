#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
//James Petullo
//Dr. Joyce Brown
void printer(vector<char>&message);
vector<char>Encrypt(vector<char>&message, int the_key);

int main()
{


  ifstream input;
  input.open("first.txt");
  if (input.fail())
  {
    cout << "Fatal error"<< endl;
    exit(1);
  }
  char letter;
  int key = 7;
  int counter = 0;
  vector<char>entire_message;
  input.get(letter);
  while(!input.eof())
  {


    if (letter == '\n')
    {
      vector<char>encrypted_message;
      //entire_message.push_back(letter);
      printer(entire_message);
      cout << "vector size of message is "<< entire_message.size()<< endl;
      cout << "-----------------------------------------------------"<< endl;
      encrypted_message = Encrypt(entire_message, key);
      cout << "Encrypted message: ";
      printer(encrypted_message);
      cout << "-----------------------------------------------------"<< endl;
      cout << endl;
      cout << endl;
      entire_message.clear();
    }
    else
    {
      entire_message.push_back(letter);
    }
    input.get(letter);

  }



}


void printer(vector<char>&message)
{
  for (int i = 0; i < message.size(); i++)
  {
    cout << message[i];
  }

  cout << endl;

}

vector<char>Encrypt(vector<char>&message, int the_key)
{
  vector<char>final_message;

  for (int i = 0; i < message.size(); i++)
  {

      if (message[i] < 'N')
      {
        int numerical_key = (int)message[i]-32+the_key;
        char final_letter = (char)numerical_key;
        final_message.push_back(final_letter);

      }
      else if (message[i] >= 'N')
      {
        int numerical_key = (int)message[i] + 32 - the_key;
        char final_letter = (char)numerical_key;
        final_message.push_back(final_letter);
      }

  }
  return final_message;

}

//James Petullo

//Assignment7 re count and space manipulation program
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream myfile;
    ofstream results;
    char letter, letter1;
    int count = 0, count1 = 0;
    myfile.open("C:\\Users\\AC Labs\\Desktop\\Input.txt"); 
    results.open("C:\\Users\\AC Labs\\Desktop\\Output.txt");
    myfile.get(letter1);

    if (myfile.fail())
    {
        cout << "Failed to open" << endl;
        exit(1);
    }
    while (!myfile.eof())
    {

        letter = letter1;
        myfile.get(letter1);
        if ((letter == 'r' || letter == 'R') && (letter1 == 'e' || letter1 == 'E'))
        {

            count++;

        }
        else if (letter == char(32))
        {
            letter = ' ';
            results.put(letter);

        }

        else if (letter == '\n')
        {
            count1++;
        }

        results.put(letter);

    }
    results << "re occurred " << count << " times and the number of lines in this file is " << count1 << " not counting this one.\n";
    myfile.close();
    results.close();
    return 0;

}

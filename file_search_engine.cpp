#include <iostream>
#include <vector>
#include <fstream>
#include <string>


using namespace std;
vector<string>get_stop_words();
string lower(string the_word);
int main()
{
	vector<string>files = {"/Users/davidpetullo/txtfolders/doc1.txt", "/Users/davidpetullo/txtfolders/doc2.txt", "/Users/davidpetullo/txtfolders/doc3.txt", "/Users/davidpetullo/txtfolders/doc4.txt", "/Users/davidpetullo/txtfolders/doc5.txt"};
	vector<string>stopwords = get_stop_words();
	string query = "justice ministry official";
	for (string filename:files)
	{
		ifstream input;
		string word;
		vector<string>file_contents;
		input.open(filename);
		input >> word;
		string file_stuff = "";
		while (!input.eof())
		{

			string lower_word;
			lower_word = lower(word);
			if (find(stopwords.begin(), stopwords.end(), lower_word) == stopwords.end())
			{
				file_stuff += lower_word;
				file_stuff += " ";
			}
			input >> word;

		}

		cout << filename<< endl;
		//cout << "file stuff "<< file_stuff<< endl;
		cout << ((file_stuff.find(query) != string::npos)?"Found":"Not Found")<< endl;


	}
}


vector<string>get_stop_words()
{
	ifstream input;
	input.open("/Users/davidpetullo/nltk_data/corpora/stopwords/english");

	string word;
	vector<string>words;

	input >> word;
	while(!input.eof())
	{
		word = lower(word);
		words.push_back(word);
		input >> word;
	}
	return words;
}
string lower(string the_word)
{
	string result = "";
	for (int i = 0; i < the_word.length(); i++)
	{
		result += (char)tolower(the_word[i]);
	}
	return result;
}

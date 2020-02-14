#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	string sentence = "This is a random sentence";
	vector<string> wordVector;
	stringstream ss(sentence);
	string word;
	char next = ' ';
	
	while (getline(ss, word, next))
	{
		wordVector.push_back(word);
	}
	
	for (int i = 0; i < wordVector.size(); ++i)
	{
		cout << wordVector.at(i) << endl;
	}
	
	system("pause");
	return 0;
}
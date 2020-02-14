#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	while (true)
	{
		string word;
		list<char> wordL;
	
		cout << "Enter a word: ";
		getline(cin, word);
		
		for (int i = 0; word[i] != '\0'; ++i)
		{
			wordL.push_back(word[i]);
		}
		
		list<char>::iterator iter = wordL.begin();
		list<char>::reverse_iterator r_iter = wordL.rbegin();
		bool isPalindrome = true;
		for (int i = 0; i < word.size()/2; ++i)
		{
			cout << "Comparing " << static_cast<char>(tolower(*iter)) << " with " << static_cast<char>(tolower(*r_iter)) << " ...";
			if (tolower(*iter) != tolower(*r_iter))
			{
				isPalindrome = false;
				cout << " Not the same!" << endl;
				break;
			}
			cout << " Good so far ..." << endl;
			++iter;
			++r_iter;
		}
		
		if (isPalindrome)
		{
			cout << word << " is a palindrome!" << endl << endl;
		}
		else
		{
			cout << word << " is not a palindrome." << endl << endl;
		}
		
		system("pause");
		system("cls");
	}
	
	return 0;
}
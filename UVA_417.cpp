#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;


int nthWord;

void BruteForce(char nextCharacter, string word, int wordLength, map <string, int> &wordIndex)
{
	if (word.length() == wordLength)
	{
		wordIndex[word] = ++nthWord;
		return;
	}

	char currentChar;

	for (currentChar = nextCharacter; currentChar <= 'z'; currentChar++)
	{
		word += currentChar;
		BruteForce(currentChar+1, word, wordLength, wordIndex);
		word.erase(word.length() - 1);
	}
}


int main()
{
	map <string, int> wordIndex;
	string inputWord;

	BruteForce('a', "", 1, wordIndex);
	BruteForce('a', "", 2, wordIndex);
	BruteForce('a', "", 3, wordIndex);
	BruteForce('a', "", 4, wordIndex);
	BruteForce('a', "", 5, wordIndex);

	while (cin >> inputWord)
	{
		cout << wordIndex[inputWord] << "\n";
	}
	return 0;
}
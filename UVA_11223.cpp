#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;


void SetMorseCodeMap(map<string, char> &morseCodeMap)
{
	morseCodeMap[".-"] = 'A';
	morseCodeMap["-..."] = 'B';
	morseCodeMap["-.-."] = 'C';
	morseCodeMap["-.."] = 'D';
	morseCodeMap["."] = 'E';
	morseCodeMap["..-."] = 'F';
	morseCodeMap["--."] = 'G';
	morseCodeMap["...."] = 'H';
	morseCodeMap[".."] = 'I';
	morseCodeMap[".---"] = 'J';
	morseCodeMap["-.-"] = 'K';
	morseCodeMap[".-.."] = 'L';
	morseCodeMap["--"] = 'M';
	morseCodeMap["-."] = 'N';
	morseCodeMap["---"] = 'O';
	morseCodeMap[".--."] = 'P';
	morseCodeMap["--.-"] = 'Q';
	morseCodeMap[".-."] = 'R';
	morseCodeMap["..."] = 'S';
	morseCodeMap["-"] = 'T';
	morseCodeMap["..-"] = 'U';
	morseCodeMap["...-"] = 'V';
	morseCodeMap[".--"] = 'W';
	morseCodeMap["-..-"] = 'X';
	morseCodeMap["-.--"] = 'Y';
	morseCodeMap["--.."] = 'Z';
	morseCodeMap["-----"] = '0';
	morseCodeMap[".----"] = '1';
	morseCodeMap["..---"] = '2';
	morseCodeMap["...--"] = '3';
	morseCodeMap["....-"] = '4';
	morseCodeMap["....."] = '5';
	morseCodeMap["-...."] = '6';
	morseCodeMap["--..."] = '7';
	morseCodeMap["---.."] = '8';
	morseCodeMap["----."] = '9';
	morseCodeMap[".-.-.-"] = '.';
	morseCodeMap["--..--"] = ',';
	morseCodeMap["..--.."] = '?';
	morseCodeMap[".----."] = '\'';
	morseCodeMap["-.-.--"] = '!';
	morseCodeMap["-..-."] = '/';
	morseCodeMap["-.--."] = '(';
	morseCodeMap["-.--.-"] = ')';
	morseCodeMap[".-..."] = '&';
	morseCodeMap["---..."] = ':';
	morseCodeMap["-.-.-."] = ';';
	morseCodeMap["-...-"] = '=';
	morseCodeMap[".-.-."] = '+';
	morseCodeMap["-....-"] = '-';
	morseCodeMap["..--.-"] = '_';
	morseCodeMap[".-..-."] = '\"';
	morseCodeMap[".--.-."] = '@';
}


string TranslateMorseCode(string morseCode, map <string, char> &morseCodeMap)
{
	int i, thisIsAnEmptySpace;
	string translatedString, tempString;

	thisIsAnEmptySpace = 0;
	translatedString = tempString = "";
	for (i = 0; i < morseCode.length(); i++)
	{
		if (morseCode[i] == ' ')
		{
			if (thisIsAnEmptySpace)
			{
				translatedString = translatedString + ' ';
				thisIsAnEmptySpace = 0;
			}
			else
			{
				if (tempString != "")
				{
					translatedString = translatedString + morseCodeMap[tempString];
					tempString = "";
					thisIsAnEmptySpace = 1;
				}
			}
		}
		else
		{
			tempString = tempString + morseCode[i];
			thisIsAnEmptySpace = 0;
		}
	}
	if (tempString != "")
	{
		translatedString = translatedString + morseCodeMap[tempString];
	}

	return translatedString;
}




void TakeInputNSolve(int &nCases, string &morseCode, map <string, char> &morseCodeMap)
{
	int i, firstCase;

	cin >> nCases;
	firstCase = 1;
	cin.ignore();
	for (i = 1; i <= nCases; i++)
	{
		if (firstCase == 1)
		{
			firstCase = 0;
		}
		else
		{
			cout << "\n";
		}
		getline(cin, morseCode);
		cout << "Message #" << i << "\n";
		cout << TranslateMorseCode(morseCode, morseCodeMap) << "\n";
	}
}





int main()
{
	int nCases;
	string morseCode;
	map <string, char> morseCodeMap;

	SetMorseCodeMap(morseCodeMap);
	TakeInputNSolve(nCases, morseCode, morseCodeMap);
	
	return 0;
}
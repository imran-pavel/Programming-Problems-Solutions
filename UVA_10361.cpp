#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


string getTokenizedString(string &line1, int &prevDelimiterPosition)
{
	int delimiterPosition;
	string tokenizedString;

	delimiterPosition = line1.find_first_of("<>", prevDelimiterPosition+1);
	tokenizedString = line1.substr(prevDelimiterPosition + 1, delimiterPosition - (prevDelimiterPosition + 1));
	prevDelimiterPosition = delimiterPosition;

	return tokenizedString;
}



void AppendTokens(string &outputLine, string token)
{
	if (token == "")
	{
		return;
	}
	outputLine += token;
}


string GetFirstOutputLine(string &line1, string &s1, string &s2, string &s3, string &s4, string &s5)
{
	int delemiterPosition, prevDelemiterPosition;
	string outputLine;

	prevDelemiterPosition = -1;
	s1 = getTokenizedString(line1, prevDelemiterPosition);
	s2 = getTokenizedString(line1, prevDelemiterPosition);
	s3 = getTokenizedString(line1, prevDelemiterPosition);
	s4 = getTokenizedString(line1, prevDelemiterPosition);
	s5 = getTokenizedString(line1, prevDelemiterPosition);

	AppendTokens(outputLine, s1);
	AppendTokens(outputLine, s2);
	AppendTokens(outputLine, s3);
	AppendTokens(outputLine, s4);
	AppendTokens(outputLine, s5);

	return outputLine;
}



string GetSecondOutputLine(string &line2, string &s1, string &s2, string &s3, string &s4, string &s5)
{
	string outputLine;

	AppendTokens(outputLine, s4);
	AppendTokens(outputLine, s3);
	AppendTokens(outputLine, s2);
	AppendTokens(outputLine, s5);

	line2.replace(line2.find_first_of(".", 0), 3, outputLine);

	return line2;
}



int main()
{
	int nPairs;
	string line1, line2, s1, s2, s3, s4, s5;

	cin >> nPairs;
	cin.ignore();

	while (nPairs--)
	{
		getline(cin, line1);
		getline(cin, line2);

		cout << GetFirstOutputLine(line1, s1, s2, s3, s4, s5) << "\n";
		cout << GetSecondOutputLine(line2, s1, s2, s3, s4, s5) << "\n";
	}

	return 0;
}
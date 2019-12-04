#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#define MapSize 20

using namespace std;


string TokenizePosition(string inputString, int fromIndex)
{
	return inputString.substr(fromIndex, inputString.find_first_of(" \n", fromIndex) - fromIndex);
}



void GetPosition(string inputString, string &positionString, int &fromIndex)
{
	positionString = "";
	while (true)
	{
		positionString = TokenizePosition(inputString, fromIndex);
		if (positionString != "")
		{
			break;
		}
		fromIndex++;
	}
}

void PrintAsterisks()
{
	cout << "********************\n";
}



int GetIntPosition(string positionString)
{
	int position;
	stringstream stringStream;

	stringStream.str(positionString);
	stringStream >> position;

	return position;
}



void UpdateMap(char spaceMap[][MapSize], vector <int> &positionsX, vector <int> &positionsY, char updateCharacter)
{
	int i;

	for (i = 0; i < positionsX.size(); i++)
	{
		spaceMap[positionsX[i]][positionsY[i]] = updateCharacter;
	}
}



void Simulate(char spaceMap[][MapSize], vector <int> &positionChangesX, vector <int> &positionChangesY)
{
	int i, j, k, neighborCount, neighborX, neighborY;
	vector <int> newQuartersLocationsX, newQuartersLocationsY;
	vector <int> dyingQuartersLocationsX, dyingQuartersLocationsY;

	for (i = 0; i < MapSize; i++)
	{
		for (j = 0; j < MapSize; j++)
		{
			neighborCount = 0;
			for (k = 0; k < positionChangesX.size(); k++)
			{
				neighborX = i + positionChangesX[k];
				neighborY = j + positionChangesY[k];
				if ((neighborX >= 0 && neighborX < MapSize) && (neighborY >= 0 && neighborY < MapSize))
				{
					if (spaceMap[neighborX][neighborY] == 'O')
					{
						neighborCount++;
					}
				}
			}

			if (spaceMap[i][j] == ' ' && neighborCount == 3)
			{
				newQuartersLocationsX.push_back(i);
				newQuartersLocationsY.push_back(j);
			}
			else if (spaceMap[i][j] == 'O' && (neighborCount <= 1 || neighborCount >= 4))
			{
				dyingQuartersLocationsX.push_back(i);
				dyingQuartersLocationsY.push_back(j);
			}
		}
	}

	UpdateMap(spaceMap, newQuartersLocationsX, newQuartersLocationsY, 'O');
	UpdateMap(spaceMap, dyingQuartersLocationsX, dyingQuartersLocationsY, ' ');
}


void PrintSpaceMap(char spaceMap[][MapSize])
{
	int i, j;

	for (i = 0; i < MapSize; i++)
	{
		for (j = 0; j < MapSize; j++)
		{
			cout << spaceMap[i][j];
		}
		cout << "\n";
	}
}


void SetPositionChangeValues(vector <int> &positionChangesX, vector <int> &positionChangesY)
{
	positionChangesX.push_back(0);
	positionChangesX.push_back(-1);
	positionChangesX.push_back(-1);
	positionChangesX.push_back(-1);
	positionChangesX.push_back(0);
	positionChangesX.push_back(1);
	positionChangesX.push_back(1);
	positionChangesX.push_back(1);

	positionChangesY.push_back(1);
	positionChangesY.push_back(1);
	positionChangesY.push_back(0);
	positionChangesY.push_back(-1);
	positionChangesY.push_back(-1);
	positionChangesY.push_back(-1);
	positionChangesY.push_back(0);
	positionChangesY.push_back(1);
}



int main()
{
	int fromIndex, nCases, nYears, firstPosition, secondPosition, firstTestCase;
	char spaceMap[MapSize][MapSize];
	string inputString, firstPositionString, secondPositionString;
	vector <int> positionChangesX, positionChangesY;
	
	SetPositionChangeValues(positionChangesX, positionChangesY);
	firstTestCase = 1;
	cin >> nCases;
	while (nCases--)
	{
		memset(spaceMap, ' ', sizeof(spaceMap));
		cin >> nYears;
		cin.ignore();
		while (getline(cin, inputString) && inputString!= "")
		{
			fromIndex = 0;
			GetPosition(inputString, firstPositionString, fromIndex);
			fromIndex += firstPositionString.length();
			GetPosition(inputString, secondPositionString, fromIndex);

			firstPosition = GetIntPosition(firstPositionString);
			secondPosition = GetIntPosition(secondPositionString);

			spaceMap[firstPosition-1][secondPosition-1] = 'O';
		}

		if (firstTestCase)
		{
			firstTestCase = 0;
		}
		else
		{
			cout << "\n";
		}

		PrintAsterisks();
		PrintSpaceMap(spaceMap);
		PrintAsterisks();
		nYears--;
		while (nYears--)
		{
			Simulate(spaceMap, positionChangesX, positionChangesY);
			PrintSpaceMap(spaceMap);
			PrintAsterisks();
		}
	}

	
	
	return 0;
}
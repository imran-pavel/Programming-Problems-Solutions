#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int NCases, CharToValue[121], DNAProgram[10];
char Dishes1[41], Dishes2[41], ValueToChar[4], Decoy[2];


void Reset()
{
	memset(Dishes1, ' ', sizeof(Dishes1));
	Dishes1[19] = '.';
	Dishes1[40] = Dishes2[40] = '\0';
}



void Simulate(char Array1[], char Array2[], int Day)
{
	if (Day == 50)
	{
		puts(Array1);
		return;
	}

	int i, Cost1, Cost2;
	
	puts(Array1);
	for (i = 0; i < 40; i++)
	{
		if (i - 1 < 0)
		{
			Cost1 = 0;
		}
		else
		{
			Cost1 = CharToValue[Array1[i-1]];
		}
		if (i + 1 >= 40)
		{
			Cost2 = 0;
		}
		else
		{
			Cost2 = CharToValue[Array1[i+1]];
		}
		Array2[i] = ValueToChar[DNAProgram[Cost1 + CharToValue[Array1[i]] + Cost2]];
	}

	Simulate(Array2, Array1, Day + 1);
}



int main()
{
	int i, j, IsFirst;

	CharToValue[' '] = 0;
	CharToValue['.'] = 1;
	CharToValue['x'] = 2;
	CharToValue['W'] = 3;

	ValueToChar[0] = ' ';
	ValueToChar[1] = '.';
	ValueToChar[2] = 'x';
	ValueToChar[3] = 'W';

	cin >> NCases;
	IsFirst = 1;
	for (i = 0; i < NCases; i++)
	{
		if (IsFirst)
		{
			IsFirst = 0;
		}
		else
		{
			cout << "\n";
		}
		for (j = 0; j < 10; j++)
		{
			cin >> DNAProgram[j];
		}
		Reset();
		Simulate(Dishes1, Dishes2, 1);
	}
	return 0;
}
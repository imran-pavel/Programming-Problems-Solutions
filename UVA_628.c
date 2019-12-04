

#include <stdio.h>

int NWords, NRules, WordTaken[110], DigitTaken[12], Output[260];

char Words[100][260], Rules[1000][260];


void Reset()
{
	int i;

	for (i = 0; i < 10; i++)
	{
		DigitTaken[i] = 0;
		WordTaken[i] = 0;
	}

	for (i = 10; i < 100; i++)
	{
		WordTaken[i] = 0;
	}
}


void Print(int NthRule)
{
	int i;

	for (i = 0; Rules[NthRule][i]; i++)
	{
		if (Rules[NthRule][i] == '0')
		{
			printf("%d", Output[i]);
		}
		else
		{
			printf("%s", Words[Output[i]]);
		}
	}

	printf("\n");
}


void BackTrack(int NthPosition, int NthRule, int CurrentCharacterIndex)
{
	if (Rules[NthRule][CurrentCharacterIndex] == '\0')
	{
		Print(NthRule);
		return;
	}

	if (Rules[NthRule][CurrentCharacterIndex] == '0')
	{
		int i;

		for (i = 0; i < 10; i++)
		{
			Output[NthPosition] = i;
			BackTrack(NthPosition + 1, NthRule, CurrentCharacterIndex + 1);
		}
	}
	else
	{
		int i;

		for (i = 0; i < NWords; i++)
		{
			Output[NthPosition] = i;
			BackTrack(NthPosition + 1, NthRule, CurrentCharacterIndex + 1);
		}
	}
}



void PrintRules()
{
	int i;

	for (i = 0; i < NRules; i++)
	{
		printf("%s\n", Rules[i]);
	}
}



int main()
{

	
	int i;
	
	while (scanf("%d", &NWords) == 1)
	{
		for (i = 0; i < NWords; i++)
		{
			scanf("%s", Words[i]);
		}

		scanf("%d", &NRules);
		for (i = 0; i < NRules; i++)
		{
			scanf("%s", Rules[i]);
		}


		for (i = 0; i < NRules; i++)
		{
			printf("--\n");
			BackTrack(0, i, 0);
		}
	}
	return 0;
}
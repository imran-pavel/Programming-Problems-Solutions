#include <stdio.h>

int NCases, NNewsPapers, From, To, ShouldTake, Taken[12], Output[12];
char Range[1000000], Decoy[2];
char NewsPaperList[13][31];


void Reset()
{
	int i;

	for (i = 0; i < 13; i++)
	{
		NewsPaperList[i][0] = 0;
	}
}



void PrintNewsPapers()
{
	int i;

	for (i = 0; i < ShouldTake-1; i++)
	{
		printf("%s, ", NewsPaperList[Output[i]]);
	}
	printf("%s\n", NewsPaperList[Output[i]]);
}




void Backtrack(int NTaken, int NextIndex)
{
	if (NTaken == ShouldTake)
	{
		PrintNewsPapers();
	}

	int i;

	for (i = NextIndex; i < NNewsPapers; i++)
	{
		if (!Taken[i])
		{
			Taken[i] = 1;
			Output[NTaken] = i;
			Backtrack(NTaken + 1, i+1);
			Taken[i] = 0;
		}
	}
}




void FindRange()
{
	int i;

	From = To = -1;
	if (Range[0] == '*')
	{
		From = 1;
		To = NNewsPapers;
		return;
	}
	i = 0;
	while ((From == -1 || To == -1 ) && Range[i])
	{
		if (Range[i] >= '0' && Range[i] <= '9' && From == -1)
		{
			if (Range[i + 1] >= '0' && Range[i + 1] <= '9')
			{
				From = ((Range[i] - '0') * 10) + (Range[i + 1] - '0');
				i += 2;
				continue;
			}
			else
			{
				From = Range[i] - '0';
			}
		}
		else if (Range[i] >= '0' && Range[i] <= '9' && To == -1)
		{
			if (Range[i + 1] >= '0' && Range[i + 1] <= '9')
			{
				To = ((Range[i] - '0') * 10) + (Range[i + 1] - '0');
			}
			else
			{
				To = Range[i] - '0';
			}

			break;
		}
		i++;
	}

	if (To == -1)
	{
		To = From;
	}
}




int main()
{
	int i, j, IsFirst1, IsFirst2;

	IsFirst1 = IsFirst2 = 1;
	scanf("%d", &NCases);
	gets(Decoy);
	for (i = 0; i < NCases; i++)
	{
		if (IsFirst1)
		{
			gets(Decoy);
			IsFirst1 = 0;
		}
		else
		{
			printf("\n");
		}
		gets(Range);
		Reset();
		for (NNewsPapers = 0; NNewsPapers < 13; NNewsPapers++)
		{
			gets(NewsPaperList[NNewsPapers]);
			if (!(NewsPaperList[NNewsPapers][0] >= 'A' && NewsPaperList[NNewsPapers][0] <= 'Z') && !(NewsPaperList[NNewsPapers][0] >= 'a' && NewsPaperList[NNewsPapers][0] <= 'z'))
			{
				break;
			}
		}

		FindRange();
		for (j = From; j <= To; j++)
		{
			if (IsFirst2)
			{
				IsFirst2 = 0;
			}
			else
			{
				printf("\n");
			}
			ShouldTake = j;
			printf("Size %d\n", ShouldTake);
			Backtrack(0, 0);
		}
	}

	printf("\n");
	return 0;
}
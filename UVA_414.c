#include <stdio.h>
#define MaxNLines 12
#define MaxLength 26

int NLines, GapsInNthLine[MaxNLines];
char Decoy[2], Surface[MaxNLines][MaxLength];

int GetAbsValue(int Num)
{
	if (Num < 0)
	{
		return -Num;
	}
	return Num;
}

int GetSurfaceLength(int Start, int InOrDecrement, int NthLine)
{
	int i;

	for (i = Start; i >= 0 && i < 25; i += InOrDecrement)
	{
		if (Surface[NthLine][i] != 'X')
		{
			break;
		}
	}

	if (i >= 0 && i < 25)
	{
		return GetAbsValue(Start-i);
	}

	return 25;
}


int GetNthLineGaps(int NthLine)
{
	int FirstLength, SecondLength;

	FirstLength = GetSurfaceLength(0, 1, NthLine);
	SecondLength = GetSurfaceLength(24, -1, NthLine);
	if (25 - (FirstLength + SecondLength) <= 0)
	{
		return 0;
	}
	return (25 - (FirstLength + SecondLength));
}




int GetSurfaceGaps(int NthLine, int NLowestGaps)
{
	int i, TotalGaps;

	TotalGaps = 0;
	for (i = 0; i < NLines; i++)
	{
		if (i == NthLine)
		{
			continue;
		}
		TotalGaps += GetAbsValue(GapsInNthLine[NthLine] - GapsInNthLine[i]);
	}

	return TotalGaps;
}



int main()
{
	int i, LineWithLowestGaps, NLowestGaps;

	while (scanf("%d", &NLines) && NLines)
	{
		gets(Decoy);
		for (i = 0; i < NLines; i++)
		{
			gets(Surface[i]);
		}
		NLowestGaps = 26;
		for (i = 0; i < NLines; i++)
		{
			GapsInNthLine[i] = GetNthLineGaps(i);
			if (GapsInNthLine[i] < NLowestGaps)
			{
				LineWithLowestGaps = i;
				NLowestGaps = GapsInNthLine[i];
			}
		}
		printf("%d\n", GetSurfaceGaps(LineWithLowestGaps, NLowestGaps));
	}
	return 0;
}
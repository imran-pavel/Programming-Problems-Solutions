
#include <stdio.h>

#define GridSize 101

int Done, NVariables, NRules, Output[GridSize], Taken[GridSize];
int AdjacencyList[GridSize][GridSize];


void Reset()
{
	int i, j;

	for (i = 0; i < GridSize; i++)
	{
		Taken[i] = 0;
		for (j = 0; j < GridSize; j++)
		{
			AdjacencyList[i][j] = 0;
		}
	}

	Done = 0;
}



void Print()
{
	int i;

	for (i = 0; i < NVariables-1; i++)
	{
		printf("%d ", Output[i]);
	}
	printf("%d\n", Output[i]);
}



void BackTrack(int NthVariable)
{
	if (NthVariable == NVariables)
	{
		Print();
		Done = 1;
		return;
	}

	int i, j;

	for (i = 1; i <= NVariables; i++)
	{
		if (!Taken[i])
		{
			for (j = 1; j <= NVariables; j++)
			{
				if (AdjacencyList[i][j] && Taken[j])
				{
					return;
				}
			}

			Output[NthVariable] = i;
			Taken[i] = 1;
			BackTrack(NthVariable + 1);
			Taken[i] = 0;
			if (Done)
			{
				return;
			}
		}
	}
}



int main()
{
	
	
	int i, Task1, Task2;

	while (1)
	{
		scanf("%d %d", &NVariables, &NRules);
		if (!NVariables && !NRules)
		{
			break;
		}


		Reset();
		for (i = 0; i < NRules; i++)
		{
			scanf("%d %d", &Task1, &Task2);
			AdjacencyList[Task1][Task2] = 1;
		}
		BackTrack(0);
	}
	return 0;
}
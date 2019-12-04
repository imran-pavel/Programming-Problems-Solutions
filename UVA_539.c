#include <stdio.h>

int NNodes, NEdges, Max, AdjacencyList[25][25];


void ResetAdjacencyList()
{
	int i, j;

	for (i = 0; i < NNodes; i++)
	{
		for (j = 0; j < NNodes; j++)
		{
			AdjacencyList[i][j] = 0;
		}
	}
}


void BackTrack(int IthNode, int PathLength)
{
	int i;

	for (i = 0; i < NNodes; i++)
	{
		if (AdjacencyList[IthNode][i])
		{
			AdjacencyList[IthNode][i] = AdjacencyList[i][IthNode] = 0;
			BackTrack(i, PathLength + 1);
			AdjacencyList[IthNode][i] = AdjacencyList[i][IthNode] = 1;
		}
	}

	if (PathLength > Max)
	{
		Max = PathLength;
	}
}


int main()
{
	int i, From, To;

	while (1)
	{
		scanf("%d %d", &NNodes, &NEdges);
		if (!NNodes && !NEdges)
		{
			break;
		}
		ResetAdjacencyList();
		for (i = 0; i < NEdges; i++)
		{
			scanf("%d %d", &From, &To);
			AdjacencyList[From][To] = AdjacencyList[To][From] = 1;
		}

		Max = -1;
		for (i = 0; i < NNodes; i++)
		{
			BackTrack(i, 0);
		}

		printf("%d\n", Max);
	}
	return 0;
}
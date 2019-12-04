#include <stdio.h>
#define NMaxNodes 110
#define MaxOutputLength 210

int NCases, NNodes, OutputLength, QTop, QBottom, Q[NMaxNodes], Taken[NMaxNodes], HoldAdjacencyList[NMaxNodes];
int NNodesReachable, NewNNodesReachable, NewReachableNodes[NMaxNodes], ReachableNodes[NMaxNodes];
int ReachableFlag[NMaxNodes], AdjacencyList[NMaxNodes][NMaxNodes];
char Output[MaxOutputLength][MaxOutputLength];



void Reset1()
{
	int i;

	for (i = 0; i < NNodes; i++)
	{
		ReachableFlag[i] = 0;
	}
}



void Reset2()
{
	int i;

	for (i = 0; i < NNodes; i++)
	{
		Taken[i] = 0;
	}
}



int IsQEmpty()
{
	if (QTop > QBottom)
	{
		return 1;
	}
	return 0;
}




void RemoveOutGoingEdges(int Node)
{
	int i;

	for (i = 0; i < NNodes; i++)
	{
		HoldAdjacencyList[i] = AdjacencyList[Node][i];
		AdjacencyList[Node][i] = 0;
	}
}


void RestoreOutGoingEdges(int Node)
{
	int i;

	for (i = 0; i < NNodes; i++)
	{
		AdjacencyList[Node][i] = HoldAdjacencyList[i];
	}
}



int BFS_FindReachedNodes(int ReachedNodesList[])
{
	int i, NNodesReached, U;

	QTop = QBottom = NNodesReached = 0;
	Q[QTop] = 0;
	Taken[0] = 1;
	while (!IsQEmpty())
	{
		U = Q[QTop];
		QTop++;
		ReachedNodesList[NNodesReached] = U;
		NNodesReached++;
		ReachableFlag[U] = 1;

		for (i = 0; i < NNodes; i++)
		{
			if (AdjacencyList[U][i] && !Taken[i])
			{
				QBottom++;
				Q[QBottom] = i;
				Taken[i] = 1;
			}
		}
	}

	return NNodesReached;
}



void FormatOutput()
{
	int i, j;


	OutputLength = NNodes + (NNodes - 1) + 2;
	for (i = 0; i < OutputLength; i++)
	{
		if (i % 2 == 0)
		{
			Output[i][0] = '+';
			for (j = 1; j < OutputLength - 1; j++)
			{
				Output[i][j] = '-';
			}
			Output[i][j] = '+';
			Output[i][j + 1] = '\0';
		}
		else
		{
			for (j = 0; j < OutputLength; j++)
			{
				if (j % 2 == 0)
				{
					Output[i][j] = '|';
				}
				else
				{
					Output[i][j] = 'Y';
				}
			}
			Output[i][j] = '\0';
		}
	}
}




void PrintOutput()
{
	int i;

	for (i = 0; i < OutputLength; i++)
	{
		printf("%s\n", Output[i]);
	}

}



void PrintNodes(int NodesList[], int Length)
{
	int i;

	for (i = 0; i < Length; i++)
	{
		printf("%d ", NodesList[i]);
	}

	printf("\n");
}



void Swap(int i, int j)
{
	int Hold;

	Hold = NewReachableNodes[i];
	NewReachableNodes[i] = NewReachableNodes[j];
	NewReachableNodes[j] = Hold;
}



void BubbleSort_NewReachableNodes()
{
	int i, j;

	for (i = 0; i < NewNNodesReachable; i++)
	{
		for (j = i + 1; j < NewNNodesReachable; j++)
		{
			if (NewReachableNodes[i] > NewReachableNodes[j])
			{
				Swap(i, j);
			}
		}
	}
}




void UpdateOutput(int Node)
{
	int i, NthRowOfOutput, NthColumnOfOutput;

	BubbleSort_NewReachableNodes();
	NthRowOfOutput = 2 * Node + 1;
	for (i = 0; i < NewNNodesReachable; i++)
	{
		if (Node == NewReachableNodes[i])
		{
			continue;
		}
		NthColumnOfOutput = 2 * NewReachableNodes[i] + 1;
		Output[NthRowOfOutput][NthColumnOfOutput] = 'N';
	}
}


void UpdateDisconnectedGraphOutput(int Node)
{
	int i, j, NthOutputRow, NthOutputColumn;

	for (i = 0; i < NNodes; i++)
	{
		if (i == Node)
		{
			NthOutputRow = 2 * Node + 1;
			for (j = 0; j < NNodes; j++)
			{
				NthOutputColumn = 2 * j + 1;
				Output[NthOutputRow][NthOutputColumn] = 'N';
			}
		}
		else
		{
			NthOutputRow = 2 * i + 1;
			NthOutputColumn = 2 * Node + 1;
			Output[NthOutputRow][NthOutputColumn] = 'N';
		}
	}
}




int main()
{
	int i, j, k;

	scanf("%d", &NCases);
	for (i = 1; i <= NCases; i++)
	{
		scanf("%d", &NNodes);
		for (j = 0; j < NNodes; j++)
		{
			for (k = 0; k < NNodes; k++)
			{
				scanf("%d", &AdjacencyList[j][k]);
			}
		}

		FormatOutput();
		Reset1();
		Reset2();
		NNodesReachable = BFS_FindReachedNodes(ReachableNodes);
		for (j = 0; j < NNodes; j++)
		{
			if (ReachableFlag[j] == 0)
			{
				UpdateDisconnectedGraphOutput(j);
				continue;
			}
			RemoveOutGoingEdges(j);
			Reset2();
			NewNNodesReachable = BFS_FindReachedNodes(NewReachableNodes);
			UpdateOutput(j);
			RestoreOutGoingEdges(j);
		}
		
		printf("Case %d:\n", i);
		PrintOutput();
	}
	return 0;
}
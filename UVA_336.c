/*
   In this link: https://uva.onlinejudge.org/board/viewtopic.php?t=7766&start=60
   
   I found this:
   
   "I got at least 6 times WA for the given code ( in the previous post). I posted here bcz I 
    didn't found any bug in my code. I hoped that I will get helped from the great helpers about my 
    problem. But I failed to get help from others. 

    I think somebody ( cordial persons ) tried to help, but they also failed to help me bcz 
    actually theres no bug in my code. Then whats the problem? The problem is in the judges
    input data set. I'm telling this bcz in that code I declared an array (int) of size 32.

    The reason of that is here: "There will be no more than one (direct) communication line
    between any pair of nodes, and no network will contain more than 30 nodes."
    Then judge was giving me Wrong Ans. But when I changed the size of that array into 32->50
    ( by the suggestion of a friend ) then I got Accepted.
    "

    I changed the size of my array into 40->50 and got accepted too.
*/

#include <stdio.h>

int NEdges, NNodes, Nodes[50], NConnectedNodes[50], AdjacencyList[50][50];
int QTop, QBottom, Source, TTL, Reached[50], TTLValues[50], Q[10000];
int NUnreachable, NthCase, SourceIndex;


void InsertNode(int Number)
{
	Nodes[NNodes] = Number;
	NNodes++;
}


int NumberIndex(int Number)
{
	int i;

	for (i = 0; i < NNodes; i++)
	{
		if (Nodes[i] == Number)
		{
			return i;
		}
	}

	return -1;
}



void Reset1()
{
	int i;

	for (i = 0; i < NNodes; i++)
	{
		NConnectedNodes[i] = 0;
	}
	NNodes = 0;
}

void Reset2()
{
	int i;

	for (i = 0; i < NNodes; i++)
	{
		Reached[i] = 0;
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




void BFS()
{
	int i, U, V;

	QTop = QBottom = 0;
	TTLValues[SourceIndex] = TTL;
	Q[QTop] = SourceIndex;
	Reached[SourceIndex] = 1;

	while (!IsQEmpty())
	{
		U = Q[QTop];
		QTop++;

		if (TTLValues[U] == 0)
		{
			break;
		}

		for (i = 0; i < NConnectedNodes[U]; i++)
		{
			V = AdjacencyList[U][i];
			if (Reached[V])
			{
				continue;
			}
			TTLValues[V] = TTLValues[U] - 1;
			Reached[V] = 1;
			QBottom++;
			Q[QBottom] = V;
		}
	}
}




void CountUnreachableNodes()
{
	int i;

	NUnreachable = 0;
	for (i = 0; i < NNodes; i++)
	{
		if (!Reached[i])
		{
			NUnreachable++;
		}
	}
}



int main()
{
	int i, From, To, IFrom, ITo;

	while (scanf("%d", &NEdges) == 1)
	{
		if (NEdges == 0)
		{
			break;
		}

		for (i = 0; i < NEdges; i++)
		{
			scanf("%d %d", &IFrom, &ITo);
			From = NumberIndex(IFrom);
			if (From == -1)
			{
				InsertNode(IFrom);
				From = NNodes - 1;
			}
			To = NumberIndex(ITo);
			if (To == -1)
			{
				InsertNode(ITo);
				To = NNodes - 1;
			}
			if (From == To)
			{
				continue;
			}
			AdjacencyList[From][NConnectedNodes[From]] = To;
			AdjacencyList[To][NConnectedNodes[To]] = From;
			NConnectedNodes[From]++;
			NConnectedNodes[To]++;
		}

		while (scanf("%d %d", &Source, &TTL) == 2)
		{
			if (Source == 0 && TTL == 0)
			{
				break;
			}
			SourceIndex = NumberIndex(Source);
			if (SourceIndex == -1)
			{
				printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++NthCase, NNodes, Source, TTL);
				continue;
			}
			Reset2();
			BFS();
			CountUnreachableNodes();
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++NthCase, NUnreachable, Source, TTL);
		}
		Reset1();
	}
	return 0;
}
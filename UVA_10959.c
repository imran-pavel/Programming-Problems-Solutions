#include <stdio.h>


int NCase, NPersons, NCouples, QTop, QBottom, IsFirst;
int AdjacencyList[1001][999], NPartners[1001], Taken[1001], Q[1000], GiovanniNumbers[1001];
char Decoy[2];

void Reset()
{
	int i;

	for (i = 0; i < NPersons; i++)
	{
		Taken[i] = NPartners[i] = 0;
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
	Q[QTop] = 0;
	Taken[0] = 1;
	GiovanniNumbers[0] = 0;

	while (!IsQEmpty())
	{
		U = Q[QTop];
		QTop++;
		for (i = 0; i < NPartners[U]; i++)
		{
			V = AdjacencyList[U][i];
			if (!Taken[V])
			{
				GiovanniNumbers[V] = GiovanniNumbers[U] + 1;
				QBottom++;
				Q[QBottom] = V;
				Taken[V] = 1;
			}
		}
	}
}




void PrintGiovanniNumbers()
{
	int i;

	for (i = 1; i < NPersons; i++)
	{
		printf("%d\n", GiovanniNumbers[i]);
	}
}


int main()
{
	int i, FirstPerson, SecondPerson;

	scanf("%d", &NCase);
	gets(Decoy);
	IsFirst = 1;
	while (NCase--)
	{
		gets(Decoy);
		scanf("%d %d", &NPersons, &NCouples);
		for (i = 0; i < NCouples; i++)
		{
			scanf("%d %d", &FirstPerson, &SecondPerson);
			AdjacencyList[FirstPerson][NPartners[FirstPerson]] = SecondPerson;
			AdjacencyList[SecondPerson][NPartners[SecondPerson]] = FirstPerson;
			NPartners[FirstPerson]++;
			NPartners[SecondPerson]++;
		}
		BFS();
		if (IsFirst)
		{
			IsFirst = 0;
		}
		else
		{
			printf("\n");
		}
		PrintGiovanniNumbers();
		Reset();
	}
	return 0;
}
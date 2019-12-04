#include <stdio.h>


int NCases, NWareHouses, NRoutes, NQueries, NthWareHouse, QTop, QBottom, From, To;
int SizeOfShipment, Taken[50], Distance[50], Q[50], NConnections[50], AdjacencyList[50][50];
char WareHouseList[50][3];


void Reset1()
{
	int i;

	NthWareHouse = 0;
	for (i = 0; i < NWareHouses; i++)
	{
		NConnections[i] = 0;
	}
}

void Reset2()
{
	int i;

	for (i = 0; i < NWareHouses; i++)
	{
		Taken[i] = 0;
	}
}



int GetWareHouseIndex(char WareHouse[])
{
	int i, j;

	for (i = 0; i < NWareHouses; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (WareHouse[j] != WareHouseList[i][j])
			{
				break;
			}
		}
		if (j == 2)
		{
			return i;
		}
	}

	return -1;
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
	Q[QTop] = From;
	Distance[From] = 0;
	Taken[From] = 1;

	while (!IsQEmpty())
	{
		U = Q[QTop];
		QTop++;
		for (i = 0; i < NConnections[U]; i++)
		{
			V = AdjacencyList[U][i];
			if (!Taken[V])
			{
				Distance[V] = Distance[U] + 1;
				Taken[V] = 1;
				if (V == To)
				{
					return;
				}
				QBottom++;
				Q[QBottom] = V;
			}
		}
	}
}


int main()
{
	int i, j;
	char FromWareHouse[3], ToWareHouse[3];

	scanf("%d", &NCases);
	printf("SHIPPING ROUTES OUTPUT\n");
	for (i = 1; i <= NCases; i++)
	{
		scanf("%d %d %d", &NWareHouses, &NRoutes, &NQueries);
		for (j = 0; j < NWareHouses; j++)
		{
			scanf("%s", WareHouseList[j]);
		}

		for (j = 0; j < NRoutes; j++)
		{
			scanf("%s %s", FromWareHouse, ToWareHouse);
			From = GetWareHouseIndex(FromWareHouse);
			To = GetWareHouseIndex(ToWareHouse);
			if (From == To)
			{
				continue;
			}
			AdjacencyList[From][NConnections[From]] = To;
			AdjacencyList[To][NConnections[To]] = From;
			NConnections[From]++;
			NConnections[To]++;
		}

		printf("\nDATA SET  %d\n\n", i);
		for (j = 0; j < NQueries; j++)
		{
			scanf("%d %s %s", &SizeOfShipment, FromWareHouse, ToWareHouse);
			From = GetWareHouseIndex(FromWareHouse);
			To = GetWareHouseIndex(ToWareHouse);
			Reset2();
			BFS();
			if (!Taken[To])
			{
				printf("NO SHIPMENT POSSIBLE\n");
			}
			else
			{
				printf("$%d\n", SizeOfShipment*Distance[To] * 100);
			}
		}
		Reset1();
	}
	printf("\nEND OF OUTPUT\n");
	return 0;
}
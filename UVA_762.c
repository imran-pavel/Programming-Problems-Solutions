#include <stdio.h>
#define MaxCities 1000


int From, To, NPairs, NConnections[MaxCities], NCities, QTop, QBottom, IsFirst, Parent[MaxCities];
int Taken[MaxCities], Q[MaxCities], AdjacencyList[MaxCities][MaxCities];
char Decoy[2], CityList[MaxCities][3];



void Reset1()
{
	int i;

	for (i = 0; i < NCities; i++)
	{
		Taken[i] = 0;
		Parent[i] = -1;
	}
}



void Reset2()
{
	int i;

	for (i = 0; i < NCities; i++)
	{
		NConnections[i] = 0;
	}
	NCities = 0;
}



int GetCityIndex(char City[])
{
	int i, j;

	for (i = 0; i < NCities; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (City[j] != CityList[i][j])
			{
				break;
			}
		}
		if (j == 2)
		{
			return i;
		}
	}

	for (j = 0; j < 2; j++)
	{
		CityList[i][j] = City[j];
	}
	CityList[i][j] = '\0';
	NCities++;
	return i;
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
	Taken[From] = 1;
	Parent[From] = -1;

	while (!IsQEmpty())
	{
		U = Q[QTop];
		QTop++;
		for (i = 0; i < NConnections[U]; i++)
		{
			V = AdjacencyList[U][i];
			if (!Taken[V])
			{
				Parent[V] = U;
				if (V == To)
				{
					return;
				}
				QBottom++;
				Q[QBottom] = V;
				Taken[V] = 1;
			}
		}
	}
}





void printPath()
{
	int i, Output[MaxCities];

	i = 0;
	while (1)
	{
		Output[i++] = To;
		To = Parent[To];
		if (To == -1)
		{
			break;
		}
	}
	for ( i--;i>0; i--)
	{
		printf("%s %s\n", CityList[Output[i]], CityList[Output[i-1]]);
	}
}



int main()
{
	int i;
	char FromCity[3], ToCity[3];

	IsFirst = 1;
	while (scanf("%d", &NPairs) == 1)
	{
		gets(Decoy);
		for (i = 0; i < NPairs; i++)
		{
			scanf("%s %s", FromCity, ToCity);
			From = GetCityIndex(FromCity);
			To = GetCityIndex(ToCity);
			AdjacencyList[From][NConnections[From]] = To;
			AdjacencyList[To][NConnections[To]] = From;
			NConnections[From]++;
			NConnections[To]++;
		}
		scanf("%s %s", FromCity, ToCity);
		From = GetCityIndex(FromCity);
		To = GetCityIndex(ToCity);
		Reset1();
		BFS();
		if (IsFirst)
		{
			IsFirst = 0;
		}
		else
		{
			printf("\n");
		}
		if (Parent[To] == -1)
		{
			printf("No route\n");
		}
		else
		{
			printPath();
		}
		Reset2();
	}
	return 0;
}
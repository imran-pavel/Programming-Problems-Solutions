#include <stdio.h>

char Decoy[2], From[1000000], To[1000000], Parent[26], AdjacencyList[26][25];
int NCases, NRoads, NQueries, NConnectedCities[26];
int Taken[26], Q[26];

void Reset1()
{
	int i;

	for (i = 0; i < 26; i++)
	{
		NConnectedCities[i] = 0;
	}
}

void Reset2()
{
	int i;

	for (i = 0; i < 26; i++)
	{
		Taken[i] = 0;
	}
}


int IsQEmpty(int QTop, int QBottom)
{
	if (QTop > QBottom)
	{
		return 1;
	}
	return 0;
}



void BFS()
{
	int i, QTop, QBottom;
	char NewSource;

	QTop = QBottom = 0;
	Q[QTop] = From[0]-'A';
	Parent[From[0] - 'A'] = 'a';
	Taken[From[0] - 'A'] = 1;

	while (!IsQEmpty(QTop, QBottom))
	{
		NewSource = Q[QTop];
		QTop++;

		for (i = 0; i < NConnectedCities[NewSource]; i++)
		{
			if (!Taken[AdjacencyList[NewSource][i]])
			{
				Parent[AdjacencyList[NewSource][i]] = NewSource;
				if (AdjacencyList[NewSource][i] == To[0] - 'A')
				{
					return;
				}
				QBottom++;
				Q[QBottom] = AdjacencyList[NewSource][i];
				Taken[AdjacencyList[NewSource][i]] = 1;
			}
		}
	}
}



void PrintPath(int Destination)
{
	int i;
	char Output[27];

	i = 0;
	while (Destination != 'a')
	{
		Output[i] = Destination+'A';
		Destination = Parent[Destination];
		i++;
	}

	i--;
	while (i > -1)
	{
		printf("%c", Output[i]);
		i--;
	}
	printf("\n");
}




int main()
{
	int i, j, IsFirst = 1;

	scanf("%d", &NCases);
	gets(Decoy);
	for (i = 0; i < NCases; i++)
	{
		gets(Decoy);
		Reset1();
		scanf("%d %d", &NRoads, &NQueries);
		gets(Decoy);

		for (j = 0; j < NRoads; j++)
		{
			scanf("%s %s", From, To);
			AdjacencyList[From[0]-'A'][NConnectedCities[From[0] - 'A']] = To[0]-'A';
			AdjacencyList[To[0]-'A'][NConnectedCities[To[0] - 'A']] = From[0]-'A';
			NConnectedCities[From[0] - 'A']++;
			NConnectedCities[To[0] - 'A']++;
		}
		if (IsFirst)
		{
			IsFirst = 0;
		}
		else
		{
			printf("\n");
		}
		for (j = 0; j < NQueries; j++)
		{
			scanf("%s %s", From, To);
			Reset2();
			BFS();
			PrintPath(To[0]-'A');
		}
	}
	return 0;
}
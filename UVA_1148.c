#include <stdio.h>


int NCases, NCamarades, NthCamarade, Source, Destination, NCamaradesList[100000], CamaradesList[100000][100];
int Q[100000], Taken[100000], Distance[100000];

void Reset()
{
	int i;

	for (i = 0; i < NCamarades; i++)
	{
		Taken[i] = Distance[i] = 0;
	}
}


int IsQEmpty(int Qtop, int QBottom)
{
	if (Qtop > QBottom)
	{
		return 1;
	}
	return 0;
}


void BFS()
{
	int i, QTop, QBottom, NewSource;

	QTop = QBottom = 0;
	Q[QTop] = Source;

	while (!IsQEmpty(QTop, QBottom))
	{
		NewSource = Q[QTop];
		QTop++;

		for (i = 0; i < NCamaradesList[NewSource]; i++)
		{
			if (!Taken[CamaradesList[NewSource][i]])
			{
				Distance[CamaradesList[NewSource][i]] = Distance[NewSource] + 1;
				if (CamaradesList[NewSource][i] == Destination)
				{
					return;
				}
				QBottom++;
				Q[QBottom] = CamaradesList[NewSource][i];
				Taken[CamaradesList[NewSource][i]] = 1;
			}
		}
	}
}


int main()
{
	int i, j, k, IsFirst = 1;

	scanf("%d", &NCases);
	for (i = 0; i < NCases; i++)
	{
		scanf("%d", &NCamarades);
		for (j = 0; j < NCamarades; j++)
		{
			scanf("%d %d", &NthCamarade, &NCamaradesList[j]);
			for (k = 0; k < NCamaradesList[j]; k++)
			{
				scanf("%d", &CamaradesList[NthCamarade][k]);
			}
		}
		scanf("%d %d", &Source, &Destination);
		Reset();
		BFS();
		if (IsFirst)
		{
			IsFirst = 0;
		}
		else
		{
			printf("\n");
		}
		printf("%d %d %d\n", Source, Destination, Distance[Destination]-1);
	}
	return 0;
}
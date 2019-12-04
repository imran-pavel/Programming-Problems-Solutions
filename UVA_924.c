#include <stdio.h>

int NEmployees, MaxBoom, OnDay;
int Q[35000], NFriends[2500], Taken[2500], Day[2500], FriendsList[2500][14], DayBoomCount[2500];


void Reset()
{
	int i;

	MaxBoom = -1;
	for (i = 0; i < 2500; i++)
	{
		Taken[i] = 0;
		Day[i] = 0;
		DayBoomCount[i] = 0;
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



void BFS(int Source)
{
	int i, QTop, QBottom, NewSource;

	QTop = QBottom = 0;
	Q[QTop] = Source;
	Taken[Source] = 1;

	while (!IsQEmpty(QTop, QBottom))
	{
		NewSource = Q[QTop];
		QTop++;
		for (i = 0; i < NFriends[NewSource]; i++)
		{
			if (!Taken[FriendsList[NewSource][i]])
			{
				QBottom++;
				Q[QBottom] = FriendsList[NewSource][i];
				Taken[FriendsList[NewSource][i]] = 1;
				Day[FriendsList[NewSource][i]] = Day[NewSource] + 1;
				DayBoomCount[Day[FriendsList[NewSource][i]]]++;
				if (DayBoomCount[Day[FriendsList[NewSource][i]]] > MaxBoom)
				{
					MaxBoom = DayBoomCount[Day[FriendsList[NewSource][i]]];
					OnDay = Day[FriendsList[NewSource][i]];
				}
			}
		}
	}
}




int main()
{
	int i, j, NCases, Source;

	while (scanf("%d", &NEmployees) == 1)
	{
		for (i = 0; i < NEmployees; i++)
		{
			scanf("%d", &NFriends[i]);
			for (j = 0; j < NFriends[i]; j++)
			{
				scanf("%d", &FriendsList[i][j]);
			}
		}

		scanf("%d", &NCases);
		for (i = 0; i < NCases; i++)
		{
			scanf("%d", &Source);
			Reset();
			BFS(Source);
			if (MaxBoom == -1)
			{
				printf("0\n");
			}
			else
			{
				printf("%d %d\n", MaxBoom, OnDay);
			}
		}
	}
	return 0;
}
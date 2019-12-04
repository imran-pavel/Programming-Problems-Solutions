#include <stdio.h>
#include <math.h>
#define MaxNodes 400000
#define MaxDimension 210


int NRows, NColumns, NBlockedPositions, SourceX, SourceY, AdjacencyList[MaxDimension][MaxDimension];
int NJigglyPuffs, QTop, QBottom, LoudNess, QX[MaxNodes], QY[MaxNodes];
double Distance[MaxDimension][MaxDimension];
int Taken[MaxDimension][MaxDimension];

void Reset1()
{
	int i, j;

	for (i = 1; i <= NRows; i++)
	{
		for (j = 1; j <= NColumns; j++)
		{
			AdjacencyList[i][j] = 0;
		}
	}
}



void Reset2()
{
	int i, j;

	for (i = 1; i <= NRows; i++)
	{
		for (j = 1; j <= NColumns; j++)
		{
			Taken[i][j] = 0;
		}
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



void MarkBlockedPositions()
{
	int UX, UY;

	QTop = QBottom = 0;
	QX[QTop] = SourceX;
	QY[QTop] = SourceY;
	Distance[SourceX][SourceY] = 0;
	Taken[SourceX][SourceY] = 1;

	while (!IsQEmpty())
	{
		UX = QX[QTop];
		UY = QY[QTop];
		QTop++;
		
		AdjacencyList[UX][UY] = -1;
		if (UY + 1 <= NColumns && !Taken[UX][UY + 1])
		{
			Distance[UX][UY + 1] = sqrt((SourceX - UX)*(SourceX - UX) + (SourceY - (UY + 1))*(SourceY - (UY + 1)));
			if (Distance[UX][UY + 1] <= LoudNess)
			{
				QBottom++;
				QX[QBottom] = UX;
				QY[QBottom] = UY + 1;
			}
			Taken[UX][UY + 1] = 1;
		}
		if (UX + 1 <= NRows && !Taken[UX+1][UY])
		{
			Distance[UX + 1][UY] = sqrt((SourceX - (UX + 1))*(SourceX - (UX + 1)) + (SourceY - UY)*(SourceY - UY));
			if (Distance[UX + 1][UY] <= LoudNess)
			{
				QBottom++;
				QX[QBottom] = UX + 1;
				QY[QBottom] = UY;
			}
			Taken[UX + 1][UY] = 1;
		}
		if (UY - 1 >= 1 && !Taken[UX][UY - 1])
		{
			Distance[UX][UY - 1] = sqrt((SourceX - UX)*(SourceX - UX) + (SourceY - (UY - 1))*(SourceY - (UY - 1)));
			if (Distance[UX][UY - 1] <= LoudNess)
			{
				QBottom++;
				QX[QBottom] = UX;
				QY[QBottom] = UY - 1;
			}
			Taken[UX][UY - 1] = 1;
		}
		if (UX - 1 >= 1 && !Taken[UX - 1][UY])
		{
			Distance[UX - 1][UY] = sqrt((SourceX - (UX - 1))*(SourceX - (UX - 1)) + (SourceY - UY)*(SourceY - UY));
			if (Distance[UX - 1][UY] <= LoudNess)
			{
				QBottom++;
				QX[QBottom] = UX - 1;
				QY[QBottom] = UY;
			}
			Taken[UX - 1][UY] = 1;
		}
	}
}



void BFS()
{
	int UX, UY;

	QTop = QBottom = 0;
	QX[QTop] = SourceX;
	QY[QTop] = SourceY;
	Distance[SourceX][SourceY] = 0;
	Taken[SourceX][SourceY] = 1;

	while (!IsQEmpty())
	{
		UX = QX[QTop];
		UY = QY[QTop];
		QTop++;

		if (UY + 1 <= NColumns && !Taken[UX][UY+1] && AdjacencyList[UX][UY+1] != -1)
		{
			Distance[UX][UY + 1] = Distance[UX][UY] + 1;
			QBottom++;
			QX[QBottom] = UX;
			QY[QBottom] = UY + 1;
			Taken[UX][UY + 1] = 1;
		}

		if (UX + 1 <= NRows && !Taken[UX + 1][UY] && AdjacencyList[UX + 1][UY] != -1)
		{
			Distance[UX + 1][UY] = Distance[UX][UY] + 1;
			QBottom++;
			QX[QBottom] = UX + 1;
			QY[QBottom] = UY;
			Taken[UX + 1][UY] = 1;
		}
		if (UY - 1 >= 1 && !Taken[UX][UY - 1] && AdjacencyList[UX][UY - 1] != -1)
		{
			Distance[UX][UY - 1] = Distance[UX][UY] + 1;
			QBottom++;
			QX[QBottom] = UX;
			QY[QBottom] = UY - 1;
			Taken[UX][UY - 1] = 1;
		}
		if (UX - 1 >= 1 && !Taken[UX - 1][UY] && AdjacencyList[UX - 1][UY] != -1)
		{
			Distance[UX - 1][UY] = Distance[UX][UY] + 1;
			QBottom++;
			QX[QBottom] = UX - 1;
			QY[QBottom] = UY;
			Taken[UX - 1][UY] = 1;
		}
	}
}


int main()
{
	int i;

	while (scanf("%d %d", &NRows, &NColumns) == 2)
	{
		if (!NRows && !NColumns)
		{
			break;
		}
		Reset1();
		scanf("%d", &NBlockedPositions);
		for (i = 1; i <= NBlockedPositions; i++)
		{
			scanf("%d %d", &SourceX, &SourceY);
			AdjacencyList[SourceX][SourceY] = -1;
		}
		scanf("%d", &NJigglyPuffs);
		for (i = 1; i <= NJigglyPuffs; i++)
		{
			scanf("%d %d %d", &SourceX, &SourceY, &LoudNess);
			Reset2();
			MarkBlockedPositions();
		}

		if (AdjacencyList[1][1] == -1)
		{
			printf("Impossible.\n");
		}
		else
		{
			SourceX = SourceY = 1;
			Reset2();
			BFS();
			if (Taken[NRows][NColumns])
			{
				printf("%d\n", (int)Distance[NRows][NColumns]);
			}
			else
			{
				printf("Impossible.\n");
			}
		}
	}
	return 0;
}
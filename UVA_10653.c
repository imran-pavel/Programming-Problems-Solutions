#include <stdio.h>

int NRows, NColumns, NBombRows, SourceX, SourceY, DestinationX, DestinatinoY;
int QX[1000000], QY[1000000], Grid[1000][1000];

void Reset()
{
	int i, j;

	for (i = 0; i < NRows; i++)
	{
		for (j = 0; j < NColumns; j++)
		{
			Grid[i][j] = 0;
		}
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
	int QTop, QBottom, Ux, Uy;

	QTop = QBottom = 0;
	QX[QTop] = SourceX;
	QY[QTop] = SourceY;

	while (!IsQEmpty(QTop, QBottom))
	{
		Ux = QX[QTop];
		Uy = QY[QTop];

		QTop++;

		if (Uy + 1 < NColumns)
		{
			if (!Grid[Ux][Uy + 1])
			{
				QBottom++;
				QX[QBottom] = Ux;
				QY[QBottom] = Uy + 1;

				Grid[Ux][Uy + 1] = Grid[Ux][Uy] + 1;
			}
		}

		if (Ux - 1 >= 0)
		{
			if (!Grid[Ux - 1][Uy])
			{
				QBottom++;
				QX[QBottom] = Ux-1;
				QY[QBottom] = Uy;

				Grid[Ux - 1][Uy] = Grid[Ux][Uy] + 1;
			}
		}

		if (Uy - 1 >= 0)
		{
			if (!Grid[Ux][Uy - 1])
			{
				QBottom++;
				QX[QBottom] = Ux;
				QY[QBottom] = Uy - 1;

				Grid[Ux][Uy - 1] = Grid[Ux][Uy] + 1;
			}
		}

		if (Ux + 1 < NRows)
		{
			if (!Grid[Ux+1][Uy])
			{
				QBottom++;
				QX[QBottom] = Ux+1;
				QY[QBottom] = Uy;

				Grid[Ux + 1][Uy] = Grid[Ux][Uy] + 1;
			}
		}
	}
}





int main()
{
	int i, j, NthRow, NthColumn, NBombs;

	while (1)
	{
		scanf("%d %d", &NRows, &NColumns);
		if (NRows == 0 && NColumns == 0)
		{
			break;
		}

		Reset();
		scanf("%d", &NBombRows);
		for (i = 0; i < NBombRows; i++)
		{
			scanf("%d %d", &NthRow, &NBombs);
			for (j = 0; j < NBombs; j++)
			{
				scanf("%d", &NthColumn);
				Grid[NthRow][NthColumn] = -1;
			}
		}

		scanf("%d %d", &SourceX, &SourceY);
		scanf("%d %d", &DestinationX, &DestinatinoY);

		BFS();
		printf("%d\n", Grid[DestinationX][DestinatinoY]);
	}
	return 0;
}
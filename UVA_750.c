#include <stdio.h>

int FixedRow, NthSolution, FixedColumn, NCases, IsFirst, QueenPositions[9];



int AbsoluteValue(int Value)
{
	if (Value < 0)
	{
		return -Value;
	}
	return Value;
}




int IsSafeToPlace(int X, int Y)
{
	int i;

	if (FixedRow == X || FixedColumn == Y || AbsoluteValue(FixedRow - X) == AbsoluteValue(FixedColumn - Y))
	{
		return 0;
	}

	for (i = 1; i < Y; i++)
	{
		if (QueenPositions[i] == X || AbsoluteValue(X - QueenPositions[i]) == AbsoluteValue(i - Y))
		{
			return 0;
		}
	}

	return 1;
}


void Print()
{
	int i;

	
	printf("%2d      ", ++NthSolution);
	for (i = 1; i < 8; i++)
	{
		printf("%d ", QueenPositions[i]);
	}
	printf("%d\n", QueenPositions[i]);
}




void BackTrack(int NthQueen)
{
	if (NthQueen == 9)
	{
		Print();
		return;
	}

	int i;

	if (NthQueen == FixedColumn)
	{
		BackTrack(NthQueen + 1);
		return;
	}

	for (i = 1; i <= 8; i++)
	{
		if (IsSafeToPlace(i,NthQueen))
		{
			QueenPositions[NthQueen] = i;
			BackTrack(NthQueen + 1);
		}
	}
}




int main()
{
	int i;

	scanf("%d", &NCases);
	IsFirst = 1;
	for (i = 0; i < NCases; i++)
	{
		scanf("%d %d", &FixedRow, &FixedColumn);
		QueenPositions[FixedColumn] = FixedRow;
		NthSolution = 0;
		if (IsFirst)
		{
			IsFirst = 0;
		}
		else
		{
			printf("\n");
		}
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		BackTrack(1);
	}
	return 0;
}
#include <stdio.h>
#include <math.h>

int NPegs, Output[51], TopBall[51];


void Reset()
{
	int i;

	for (i = 1; i < 51; i++)
	{
		TopBall[i] = 0;
	}
}



void PlaceBallsInNPegs()
{
	int i, j;

	for (i = 1;; i++)
	{
		for (j = 1; j <= NPegs; j++)
		{
			if (!TopBall[j])
			{
				TopBall[j] = i;
				break;
			}

			int Sum, SqRoot;

			Sum = TopBall[j] + i;
			SqRoot = sqrt(Sum);
			if (SqRoot*SqRoot == Sum)
			{
				TopBall[j] = i;
				break;
			}

		}

		if (j > NPegs)
		{
			break;
		}
	}

	Output[NPegs] = i-1;
}




void PlaceBalls()
{
	int i;

	for (i = 1; i < 51; i++)
	{
		Reset();
		NPegs = i;
		PlaceBallsInNPegs();
	}
}



int main()
{
	int NCases;

	PlaceBalls();

	

	
	scanf("%d", &NCases);
	while (NCases--)
	{
		scanf("%d", &NPegs);
		printf("%d\n", Output[NPegs]);
	}
	
	
	return 0;
}
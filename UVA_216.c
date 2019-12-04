

#include <stdio.h>
#include <math.h>

int NComputers, Taken[8];
int InputX[8], OutputX[8], LastOutputX[8];
int InputY[8], OutputY[8], LastOutputY[8];
double Min, Distances[8], OutputDistances[8];


void Reset()
{
	int i;

	for (i = 0; i < 8; i++)
	{
		Taken[i] = 0;
	}
}



double CalculateDistance(int FirstX, int FirstY, int SecondX, int SecondY)
{
	return sqrt((FirstX - SecondX)*(FirstX - SecondX) + (FirstY - SecondY)*(FirstY - SecondY));
}



void Update(int LastDistanceIndex)
{
	int i;

	for (i = 0; i < NComputers; i++)
	{
		LastOutputX[i] = OutputX[i];
		LastOutputY[i] = OutputY[i];
	}

	for (i = 0; i < LastDistanceIndex; i++)
	{
		OutputDistances[i] = Distances[i];
	}
}



void BackTrack(int NthComputer, int LastIndex, double Distance, int CurrentDistanceIndex)
{
	if (NthComputer == NComputers)
	{
		if (Distance < Min)
		{
			Update(CurrentDistanceIndex);
			Min = Distance;
		}
		return;
	}

	int i;
	double CurrentDistance;

	for (i = 0; i < NComputers; i++)
	{
		if (!Taken[i])
		{
			Taken[i] = 1;
			OutputX[NthComputer] = InputX[i];
			OutputY[NthComputer] = InputY[i];
			CurrentDistance = CalculateDistance(InputX[LastIndex], InputY[LastIndex], InputX[i], InputY[i]);
			Distances[CurrentDistanceIndex] = CurrentDistance;
			BackTrack(NthComputer + 1, i, Distance+CurrentDistance, CurrentDistanceIndex+1);
			Taken[i] = 0;
		}
	}
}




int main()
{
	
	int i, NthCase = 0;
	double Total;

	while (1)
	{
		scanf("%d", &NComputers);
		if (!NComputers)
		{
			break;
		}
		for (i = 0; i < NComputers; i++)
		{
			scanf("%d %d", &InputX[i], &InputY[i]);
		}

		Min = 1000;
		for (i = 0; i < NComputers; i++)
		{
			OutputX[0] = InputX[i];
			OutputY[0] = InputY[i];
			Reset();
			Taken[i] = 1;
			BackTrack(1, i, 0, 0);
			Taken[i] = 0;
		}

		NthCase++;
		printf("**********************************************************\n");
		printf("Network #%d\n", NthCase);
		for (Total = i = 0; i < NComputers - 1; i++)
		{
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", LastOutputX[i], LastOutputY[i], LastOutputX[i+1], LastOutputY[i+1], OutputDistances[i]+16);
			Total += OutputDistances[i];
		}
		printf("Number of feet of cable required is %.2lf.\n", Total+(NComputers-1)*16);
	}
	return 0;
}
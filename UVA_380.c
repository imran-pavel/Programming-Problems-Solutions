

#include <stdio.h>

int NRows, OutputPrinted, Count[10000], Forwarded[10000], List[100][4], Indexes[10000][100];



void ResetCount()
{
	int i;

	for (i = 0; i < 10000; i++)
	{
		Count[i] = 0;
	}
}


void PrintExtension(int Extenstion)
{
	if (Extenstion < 10)
	{
		printf("000");
		return;
	}
	else if (Extenstion < 100)
	{
		printf("00");
		return;
	}
	else if (Extenstion < 1000)
	{
		printf("0");
		return;
	}
}



void FindTarget(int Time, int Target1, int Target2)
{
	int i;

	for (i = 0; i < Count[Target2]; i++)
	{
		if (Time >= List[Indexes[Target2][i]][1] && Time <= List[Indexes[Target2][i]][1]+List[Indexes[Target2][i]][2])
		{
			if (Forwarded[List[Indexes[Target2][i]][3]])
			{
				printf("AT ");
				PrintExtension(Time);
				printf("%d CALL TO ",Time);
				PrintExtension(Target1);
				printf("%d", Target1);
				printf(" RINGS 9999\n");
				OutputPrinted = 1;
			}
			else
			{
				Forwarded[Target2] = 1;
				FindTarget(Time, Target1, List[Indexes[Target2][i]][3]);
				Forwarded[Target2] = 0;
			}
			break;
		}
	}
	if (!OutputPrinted)
	{
		printf("AT ");
		PrintExtension(Time);
		printf("%d CALL TO ",Time);
		PrintExtension(Target1);
		printf("%d", Target1);
		printf(" RINGS ");
		PrintExtension(Target2);
		printf("%d\n", Target2);
		OutputPrinted = 1;
	}
}



int main()
{
        int i, j, NCases, Time, Target;
	
	scanf("%d", &NCases);
	printf("CALL FORWARDING OUTPUT\n");
	for (j = 0; j < NCases; j++)
	{
		i = NRows = 0;
		ResetCount();

		while (1)
		{
			scanf("%d", &List[NRows][0]);
			if (!List[NRows][0])
			{
				break;
			}
			scanf("%d %d %d", &List[NRows][1], &List[NRows][2], &List[NRows][3]);
			

			Indexes[List[NRows][0]][Count[List[NRows][0]]] = NRows;
			Count[List[NRows][0]]++;
			NRows++;
		}

		printf("SYSTEM %d\n", j + 1);
		while (1)
		{
			scanf("%d", &Time);
			if (Time == 9000)
			{
				break;
			}
			scanf("%d", &Target);
			OutputPrinted = 0;
			FindTarget(Time, Target, Target);
		}
	}
	printf("END OF OUTPUT\n");

	return 0;
}
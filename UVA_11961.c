#include <stdio.h>
#define MaxDNASequenceLength 15
#define MaxOutputs 9765630

int NCases, DNASequenceLength, Distance, NOutputs;
char Decoy[2], DNASequence[MaxDNASequenceLength], Elements[4], Output[MaxOutputs][MaxDNASequenceLength];


void Set()
{
	Elements[0] = 'A';
	Elements[1] = 'C';
	Elements[2] = 'G';
	Elements[3] = 'T';
}



void PrintDNASequences(int StartIndex, int EndIndex)
{
	int i;

	for (i = StartIndex; i < EndIndex; i++)
	{
		printf("%s\n", Output[i]);
	}
}



void StoreDNASequence()
{
	int i;

	for (i = 0; i < DNASequenceLength; i++)
	{
		Output[NOutputs][i] = DNASequence[i];
	}

	Output[NOutputs][i] = '\0';
	NOutputs++;
}




void Backtrack(int CurrentIndex, int Distance)
{
	if (Distance < 0)
	{
		return;
	}
	if (CurrentIndex >= DNASequenceLength)
	{
		StoreDNASequence();
		return;
	}

	int i, Ran;
	char Hold;

	Hold = DNASequence[CurrentIndex];
	for (Ran = i = 0; i < 4; i++)
	{
		
		if (Hold == Elements[i])
		{
			DNASequence[CurrentIndex] = Hold;
			Backtrack(CurrentIndex + 1, Distance);
		}
		else
		{
			DNASequence[CurrentIndex] = Elements[i];
			Backtrack(CurrentIndex + 1, Distance - 1);
		}
	}
	DNASequence[CurrentIndex] = Hold;
}


void SwapSequences(int FirstSequence, int SecondSequence)
{
	int i;
	char Hold;

	for (i = 0; i < DNASequenceLength; i++)
	{
		Hold = Output[FirstSequence][i];
		Output[FirstSequence][i] = Output[SecondSequence][i];
		Output[SecondSequence][i] = Hold;
	}
}





int FindPositionIndex()
{
	int i, j;

	for (i = 0; i < NOutputs; i++)
	{
		for (j = 0; j < DNASequenceLength; j++)
		{
			if (Output[i][j] > DNASequence[j])
			{
				return i;
			}
		}
	}

	return i;
}



int main()
{
	int i, Mid;

	Set();
	scanf("%d", &NCases);
	for (i = 0; i < NCases; i++)
	{
		scanf("%d %d", &DNASequenceLength, &Distance);
		gets(Decoy);
		gets(DNASequence);

		NOutputs = 0;
		if (Distance <= DNASequenceLength)
		{
			Backtrack(0, Distance);
			Mid = FindPositionIndex();
			printf("%d\n", NOutputs);
			PrintDNASequences(0, NOutputs);
		}
	}
	return 0;
}
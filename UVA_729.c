#include <stdio.h>

int Length, HammingDistance, IsFirst;
char Output[17];



void BackTrack(int IthPosition, int NOnes)
{
	if (NOnes > HammingDistance)
	{
		return;
	}
	if (IthPosition == Length)
	{
		if (NOnes == HammingDistance)
		{
			Output[IthPosition] = '\0';
			printf("%s\n", Output);
		}
		return;
	}
	Output[IthPosition] = '0';
	BackTrack(IthPosition + 1, NOnes);
	Output[IthPosition] = '1';
	BackTrack(IthPosition + 1, NOnes + 1);
}




int main()
{
        int i, NCases;

	scanf("%d", &NCases);
	IsFirst = 1;
	for (i = 0; i < NCases; i++)
	{
		scanf("%d %d", &Length, &HammingDistance);
		if (IsFirst)
		{
			IsFirst = 0;
		}
		else
		{
			printf("\n");
		}
		BackTrack(0, 0);
	}
	return 0;
}
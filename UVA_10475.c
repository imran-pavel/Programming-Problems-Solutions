/*
    Convert all characters to uppercase before doing anything.
    I got WA several times for that.
*/

#include <stdio.h>
#define NMaxTopics 120
#define NMaxLength 120

int NCases, NTopics, NProhibitedPairs, NSpeechTopics, NProhibited[NMaxTopics];
int Output[NMaxTopics], TopicLength[NMaxTopics], ProhibitedIndexes[NMaxTopics][NMaxTopics];
int Taken[NMaxTopics];
char Decoy[2], TopicsList[NMaxTopics][NMaxLength];


void Reset()
{
	int i;

	for (i = 0; i < NTopics; i++)
	{
		NProhibited[i] = 0;
	}
}




int GetTopicLength(char Topic[])
{
	int i;

	for (i = 0;; i++)
	{
		if (Topic[i] == '\0')
		{
			break;
		}
	}

	return i;
}



int GetTopicIndex(char Topic[])
{
	int i, j, CurrentTopicLength;

	CurrentTopicLength = GetTopicLength(Topic);
	for (i = 0; i < NTopics; i++)
	{
		if (CurrentTopicLength == TopicLength[i])
		{
			for (j = 0; j < TopicLength[i]; j++)
			{
				if (Topic[j] != TopicsList[i][j])
				{
					break;
				}
			}
			if (j == TopicLength[i])
			{
				return i;
			}
		}
	}

	return -1;
}


void SwapTopicPositions(int FirstPosition, int SecondPosition)
{
	int i, HoldLength;
	char Hold;

	for (i = 0; i < TopicLength[FirstPosition]; i++)
	{
		Hold = TopicsList[FirstPosition][i];
		TopicsList[FirstPosition][i] = TopicsList[SecondPosition][i];
		TopicsList[SecondPosition][i] = Hold;
	}

	TopicsList[FirstPosition][i] = TopicsList[SecondPosition][i];

	for ( i++; i < TopicLength[SecondPosition]; i++)
	{
		TopicsList[FirstPosition][i] = TopicsList[SecondPosition][i];
	}

	HoldLength = TopicLength[FirstPosition];
	TopicLength[FirstPosition] = TopicLength[SecondPosition];
	TopicLength[SecondPosition] = HoldLength;
	TopicsList[FirstPosition][TopicLength[FirstPosition]] = TopicsList[SecondPosition][TopicLength[SecondPosition]] = '\0';
}



int IsLexicographicallyOrdered(int FirstPosition, int SecondPosition)
{
	int i;

	for (i = 0; i < TopicLength[FirstPosition]; i++)
	{
		if (TopicsList[FirstPosition][i] < TopicsList[SecondPosition][i])
		{
			return 1;
		}
		else if (TopicsList[FirstPosition][i] > TopicsList[SecondPosition][i])
		{
			return 0;
		}
	}

	return 1;
}





void BubbleSort()
{
	int i, j;

	for (i = 0; i < NTopics; i++)
	{
		for (j = i+1; j < NTopics; j++)
		{
			if (TopicLength[i] < TopicLength[j])
			{
				SwapTopicPositions(i, j);
			}
			else if (TopicLength[i] == TopicLength[j])
			{
				if (!IsLexicographicallyOrdered(i, j))
				{
					SwapTopicPositions(i, j);
				}
			}
		}
	}
}




void Convert2UpperCase(char Topic[], int Length)
{
	int i;

	for (i = 0; i < Length; i++)
	{
		if (Topic[i] >= 'a' && Topic[i] <= 'z')
		{
			Topic[i] -= 32;
		}
	}
}



void PrintTopics()
{
	int i;

	for (i = 0; i < NSpeechTopics-1; i++)
	{
		printf("%s ", TopicsList[Output[i]]);
	}
	printf("%s\n", TopicsList[Output[i]]);
}



void Backtrack(int NTopicsTaken, int NextIndex)
{
	if (NTopicsTaken == NSpeechTopics)
	{
		PrintTopics();
		return;
	}

	int i, j, ProhibitedTaken;

	for (i = NextIndex; i < NTopics; i++)
	{
		ProhibitedTaken = 0;
		for (j = 0; j < NProhibited[i]; j++)
		{
			if (Taken[ProhibitedIndexes[i][j]])
			{
				ProhibitedTaken = 1;
				break;
			}
		}
		if (!ProhibitedTaken)
		{
			Output[NTopicsTaken] = i;
			Taken[i] = 1;
			Backtrack(NTopicsTaken + 1, i + 1);
			Taken[i] = 0;
		}
	}
}


int main()
{
	int i, j, FirstTopicIndex, SecondTopicIndex;
	char FirstTopic[NMaxLength], SecondTopic[NMaxLength];

	scanf("%d", &NCases);
	for (i = 1; i <= NCases; i++)
	{
		scanf("%d %d %d", &NTopics, &NProhibitedPairs, &NSpeechTopics);
		gets(Decoy);
		for (j = 0; j < NTopics; j++)
		{
			scanf("%s", TopicsList[j]);
			TopicLength[j] = GetTopicLength(TopicsList[j]);
			Convert2UpperCase(TopicsList[j], TopicLength[j]);
		}
		BubbleSort();
		Reset();
		for (j = 0; j < NProhibitedPairs; j++)
		{
			scanf("%s %s", FirstTopic, SecondTopic);
			Convert2UpperCase(FirstTopic, GetTopicLength(FirstTopic));
			Convert2UpperCase(SecondTopic, GetTopicLength(SecondTopic));
			FirstTopicIndex = GetTopicIndex(FirstTopic);
			SecondTopicIndex = GetTopicIndex(SecondTopic);
			ProhibitedIndexes[FirstTopicIndex][NProhibited[FirstTopicIndex]] = SecondTopicIndex;
			ProhibitedIndexes[SecondTopicIndex][NProhibited[SecondTopicIndex]] = FirstTopicIndex;
			NProhibited[FirstTopicIndex]++;
			NProhibited[SecondTopicIndex]++;
		}
		printf("Set %d:\n", i);
		if (NSpeechTopics <= NTopics)
		{
			Backtrack(0, 0);
		}
		printf("\n");
	}
	return 0;
}
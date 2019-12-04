#include <stdio.h>

int NVariables, IsFirst, Variables[26], Taken[26], AdjacencyList[26][26];
char Output[21], Input[200];


void Reset()
{
    int i, j;

    NVariables = 0;
    for(i=0; i<26; i++)
    {
        Taken[i] = Variables[i] = 0;
        for(j=0; j<26; j++)
        {
            AdjacencyList[i][j] = 0;
        }
    }
}


void CountVariables()
{
    int i;

    NVariables = 0;
    for(i=0; Input[i]; i++)
    {
        if(Input[i]>='a' && Input[i]<='z' && !Variables[Input[i]-'a'])
        {
            NVariables++;
            Variables[Input[i]-'a'] = 1;
        }
    }
}

void SetAdjacencyList()
{
    int i, U, V, FirstLetterTaken, SecondLetterTaken;

    FirstLetterTaken = 0;
    for(i=0; Input[i]; i++)
    {
        if(Input[i]>='a' && Input[i]<='z')
        {
            if(!FirstLetterTaken)
            {
                U = Input[i] - 'a';
                FirstLetterTaken = 1;
                SecondLetterTaken = 0;
            }
            else if(!SecondLetterTaken)
            {
                V = Input[i] - 'a';
                SecondLetterTaken = 1;
                FirstLetterTaken = 0;

                AdjacencyList[U][V] = 1;
            }
        }
    }
}


void BackTrack(int NthIndex)
{
    if(NthIndex==NVariables)
    {
        Output[NthIndex] = '\0';
        printf("%s\n", Output);
        return;
    }
    if(NthIndex>NVariables)
    {
        return;
    }

    int i, j;

    for(i=0; i<26; i++)
    {
        if(Variables[i] && !Taken[i])
        {
            for(j=0; j<26; j++)
            {
                if(AdjacencyList[i][j] && Taken[j])
                {
                    return;
                }
            }

            Output[NthIndex] = i + 'a';
            Taken[i] = 1;
            BackTrack(NthIndex+1);
            Taken[i] = 0;
        }
    }
}


int main()
{
    IsFirst = 1;
    while(gets(Input))
    {
        Reset();
        CountVariables(Input);
        gets(Input);
        SetAdjacencyList();
        if(IsFirst)
        {
            IsFirst = 0;
        }
        else
        {
            printf("\n");
        }
        BackTrack(0);
    }
    return 0;
}

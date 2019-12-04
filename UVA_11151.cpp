#include <stdio.h>
#include <string.h>
#define li long int

char input[1000];
int record[1000][1000];

void initializer(li StringLength)
{
    li i,j;

    for(i=0;i<StringLength;i++)
    {
        for(j=i;j<StringLength;j++)
        {
            record[i][j] = -1;
        }
    }
}

int FindLongestPalinedrome(li StartIndex, li EndIndex)
{
    if(StartIndex > EndIndex) return 0;
    li PLength1, PLength2;
    if(record[StartIndex][EndIndex]!=-1)
    {
        return record[StartIndex][EndIndex];
    }
    if(StartIndex == EndIndex)
    {
        record[StartIndex][EndIndex] = 1;
        return record[StartIndex][EndIndex];
    }
    if(input[StartIndex]==input[EndIndex])
    {
        PLength1 = FindLongestPalinedrome(StartIndex+1,EndIndex-1)+2;
        record[StartIndex][EndIndex] = PLength1;
        return record[StartIndex][EndIndex];
    }
    PLength1 = FindLongestPalinedrome(StartIndex,EndIndex-1);
    PLength2 = FindLongestPalinedrome(StartIndex+1,EndIndex);
    if(PLength1 > PLength2)
    {
        record[StartIndex][EndIndex] = PLength1;
        return record[StartIndex][EndIndex];
    }
    else
    {
        record[StartIndex][EndIndex] = PLength2;
        return record[StartIndex][EndIndex];
    }
}

int main()
{
    li NCase, InputLength;
    char NoUse[2];
    scanf("%ld",&NCase);
    gets(NoUse);

    while(NCase--)
    {
        gets(input);
        InputLength = strlen(input);
        initializer(InputLength);
        if(!InputLength)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n",FindLongestPalinedrome(0,InputLength-1));
        }
    }
    return 0;
}

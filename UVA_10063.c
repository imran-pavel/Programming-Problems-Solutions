#include <stdio.h>


char InputString[26], Decoy[2];
int InputStringLength, IsFirst;



int FindStringLength(char TargetString[])
{
    int i;

    for(i=0; i<26; i++)
    {
        if(TargetString[i] == 0)
        {
            return i;
        }
    }

    return i;
}



void ShiftString(char *CurrentArray, int CurrentArrayLength)
{
    int i;

    for(i=CurrentArrayLength; i>0; i--)
    {
        CurrentArray[i] = CurrentArray[i-1];
    }
}



void PrintString(char OutputString[], int StringLength)
{
    int i;

    OutputString[StringLength] = '\0';
    printf("* %s\n", OutputString);
}




void Bruteforce(char CurrentString[], int CurrentStringLength, int TargetCharacterIndex)
{
    if(CurrentStringLength == InputStringLength)
    {
        CurrentString[CurrentStringLength] = '\0';
        printf("%s\n", CurrentString);
        return;
    }

    if(CurrentStringLength > InputStringLength)
    {
        return;
    }

    ShiftString(CurrentString, CurrentStringLength);
    CurrentString[0] = InputString[TargetCharacterIndex];
    Bruteforce(CurrentString, CurrentStringLength+1, TargetCharacterIndex+1);

    int i;

    for(i=1; i<=CurrentStringLength; i++)
    {
        CurrentString[i-1] = CurrentString[i];
        CurrentString[i] = InputString[TargetCharacterIndex];
        Bruteforce(CurrentString, CurrentStringLength+1, TargetCharacterIndex+1);
    }
}





int main()
{
    char OutputString[26];

    IsFirst = 1;
    while(gets(InputString))
    {
        OutputString[0] = InputString[0];
        InputStringLength = FindStringLength(InputString);


        if(IsFirst)
        {
            IsFirst = 0;
        }
        else
        {
            printf("\n");
        }

        Bruteforce(OutputString, 1, 1);
    }
    return 0;
}

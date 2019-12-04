#include <stdio.h>
#define MaxStringLength 133

char Input[MaxStringLength];


void PrintNCharacters(int N, char Character)
{
    int i;

    for(i=0; i<N; i++)
    {
        printf("%c", Character);
    }
}

int main()
{
    int i, Total, NewLinePrinted;

    while(gets(Input))
    {
        if(Input[0] == '\0')
        {
            printf("\n");
            continue;
        }
        NewLinePrinted = i = 0;
        if(Input[0] == '!')
        {
            printf("\n");
            i = 1;
            NewLinePrinted = 1;
        }
        Total = 0;
        for(; ;i++)
        {
            if(Input[i] == '\0')
            {
                if(!NewLinePrinted)
                {
                    printf("\n");
                }
                break;
            }
            else
            {
                if(Input[i] == '!')
                {
                    printf("\n");
                    NewLinePrinted = 1;
                }
                else
                {
                    if(Input[i] >= '0' && Input[i] <= '9')
                    {
                        Total += (Input[i]-'0');
                    }
                    else
                    {
                        if(Input[i] == 'b')
                        {
                            PrintNCharacters(Total, ' ');
                        }
                        else
                        {
                            PrintNCharacters(Total, Input[i]);
                        }
                        NewLinePrinted = Total = 0;
                    }
                }
            }
        }
    }
    return 0;
}

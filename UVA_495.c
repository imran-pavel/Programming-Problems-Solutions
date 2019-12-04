#include <stdio.h>
#define Limit 5001


char Fibonaccis[Limit][1500];
int FibonacciNumberStartingIndexes[Limit];



void Reset()
{
    int i, j;

    for(i=0; i<Limit; i++)
    {
        for(j=0; j<1100; j++)
        {
            Fibonaccis[i][j] = '0';
        }
    }

    Fibonaccis[0][1] = '@';
    FibonacciNumberStartingIndexes[0] = 0;

    Fibonaccis[1][0] = '1';
    Fibonaccis[1][1] = '@';
    FibonacciNumberStartingIndexes[1] = 0;
}




int GetDigit(int NthNumber, int NthDigit)
{
    if(Fibonaccis[NthNumber][NthDigit] == '@')
    {
        return -1;
    }

    return Fibonaccis[NthNumber][NthDigit] - '0';
}




void CalculateFibonaccis(int NthFibonacci)
{
    if(NthFibonacci>=Limit)
    {
        return;
    }


    int i, SmallerNumberDigit, BiggerNumberDigit, CarryDigit;
    int SmallerNumberNotExhausted, DoNotBreak;

    DoNotBreak = SmallerNumberNotExhausted = 1;
    CarryDigit = i = 0;
    while(DoNotBreak)
    {
        if(SmallerNumberNotExhausted)
        {
            SmallerNumberDigit = GetDigit(NthFibonacci-2, i);
            if(SmallerNumberDigit == -1)
            {
                SmallerNumberNotExhausted = 0;
                SmallerNumberDigit = 0;
            }
        }

        BiggerNumberDigit = GetDigit(NthFibonacci-1, i);
        if(BiggerNumberDigit == -1)
        {
            BiggerNumberDigit = 0;
            DoNotBreak = 0;
        }


        if(DoNotBreak || (!DoNotBreak && CarryDigit))
        {
            Fibonaccis[NthFibonacci][i] = (SmallerNumberDigit+BiggerNumberDigit+CarryDigit) % 10 + '0';
            FibonacciNumberStartingIndexes[NthFibonacci] = i;
            Fibonaccis[NthFibonacci][i+1] = '@';
        }
        else
        {
            FibonacciNumberStartingIndexes[NthFibonacci] = i-1;
            Fibonaccis[NthFibonacci][i] = '@';
        }


        CarryDigit = (SmallerNumberDigit+BiggerNumberDigit+CarryDigit) /10;
        i++;
    }

    CalculateFibonaccis(NthFibonacci+1);
}



void PrintNthFibonacci(int NthFibonacci)
{
    int i;

    for(i=FibonacciNumberStartingIndexes[NthFibonacci]; i>-1; i--)
    {
        printf("%c", Fibonaccis[NthFibonacci][i]);
    }
    printf("\n");
}


int main()
{
    int NthFibonacci;

    Reset();
    CalculateFibonaccis(2);

    while(scanf("%d", &NthFibonacci) == 1)
    {
        printf("The Fibonacci number for %d is ", NthFibonacci);
        PrintNthFibonacci(NthFibonacci);
    }
    return 0;
}

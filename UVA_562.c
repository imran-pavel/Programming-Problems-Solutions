#include <stdio.h>

#define MaxCoins 100
#define MaxValue 50001


int NCoins, Total, Coins[MaxCoins],Storage[MaxCoins][MaxValue];


void Initialize()
{
    int i, j;

    Total = 0;
    for(i=0; i<MaxCoins; i++)
    {
        for(j=0; j<MaxValue; j++)
        {
            Storage[i][j] = -1;
        }
    }
}


int DP( int NThCoin, int CurrentTotal )
{
    if(NThCoin >= NCoins)
    {
        int Difference;

        Difference = (Total - CurrentTotal) - CurrentTotal;

        if( Difference < 0 )
        {
           return -Difference;
        }
        return Difference;
    }


    if(Storage[NThCoin][CurrentTotal] != -1)
    {
        return Storage[NThCoin][CurrentTotal];
    }

    int Difference1, Difference2;

    Difference1 = DP( NThCoin+1, CurrentTotal+Coins[NThCoin] );
    Difference2 = DP( NThCoin+1, CurrentTotal );

    if( Difference1 < Difference2 )
    {
        Storage[NThCoin][CurrentTotal] = Difference1;
        return Storage[NThCoin][CurrentTotal];
    }
    Storage[NThCoin][CurrentTotal] = Difference2;
    return Storage[NThCoin][CurrentTotal];
}



int main()
{
    int i, NCases;

    scanf("%d", &NCases);
    while(NCases--)
    {
        Initialize();
        scanf("%d", &NCoins);
        for(i=0; i<NCoins; i++)
        {
            scanf("%d", &Coins[i]);
            Total += Coins[i];
        }
        printf("%d\n", DP(0,0));
    }
    return 0;
}

#include <cstdio>
#include <iostream>
#define MaxNCoins 50
#define MaxNAmount 1001
#define BIG_NUMBER 100000007

using namespace std;

typedef long long int i64;


i64 NCases, NCoins, TargetAmount;
i64 Coins[MaxNCoins], Limits[MaxNCoins], Storage[MaxNCoins][MaxNAmount];


void Reset()
{
    i64 i, j;

    for(i=0; i<NCoins; i++)
    {
        for(j=0; j<=TargetAmount; j++)
        {
            Storage[i][j] = -1;
        }
    }
}



int DP(i64 NthCoin, i64 CurrentAmount)
{
    if( NthCoin == NCoins )
    {
        if(CurrentAmount == 0)
        {
            return 1;
        }
        return 0;
    }


    if(Storage[NthCoin][CurrentAmount] != -1)
    {
        return Storage[NthCoin][CurrentAmount];
    }


    i64 i, Result;

    Result = 0;
    for(i=1; i<=Limits[NthCoin]; i++)
    {
        if(CurrentAmount-(Coins[NthCoin]*i) < 0)
        {
            break;
        }
        Result += DP(NthCoin+1, CurrentAmount-(Coins[NthCoin]*i));
    }
    Result += DP(NthCoin+1, CurrentAmount);

    Storage[NthCoin][CurrentAmount] = Result % BIG_NUMBER;
    return Storage[NthCoin][CurrentAmount];
}




int main()
{
    i64 i, j, Result;

    cin >> NCases;
    for(i=1; i<=NCases; i++)
    {
        cin >> NCoins >> TargetAmount;
        for(j=0; j<NCoins; j++)
        {
            cin >> Coins[j];
        }
        for(j=0; j<NCoins; j++)
        {
            cin >> Limits[j];
        }
        Reset();
        Result = DP(0, TargetAmount);
        cout << "Case " << i << ": " << Result << "\n";
    }
    return 0;
}

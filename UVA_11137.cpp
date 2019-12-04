#include <cstdio>
#include <iostream>
#define NCoins 21
#define MaxAmount 10000

using namespace std;
typedef long long int i64;


i64 TargetAmount, Coins[NCoins];
i64 Storage[NCoins][MaxAmount];

void Set()
{
    i64 i, j;

    for(i=1; i<=NCoins; i++)
    {
        Coins[i-1] = i * i * i;
        for(j=0; j<MaxAmount; j++)
        {
            Storage[i-1][j] = -1;
        }
    }
}


i64 DP(i64 NthCoin, i64 CurrentAmount)
{
    if(NthCoin == NCoins)
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
    for(i=1; ;i++)
    {
        if(CurrentAmount-(Coins[NthCoin]*i) < 0)
        {
            break;
        }
        Result += DP(NthCoin+1, CurrentAmount-(Coins[NthCoin]*i));
    }

    Result += DP(NthCoin+1, CurrentAmount);

    return Storage[NthCoin][CurrentAmount] = Result;
}



int main()
{
    Set();
    while(cin >> TargetAmount)
    {
        cout << DP(0, TargetAmount) << endl;
    }
    return 0;
}

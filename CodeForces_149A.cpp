#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long int i64;


i64 BruteForce( i64 InchesToGrow, i64 GrowthSoFar, i64 IthMonth, i64 Counter, vector < i64 > &IMonths )
{
    if( InchesToGrow <= GrowthSoFar )
    {
        return Counter;
    }
    if( IthMonth > 11 )
    {
        return -1;
    }

    i64 Ret1, Ret2;

    Ret1 = BruteForce(InchesToGrow, GrowthSoFar+IMonths[IthMonth], IthMonth+1, Counter+1, IMonths);
    Ret2 = BruteForce(InchesToGrow, GrowthSoFar, IthMonth+1, Counter, IMonths);


    if( Ret1 == -1 )
    {
        return Ret2;
    }
    if( Ret2 == -1 )
    {
        return Ret1;
    }
    if( Ret1 < Ret2 )
    {
        return Ret1;
    }
    return Ret2;
}




int main()
{
    i64 InchesToGrow, i, Hold;

    while( cin >> InchesToGrow )
    {
        vector < i64 > IMonths;

        for(i=0; i<12; i++)
        {
            cin >> Hold;
            IMonths.push_back(Hold);
        }

        cout << BruteForce(InchesToGrow, 0, 0, 0, IMonths) << "\n";
    }
    return 0;
}


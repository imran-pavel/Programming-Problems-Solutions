#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <climits>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long int i64;


i64 WeightMatrix[101][101];


i64 CalculateTotal( i64 LastNode )
{
    i64 U, V, Total;

    Total = 0;
    for( U = 1; U <= LastNode; U++ )
    {
        for( V = 1; V <= LastNode; V++ )
        {
            Total += WeightMatrix[U][V];
        }
    }

    return Total;
}


void FloydWarshall( i64 LastNode )
{
    i64 U, V, IntermediateNode;

    for( IntermediateNode = 1; IntermediateNode <= LastNode; IntermediateNode++ )
    {
        for( U = 1; U <= LastNode; U++ )
        {
            for( V = 1; V <= LastNode; V++ )
            {
                if( WeightMatrix[U][V] > WeightMatrix[U][IntermediateNode] + WeightMatrix[IntermediateNode][V] )
                {
                    WeightMatrix[U][V] = WeightMatrix[U][IntermediateNode] + WeightMatrix[IntermediateNode][V];
                }
            }
        }
    }
}


int main()
{
    i64 U, V, NewNumber, NCase = 0;

    while(true)
    {
        cin >> U >> V;
        if( !U && !V )
        {
            break;
        }

        NewNumber = 0;
        map < i64, i64 > NumberMapped;
        fill(&WeightMatrix[0][0], &WeightMatrix[0][0]+101*101, 1000);

        while(U && V)
        {
            if( !NumberMapped[U] )
            {
                NumberMapped[U] = ++NewNumber;
                WeightMatrix[NumberMapped[U]][NumberMapped[U]] = 0;
            }
            if( !NumberMapped[V] )
            {
                NumberMapped[V] = ++NewNumber;
                WeightMatrix[NumberMapped[V]][NumberMapped[V]] = 0;
            }
            WeightMatrix[NumberMapped[U]][NumberMapped[V]] = 1;

            cin >> U >> V;
        }

        FloydWarshall(NewNumber);

        cout << "Case " << ++NCase << ": average length between pages = " << fixed << setprecision(3) << ( (double) CalculateTotal(NewNumber) / ( NewNumber * ( NewNumber - 1) )) << " clicks\n";
    }

    return 0;
}

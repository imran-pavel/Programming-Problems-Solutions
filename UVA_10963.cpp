#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int i, j, nCases, nPairs, n1, n2, gap;
    bool possible, firstCase;

    cin >> nCases;
    firstCase = true;
    for(i=0; i<nCases; i++)
    {
        cin >> nPairs;
        cin >> n1 >> n2;
        gap = abs(n1-n2);
        possible = true;
        for(j=0; j<nPairs-1; j++)
        {
            cin >> n1 >> n2;
            if(gap != abs(n1-n2))
            {
                possible = false;
            }
        }
        if(firstCase)
        {
            firstCase = false;
        }
        else
        {
            cout << "\n";
        }
        if(possible)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}

#include <stdio.h>
#include <iostream>
#define li long int

using namespace std;

bool Checker(li num)
{
    li i;

    for(i=1;;)
    {
        if( num == i) return false;
        if( num < i ) return true;
        i = i + ( i + 1 );
    }

}


int main()
{
    li n;

    while(true)
    {
        cin >> n;
        if(!n) break;
        if(Checker(n))
        {
            cout<<"Alice\n";
        }
        else
        {
            cout<<"Bob\n";
        }
    }
    return 0;
}

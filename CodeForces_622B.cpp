#include <cstdio>
#include <iostream>

using namespace std;

typedef long long int i64;


int main()
{
    i64 Hour, Minute, AdditionalMinutes;
    char Colon;

    while( cin >> Hour >> Colon >> Minute )
    {
        cin >> AdditionalMinutes;
        Minute += AdditionalMinutes;
        Hour += ( Minute/60 );
        Minute %= 60;
        Hour %= 24;
        if( Hour < 10 )
        {
            cout << "0";
        }
        cout << Hour << ":";
        if( Minute < 10 )
        {
            cout << "0";
        }
        cout << Minute << "\n";
    }
    return 0;
}

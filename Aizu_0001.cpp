#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int i,ar[10];
    for(i=0;i<10;i++)
        {
            cin>>ar[i];
        }
    sort(ar,ar+10);
    for(i=9;i>=7;i--)
        {
            cout<<ar[i]<<'\n';
        }
}

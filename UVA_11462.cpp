#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int ar[2000000];

int main()
{
    int n,i;
    while(cin>>n)
        {
            if(n==0) break;
            for(i=0;i<n;i++)
                {
                    cin>>ar[i];
                }
            sort(ar,ar+n);
            for(i=0;i<n-1;i++)
                {
                    cout<<ar[i]<<' ';
                }
            cout<<ar[i]<<endl;
        }
    return 0;
}

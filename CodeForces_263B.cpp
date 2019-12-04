#include <iostream>
#include <algorithm>

using namespace std;

int ar[50];

int main()
{
    int n,k,i,x=-1,j;

    while(cin>>n>>k)
        {
            for(i=0;i<n;i++)
                {
                    cin>>ar[i];
                }
            sort(ar,ar+n);
            if(k>n) cout<<x<<'\n';
            else
                {
                    for(i=n-1,j=1;i>-1;i--,j++)
                        {
                            if(j==k)
                                {
                                    cout<<ar[i]<<' '<<ar[i]<<'\n';
                                }
                        }
                }
        }
    return 0;
}

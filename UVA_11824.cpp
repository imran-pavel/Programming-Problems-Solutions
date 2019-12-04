#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long int ar[41];

int main()
{
    long long int n,i,j,total,temp,cost,k;

    cin>>n;
    for(i=1;i<=n;i++)
        {
            for(k=-1,j=1;;j++)
                {
                    cin>>cost;
                    if(cost==0) break;
                    ar[++k]=cost;
                }
            sort(ar,ar+(k+1));
            total=0;
            for(j=1;k>-1;k--,j++)
                {
                    temp=pow(ar[k],j);
                    total=total+2*temp;
                }
            if(total>5000000) cout<<"Too expensive\n";
            else cout<<total<<'\n';
        }
    return 0;
}

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long int a[1000000],prev_total[1000000];

int main()
{
    long long int n,n_case,k,c,sum;

    cin>>n_case;
    for(int l=1;l<=n_case;l++)
    {
        sum=0;
        cin>>k>>c>>n>>a[0];
        for(int i=1;i<n;i++)
        {
            a[i] = (k*a[i-1]+c)%1000007;
            //cout<<a[i]<<" ";
        }
        //cout<<"\n";
        sort(a,a+n);
        for(int i=n-1;i>-1;i--)
        {
            if(i+1>=n)
            {
                prev_total[i]=0;
            }
            else
            {
                prev_total[i]=a[i+1]+prev_total[i+1];
            }
        }
        for(int i=0;i<n;i++)
        {
            sum=sum+abs((a[i]*(n-1-i))-prev_total[i]);
        }
        cout<<"Case "<<l<<": "<<sum<<"\n";
    }
    return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

lli ar[1000000],qa[1000000];

lli lo_pos(lli mid, lli item)
{
    lli temp=mid,temp2;

    while(1)
        {
            temp2=temp;
            temp--;
            if(temp<0) return ++temp2;
            if(ar[temp]!=item) return ++temp2;
        }
}

lli binary_search(lli item, lli lim)
{
    lli low,high,mid,temp;

    low=0;
    high=lim-1;

    while(low<=high)
        {
            mid=(low+high)/2;
            //cout<<"ar["<<mid<<"]="<<ar[mid]<<'\n';
            if(ar[mid]==item)
                {
                    return lo_pos(mid,item);
                }
            else if(ar[mid]<item) low=mid+1;
            else high=mid-1;
        }
    return -1;
}

int main()
{
    lli n,q,i,item,j,temp;

    for(j=1;;j++)
        {
            cin>>n>>q;
            if(n==0 && q==0) break;
            for(i=0;i<n;i++) cin>>ar[i];
            sort(ar,ar+n);
            //for(i=0;i<n;i++) cout<<ar[i]<<endl;
            for(i=0;i<q;i++)
                {
                    cin>>qa[i];
                }
            cout<<"CASE# "<<j<<":\n";
            for(i=0;i<q;i++)
                {
                    item=qa[i];
                    temp=binary_search(item,n);
                    if(temp==-1)
                        {
                            cout<<item<<' '<<"not found\n";
                        }
                    else cout<<item<<" found at "<<temp<<'\n';
                }
        }

    return 0;
}
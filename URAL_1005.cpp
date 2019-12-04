#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#define lli long int

using namespace std;


lli weights[21],n_w,min_difference;

void brute_force(lli weights_index, lli p1, lli p2)
{
    lli result;
    if(weights_index>=n_w)
    {
        result=p1-p2;
        if(result<0) result=result*-1;
        if(result<min_difference) min_difference=result;
        return;
    }
    brute_force(weights_index+1,p1+weights[weights_index],p2);
    brute_force(weights_index+1,p1,p2+weights[weights_index]);
}

int main()
{
    lli i;

    while(cin>>n_w)
    {
        memset(weights,0,sizeof(weights));
        min_difference=1000000;
        for(i=0;i<n_w;i++)
        {
            cin>>weights[i];
        }
        brute_force(0,0,0);
        cout<<min_difference<<'\n';
    }
    return 0;
}

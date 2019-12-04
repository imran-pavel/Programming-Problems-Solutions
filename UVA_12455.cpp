#include <iostream>
#include <algorithm>

using namespace std;

int bars[20],p;

int brute_force(int index, int rem)
{
    if(index>=p) return 0;
    if(rem-bars[index]<0) return 0;
    if(rem-bars[index]==0) return 1;
    else
        {
            int check1,check2;
            check1=brute_force(index+1,rem-bars[index]);
            check2=brute_force(index+1,rem);
            if(check1||check2) return 1;
            return 0;
        }
}

int main()
{
    int n,num,i;

    cin>>n;

    while(n--)
        {
            cin>>num>>p;
            for(i=0;i<p;i++)
                {
                    cin>>bars[i];
                }
            if(num!=0)
                {
                    sort(bars,bars+p);
                    if(brute_force(0,num)) cout<<"YES\n";
                    else cout<<"NO\n";
                }
            else cout<<"YES\n";
        }
    return 0;
}

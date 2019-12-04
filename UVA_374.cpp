#include <stdio.h>

long long int b,p,m;

long long int R(long long int b, long long int p, long long int m)
{
    int temp;
    if(p==0) return 1;
    else if(p%2==0)
        {
            temp=R(b,p/2,m);
            return ((temp%m)*(temp%m))%m;
        }
    else return ((b%m)*(R(b,p-1,m)%m))%m;
}

int main()
{
    while(scanf("%lld %lld %lld",&b,&p,&m)==3)
        {
            printf("%lld\n",R(b,p,m));
        }
    return 0;
}

#include <stdio.h>
#include <math.h>

int main()
{
    long long int i,n,s,temp,temp2;

    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        {
            scanf("%lld",&s);
            temp=(8*s)+1;
            temp=sqrt(temp);
            temp=(temp-1)/2;
            printf("%lld\n",temp);
        }
    return 0;
}

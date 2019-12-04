#include <string.h>
#include <stdio.h>
#include <math.h>

int main()
{
    long long int n,sum,i;
    while(scanf("%lld",&n)!=EOF)
        {
            sum=0;
            for(i=1;i<=n;i++)
                {
                    long long int c=pow(i,3);
                    sum=sum+c;
                }
            printf("%lld\n",sum);
}
return 0;
}

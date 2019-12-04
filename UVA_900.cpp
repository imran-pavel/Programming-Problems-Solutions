#include <stdio.h>
#include <string.h>

long long int fibonacci(long long int n)
{
    if(n==1||n==0) return 1;
    else return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    long long int n,ans;
    for(;;)
        {
            scanf("%lld",&n);
            if(n==0) break;
            ans=fibonacci(n);
            printf("%lld\n",ans);
        }
    return 0;
}

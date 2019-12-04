#include <stdio.h>
#include <math.h>
int main()
{
    long long int num,a,b;
    while(scanf("%lld %lld",&a,&b)!=EOF)
        {
            num=fabs(b-a);
            printf("%lld\n",num);
        }
    return 0;
}

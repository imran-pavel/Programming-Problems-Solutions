#include <stdio.h>
int main()
{
    long long int a,b,c,n,i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            if((a+b)<=c||(b+c)<=a||(c+a)<=b)
                {
                    printf("Case %lld: Invalid\n",i);
                }
            else if(a==b && b==c)
                {
                    printf("Case %lld: Equilateral\n",i);
                }
            else if(a!=b && b!=c && c!=a)
                {
                    printf("Case %lld: Scalene\n",i);
                }
            else
                {
                    printf("Case %lld: Isosceles\n",i);
                }
        }
    return 0;
}
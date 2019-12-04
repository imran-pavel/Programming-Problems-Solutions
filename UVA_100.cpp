#include <stdio.h>

long long int length=1;

long long int cycle_length(long long int n)
{
    if(n==1) return length;
    else if(n%2==0)
        {
            length++;
            return cycle_length(n/2);
        }
    else
        {
            length++;
            return cycle_length(3*n+1);
        }
}

int main()
{
    long long int m,n,a,b,i,res,max;
    while(scanf("%lld %lld",&m,&n)!=EOF)
        {
            if(m>n)
                {
                    a=m;
                    b=n;
                }
            else
                {
                    a=n;
                    b=m;
                }
            for(i=b;i<=a;i++)
                {
                    res=cycle_length(i);
                    if(i==b) max=res;
                    else if(i>b)
                        {
                            if(max<res)
                                {
                                    max=res;
                                }
                        }
                    length=1;
                }
            printf("%lld %lld %lld\n",m,n,max);
        }
    return 0;
}

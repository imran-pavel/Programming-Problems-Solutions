#include <stdio.h>
#include <math.h>

long long int happy_or_not(long long int a)
{
    long long int total=0;
    for(;;)
        {
            total=total+pow((a%10),2);
            if(a%10==0 && a/10==0)
                {
                    if(total<10) break;
                    else
                        {
                            a=total;
                            total=0;
                        }
                }
            else a=a/10;
        }
    if(total==1) return 1;
    else return 0;
}

int main()
{
    long long int n,i,number,c,d;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        {
            scanf("%lld",&number);
            d=number;
            if(number<10)
                {
                    number=number*number;
                }
            c=happy_or_not(number);
            if(c==1) printf("Case #%lld: %lld is a Happy number.\n",i,d);
            else if(c==0) printf("Case #%lld: %lld is an Unhappy number.\n",i,d);
        }
    return 0;
}

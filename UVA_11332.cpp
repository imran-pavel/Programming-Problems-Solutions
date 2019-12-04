#include <stdio.h>
int main()
{
    long long int a,sum,digit,num;
    for(;;)
        {
            scanf("%lld",&a);
            if(a==0) break;
            else
                {
                    sum=0;
                    num=a;
                    for(;;)
                        {
                            digit=num%10;
                            sum=sum+digit;
                            num=num/10;
                            if(num==0)
                                {
                                    if(sum>9)
                                        {
                                            num=sum;
                                            sum=0;
                                        }
                                    else break;
                                }
                        }
                }
            printf("%lld\n",sum);
        }
    return 0;
}

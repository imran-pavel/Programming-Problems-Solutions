#include <stdio.h>
int main()
{
    long long int i,count,r,num,x;
    for(i=1;;i++)
        {
            scanf("%lld %lld",&r,&num);
            if(r==0 && num==0) break;
            count=0;
            if(r>(num+num*26)) printf("Case %lld: impossible\n",i);
            else
                {
                    for(;;)
                        {
                            x=r-num;
                            if(x<=0) break;
                            else if(x>0)
                                {
                                    r=x;
                                    count++;
                                }
                        }
                    printf("Case %lld: %lld\n",i,count);
                }
        }
    return 0;
}

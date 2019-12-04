#include <stdio.h>
int main()
{
    long long int a,l,count,i,m;
    for(i=1;;i++)
        {
            scanf("%lld %lld",&a,&l);
            m=a;
            if(a==-1 && l==-1) break;
            else
                {
                    count=1;
                    for(;;)
                        {
                            if(a==1) break;
                            else if(a>l)
                                {
                                    count--;
                                    break;
                                }
                            else if(a%2==0)
                                {
                                    a=a/2;
                                    count++;
                                }
                            else
                                {
                                    a=a*3+1;
                                    count++;
                                }
                        }
                }
            printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",i,m,l,count);
        }
    return 0;
}

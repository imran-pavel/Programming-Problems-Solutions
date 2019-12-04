#include <stdio.h>
int main()
{
    char str[]={"No carry operation.\n"};
    long long unsigned int x,a,b,c,d,e,count;
    for(;;)
        {
            x=0;
            count=0;
            scanf("%llu %llu",&a,&b);
            if(a==0 && b==0) break;
            else
                {
                    for(;;)
                        {
                            c=a%10;
                            d=b%10;
                            a=a/10;
                            b=b/10;
                            e=c+d+x;
                            if(e<10) x=0;
                            else if(e>9)
                                {
                                    x=1;
                                    count++;
                                }
                            if(a==0 && b==0) break;
                        }
                }
            if(count==0) printf("%s",str);
            else if(count==1) printf("1 carry operation.\n");
            else printf("%llu carry operations.\n",count);
        }
    return 0;
}

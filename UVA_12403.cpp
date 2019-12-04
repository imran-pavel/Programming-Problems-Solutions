#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    long long int n,i,count=0;
    char fau[3];
    scanf("%lld",&n);
    gets(fau);
    char ch[15],*p;
    p=&ch[7];
    for(i=1;i<=n;i++)
        {
            gets(ch);
            if(ch[0]=='d')
                {
                    count=count+atoi(p);
                }
            else if(ch[0]=='r')
                {
                    printf("%lld\n",count);
                }
        }
}

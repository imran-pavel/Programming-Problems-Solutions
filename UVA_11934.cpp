#include <stdio.h>

int main()
{
    int a,b,c,d,L,x,value,count;
    for(;;)
        {
            scanf("%d %d %d %d %d",&a,&b,&c,&d,&L);
            if(a==0 && b==0 && c==0 && d==0 && L==0) break;
            count=0;
            for(x=0;x<=L;x++)
                {
                    value=(a*(x*x))+(b*x)+c;
                    if(value%d==0) count++;
                }
            printf("%d\n",count);
        }
    return 0;
}

#include <stdio.h>

int main()
{
    int a,b,c,d;
    for(;;)
        {
            scanf("%d %d",&a,&b);
            if(a==-1 && b==-1) break;
            c=a-b;
            if(c<0) c=c+100;
            d=b-a;
            if(d<0) d=d+100;
            if(c>d)
                {
                    printf("%d\n",d);
                }
            else printf("%d\n",c);
        }
    return 0;
}

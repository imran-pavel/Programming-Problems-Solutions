#include <stdio.h>
int main()
{
    int n,a,b,sum=0,g,i;
    scanf("%d %d %d",&n,&a,&b);
    for(i=1;i<=n;i++)
        {
            g=a*b*2;
            sum=sum+g;
        }
    printf("%d\n",sum);
    return 0;
}

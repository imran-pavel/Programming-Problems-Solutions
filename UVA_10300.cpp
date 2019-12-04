#include <stdio.h>

int main()
{
    int j,n,m,s,a,p,i;
    scanf("%d",&n);
    for(j=1;j<=n;j++)
        {
            scanf("%d",&m);
            int total=0;
            for(i=1;i<=m;i++)
                {
                    scanf("%d %d %d",&s,&a,&p);
                    total=total+(s*p);
                }
            printf("%d\n",total);
        }
    return 0;
}

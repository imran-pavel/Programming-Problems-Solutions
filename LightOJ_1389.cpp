#include <stdio.h>

int main()
{
    int n,i,count,x,m,j;
    char c,fau;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
            count=0;
            scanf("%d",&m);
            scanf("%c",&fau);
            for(j=1;j<=m;j++)
                {
                    scanf("%c",&c);
                    if(count==0)
                        {
                            if(c=='.')
                                {
                                    count++;
                                    x=j+2;
                                }
                        }
                    else
                        {
                            if(j>x)
                                {
                                    if(c=='.')
                                        {
                                            count++;
                                            x=j+2;
                                        }
                                }
                        }
                }
            printf("Case %d: %d\n",i,count);
        }
    return 0;
}

#include <stdio.h>

int main()
{
    int n,i,x,sum,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            sum=0;
            int numbers[x];
            for(j=0;j<x;j++)
                {
                    scanf("%d",&numbers[j]);
                    if(j>0)
                        {
                            for(k=0;k<j;k++)
                                {
                                    if(numbers[k]<=numbers[j]) sum++;
                                }
                        }
                }
            printf("%d\n",sum);
        }
    return 0;
}

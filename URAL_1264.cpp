#include <stdio.h>
int main()
{
    int N,M,i,j,k=0;
    scanf("%d %d",&N,&M);
    for(i=0;i<=N-1;i++)
        {
            for(j=0;j<=M;j++)
                {
                    k++;
                }
        }
    printf("%d\n",k);
    return 0;
}

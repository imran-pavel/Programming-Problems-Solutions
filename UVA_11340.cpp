#include <stdio.h>
#include <string.h>

int n_chars;
double cost,costs[101];
char chars[101];

void total_cost(char ar[])
{
    int i,j;

    for(i=0;i<strlen(ar);i++)
        {
            for(j=0;j<n_chars;j++)
                {
                    if(ar[i]==chars[j]) cost=cost+costs[j];
                }
        }
}

int main()
{
    int i,j,k,n,n_line;
    char fau[2],lines[10002];

    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
            scanf("%d",&n_chars);
            scanf("%c",&fau[0]);
            for(j=0;j<n_chars;j++)
                {
                    scanf("%c %lf",&chars[j],&costs[j]);
                    scanf("%c",&fau[0]);
                }
            scanf("%d",&n_line);
            gets(fau);
            cost=0;
            for(j=1;j<=n_line;j++)
                {
                    gets(lines);
                    total_cost(lines);
                }
            printf("%.2lf$\n",cost/100);
        }
    return 0;
}

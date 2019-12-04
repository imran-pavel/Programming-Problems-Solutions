#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,i,j,inputs[3001],diff[3000],temp,check;
    while(scanf("%d",&n)!=EOF)
        {
            check=0;
            for(i=0;i<n;i++)
                {
                    scanf("%d",&inputs[i]);
                }
            memset(diff,0,sizeof(diff));
            for(i=0;i<n-1;i++)
                {
                    diff[abs(inputs[i]-inputs[i+1])]++;
                }
            for(j=1;j<n;j++)
                {
                    if(diff[j]==0)
                        {
                            check++;
                            break;
                        }
                }
            if(check!=0) printf("Not jolly\n");
            else printf("Jolly\n");
        }
    return 0;
}

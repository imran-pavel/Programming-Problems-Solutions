#include <stdio.h>

int main()
{
    int n,i,j,c;
    while(scanf("%d",&n)!=EOF)
        {
            int num[n],count=0;
            for(i=0;i<n;i++)
                {
                    scanf("%d",&num[i]);
                }
            for(i=1;i<n;i++)
                {
                    for(j=n-1;j>=i;j--)
                        {
                            if(num[j]<num[j-1])
                                {
                                    c=num[j];
                                    num[j]=num[j-1];
                                    num[j-1]=c;
                                    count++;
                                }
                        }
                }
            printf("Minimum exchange operations : %d\n",count);
        }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n,i,m,j,k,count,temp;

    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        {
            count=0;
            scanf("%lld",&m);
            long long int numbers[m];
            for(j=0;j<m;j++)
                {
                    scanf("%lld",&numbers[j]);
                }
            for(j=1;j<m;j++)
                {
                    for(k=m-1;k>=j;k--)
                        {
                            if(numbers[k-1]>numbers[k])
                                {
                                    temp=numbers[k-1];
                                    numbers[k-1]=numbers[k];
                                    numbers[k]=temp;
                                    count++;
                                }
                        }
                }
            printf("Optimal train swapping takes %lld swaps.\n",count);
        }
    return 0;
}

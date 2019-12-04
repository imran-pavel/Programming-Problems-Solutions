#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct values{
    long long int a;
    long long int b;
};

int main()
{
    struct values set;
    long long int num,i,j,cost,k=0;
    while(scanf("%lld",&num)!=EOF)
        {
            k=0;
            long long int numbers[num],c=0;
            for(i=0;i<num;i++)
                {
                    scanf("%lld",&numbers[i]);
                }
            scanf("%lld",&cost);

            for(i=0;i<num;i++)
                {
                    if(numbers[i]<cost)
                        {
                            for(j=i+1;j<num;j++)
                                {
                                    if(numbers[j]<cost)
                                        {
                                            if(numbers[i]+numbers[j]==cost)
                                                {
                                                    if(k==0)
                                                        {
                                                            if(numbers[i]<=numbers[j])
                                                                {
                                                                    set.a=numbers[i];
                                                                    set.b=numbers[j];
                                                                }
                                                            else
                                                                {
                                                                    set.a=numbers[j];
                                                                    set.b=numbers[i];
                                                                }
                                                            if(cost%2==0)
                                                                {
                                                                    if(set.b-set.a==0)
                                                                        {
                                                                            c++;
                                                                            break;
                                                                        }
                                                                }
                                                            else
                                                                {
                                                                    if(set.b-set.a==1)
                                                                        {
                                                                            c++;
                                                                            break;
                                                                        }
                                                                }
                                                            k++;
                                                        }
                                                    else
                                                        {
                                                            if(numbers[i]>numbers[j])
                                                                {
                                                                    if(set.b-set.a>numbers[i]-numbers[j])
                                                                        {
                                                                            set.a=numbers[j];
                                                                            set.b=numbers[i];
                                                                        }
                                                                }
                                                            else
                                                                {
                                                                    if(set.b-set.a>numbers[j]-numbers[i])
                                                                        {
                                                                            set.a=numbers[i];
                                                                            set.b=numbers[j];
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                    if(c!=0) break;
                }
            printf("Peter should buy books whose prices are %lld and %lld.\n\n",set.a,set.b);
        }
    return 0;
}

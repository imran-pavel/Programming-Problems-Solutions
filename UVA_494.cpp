#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char line[100000];
    long long int length,k,i,count;
    while(gets(line))
        {
            k=0;
            count=0;
            length=strlen(line);
            for(i=0;i<length;i++)
                {
                    if((line[i]>='A' && line[i]<='Z') || (line[i]>='a' && line[i]<='z'))
                        {
                            if(k==0)
                                {
                                    count++;
                                    k++;
                                }
                        }
                    else k=0;
                }
            printf("%lld\n",count);
        }
    return 0;
}

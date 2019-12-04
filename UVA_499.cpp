#include <string.h>
#include <stdio.h>

int main()
{
    char line[100000];
    int length,ar[200],i,temp,max;
    while(gets(line))
        {
            memset(ar,0,sizeof(ar));
            max=0;
            length=strlen(line);
            for(i=0;i<length;i++)
                {
                    if((line[i]>='A' && line[i]<='Z') || (line[i]>='a' && line[i]<='z'))
                        {
                            temp=line[i];
                            ar[temp]++;
                            if(ar[temp]>max) max=ar[temp];
                        }
                }
            for(i=65;i<=122;i++)
                {
                    if(ar[i]==max) printf("%c",i);
                }
            printf(" %d\n",max);
        }
    return 0;
}

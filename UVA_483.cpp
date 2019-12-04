#include <stdio.h>
#include <string.h>

int main()
{
    char line[10000];
    int i,m,j;
    while(gets(line))
        {
            m=0;
            for(i=0;;i++)
                {
                    if(line[i]==' '||line[i]=='\0')
                        {
                            for(j=i-1;j>=m;j--)
                                {
                                    printf("%c",line[j]);
                                }
                            if(line[i]!='\0') printf(" ");
                            else if(line[i]=='\0') break;
                            m=i+1;
                        }
                    if(line[i]=='\0') break;
                }
            printf("\n");
        }
    return 0;
}

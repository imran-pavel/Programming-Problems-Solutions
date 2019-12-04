#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char line[100000];
    int group,x,length,i,j,k,l;

    for(;;)
        {
            scanf("%d",&group);
            if(group==0) break;
            scanf("%s",line);
            length=strlen(line);
            x=length/group;
            for(i=0,j=1;i<length;i++,j++)
                {
                    if(j%x==0)
                        {
                            for(k=i,l=1;l<=x;k--,l++)
                                {
                                    printf("%c",line[k]);
                                }
                        }
                }
            printf("\n");
        }
    return 0;
}

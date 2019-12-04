#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char line[100000];
    int length,i,count=1;

    while(gets(line))
        {
            length=strlen(line);
            for(;;)
                {
                    for(i=0;i<length;i++)
                        {
                            if(line[i]=='"')
                                {
                                    if(count%2==0)
                                        {
                                            printf("''");
                                        }
                                    else
                                        {
                                            printf("``");
                                        }
                                    count++;
                                }
                            else printf("%c",line[i]);
                        }
                    printf("\n");
                    break;
                }
        }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char line[100000],i;
    int length;

    while(gets(line))
        {
            length=strlen(line);
            for(i=0;i<length;i++)
                {
                    printf("%c",line[i]-7);
                }
            printf("\n");
        }
    return 0;
}

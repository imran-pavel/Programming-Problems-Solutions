#include <stdio.h>
#include <string.h>

int main()
{
    char line[100000];
    int length,i;
    while(gets(line))
        {
            length=strlen(line);
            for(i=0;i<length;i++)
                {
                    printf("%c",line[i]);
                }
            printf("\n");
        }
    return 0;
}

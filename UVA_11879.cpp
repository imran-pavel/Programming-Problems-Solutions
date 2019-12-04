#include <stdio.h>
#include <string.h>

int main()
{
    char line[100000];
    int i,length,remainder,digit;

    while(gets(line))
        {
            length=strlen(line);
            if(length==1 && line[0]=='0') break;
            remainder=0;
            digit=0;
            for(i=0;i<length;i++)
                {
                    digit=(line[i]-'0')+(digit*10);
                    digit=digit%17;
                }
            if(digit==0) printf("1\n");
            else printf("0\n");
        }
    return 0;
}

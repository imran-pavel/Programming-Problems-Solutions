#include <stdio.h>
#include <string.h>
#define lli long long int

int main()
{
    lli n_case,i,len,j,loop,male;
    char input[2000];

    scanf("%lld\n",&n_case);
    for(i=1;i<=n_case;i++)
    {
        gets(input);
        loop=0;
        male=0;
        len = strlen(input);
        for(j=0;j<len;j++)
        {
            if(input[j]=='M') male++;
            if(input[j]=='F') male--;
        }
        if(male==0 && len!=2) printf("LOOP\n");
        else printf("NO LOOP\n");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>

int prime_or_not(int num)
{
    int j;
    for(j=2;j<=sqrt(num);j++)
        {
            if(num%j==0) return 0;
        }
    return 1;
}

int main()
{
    char line[21];
    while(gets(line))
    {
        int i,length=strlen(line),total=0,res;
        for(i=0;i<length;i++)
            {
                if(line[i]>='a' && line[i]<='z')
                    {
                        total=total+(line[i]-'a'+1);
                    }
                else if(line[i]>='A' && line[i]<='Z')
                    {
                        total=total+(line[i]-'A'+1+26);
                    }
            }
        res=prime_or_not(total);
        if(res==0) printf("It is not a prime word.\n");
        else if(res==1) printf("It is a prime word.\n");
    }
    return 0;
}

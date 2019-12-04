#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int degrees(int sum, int degree)
{
    int digit,total=0;

    jump:
    for(;;)
        {
            digit=sum%10;
            total=total+digit;
            sum=sum/10;
            if(sum==0) break;
        }
    if(total>9)
        {
            sum=total;
            total=0;
            degree++;
            goto jump;
        }
    else
        {
            degree++;
            return degree;
        }
}

int main()
{
    char line[100000];
    int i,length,degree,sum,result;

    while(gets(line))
    {
        degree=1;
        sum=0;
        length=strlen(line);
        if(length==1 && line[0]=='0') break;
        for(i=0;i<length;i++)
            {
                sum=sum+line[i]-'0';
            }
        if(sum%9==0 && sum>9)
            {
                result=degrees(sum,degree);
                printf("%s is a multiple of 9 and has 9-degree %d.\n",line,result);
            }
        else if(sum%9==0 && sum==9) printf("%s is a multiple of 9 and has 9-degree %d.\n",line,degree);
        else printf("%s is not a multiple of 9.\n",line);
    }
    return 0;
}

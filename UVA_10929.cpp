#include <stdio.h>
#include <string.h>


int length;

int multiple_or_not(char num[], int remainder, int index)
{
    index++;
    if(index>=length)
        {
            if(remainder%11==0) return 1;
            else return 0;
        }
    else
        {
            remainder=((remainder*10)+(num[index]-'0'))%11;
            return multiple_or_not(num,remainder,index);
        }
}

int main()
{
    int digit,l,index,result,k;
    char number[1001];
    while(gets(number))
    {
        l=0;
        k=0;
        length=strlen(number);
        if(length==1 && number[0]=='0') break;
        digit=number[0]*10+number[1];
        if(digit<11 && length>2)
            {
                digit=digit*10+number[2];
                l++;
            }
        else if(digit<11 && length<3)
            {
                printf("%s is not a multiple of 11.\n",number);
                k++;
            }
        if(k==0)
            {
                digit=digit%11;
                if(l==0) index=1;
                else if(l==1) index=2;
                result=multiple_or_not(number,digit,index);
                if(result==1) printf("%s is a multiple of 11.\n",number);
                else if(result==0) printf("%s is not a multiple of 11.\n",number);
            }
    }
    return 0;
}

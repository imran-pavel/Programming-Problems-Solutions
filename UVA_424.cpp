#include <stdio.h>
#include <string.h>

char res[101]={'\0'},num[101];

void summation(char number1[], char number2[], int l1, int l2)
{
    int carry=0,i,length1=l1-1,length2=l2-1,temp,temp_res[101],j=-1;

    for(i=length2;i>-1;i--,length1--)
        {
            temp=number1[length1]-'0'+number2[i]-'0'+carry;
            if(temp>9)
                {
                    carry=1;
                    temp_res[++j]=((temp%10)+'0');
                }
            else
                {
                    carry=0;
                    temp_res[++j]=temp+'0';
                }
        }
    for(i=length1;i>-1;i--)
        {
            temp=number1[i]-'0'+carry;
            if(temp>9)
                {
                    carry=1;
                    temp_res[++j]=((temp%10)+'0');
                }
            else
                {
                    carry=0;
                    temp_res[++j]=temp+'0';
                }
        }
    if(carry==1) temp_res[++j]='1';
    i=0;
    while(j>=0)
        {
            res[i]=temp_res[j];
            j--;
            i++;
        }
    res[i]='\0';
}

int main()
{
    int len_number,len_result,k=0;
    for(;;)
        {
            gets(num);
            len_number=strlen(num);
            if(len_number==1 && num[0]=='0')
                {
                    while(res[k]!='\0')
                        {
                            printf("%c",res[k]);
                            k++;
                        }
                    printf("\n");
                    break;
                }
            else
                {
                    len_result=strlen(res);
                    if(len_result>len_number)
                        {
                            summation(res,num,len_result,len_number);
                        }
                    else
                        {
                            summation(num,res,len_number,len_result);
                        }
                }
        }
    return 0;
}

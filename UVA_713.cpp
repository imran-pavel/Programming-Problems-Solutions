#include <stdio.h>
#include <string.h>

void adding(char ar1[],long long int l1,char ar2[],long long int l2)
{
    long long int i,j,temp,k=0,count=0,x=0;
    char res[100000];
    for(i=0,j=0;i<l1;i++,j++)
        {
            if(j<l2)
                {
                    temp=ar1[i]-'0'+ar2[i]-'0'+count;
                    if(temp>9)
                        {
                            res[k]=(temp%10)+'0';
                            k++;
                            count=1;
                        }
                    else
                        {
                            res[k]=temp+'0';
                            k++;
                            count=0;
                        }
                }
            else
                {
                    temp=ar1[i]-'0'+count;
                    if(temp>9)
                        {
                            res[k]=(temp%10)+'0';
                            k++;
                            count=1;
                        }
                    else
                        {
                            res[k]=temp+'0';
                            k++;
                            count=0;
                        }
                }
        }
    if(count==1)
        {
            res[k]=count+'0';
        }
    else k--;
    for(i=0;i<=k;i++)
        {
            if(res[i]=='0')
                {
                    if(x!=0) printf("%c",res[i]);
                }
            else if(res[i]>'0' && res[i]<='9')
                {
                    printf("%c",res[i]);
                    x++;
                }
        }
    printf("\n");
}

int main()
{
    char line1[100000],line2[100000],fau[1];
    long long int n,i,len1,len2;

    scanf("%lld",&n);
    gets(fau);
    for(i=1;i<=n;i++)
        {
            scanf("%s",line1);
            scanf("%s",line2);
            len1=strlen(line1);
            len2=strlen(line2);
            if(len1>len2)
                {
                    adding(line1,len1,line2,len2);
                }
            else adding(line2,len2,line1,len1);
        }
    return 0;
}

#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,length,j;
    char num[6];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
            scanf("%s",num);
            length=strlen(num);
            if(length==5)
                {
                    if((num[0]!='t' && num[1]=='h' && num[2]=='r' &&
                       num[3]=='e' && num[4]=='e')||
                       (num[0]=='t' && num[1]!='h' && num[2]=='r' &&
                       num[3]=='e' && num[4]=='e')||
                       (num[0]=='t' && num[1]=='h' && num[2]!='r' &&
                       num[3]=='e' && num[4]=='e')||
                       (num[0]=='t' && num[1]=='h' && num[2]=='r' &&
                       num[3]!='e' && num[4]=='e')||
                       (num[0]=='t' && num[1]=='h' && num[2]=='r' &&
                       num[3]=='e' && num[4]!='e')||
                       (num[0]=='t' && num[1]=='h' && num[2]=='r' &&
                       num[3]=='e' && num[4]=='e'))
                        {
                            printf("3\n");
                        }
                }
            else if (length==3)
                {
                    if((num[0]!='o' && num[1]=='n' &&
                       num[2]=='e')||
                       (num[0]=='o' && num[1]!='n' &&
                       num[2]=='e')||
                       (num[0]=='o' && num[1]=='n' &&
                       num[2]!='e')||
                       (num[0]=='o' && num[1]=='n' &&
                       num[2]=='e'))
                        {
                            printf("1\n");
                        }
                    else if((num[0]!='t' && num[1]=='w' &&
                            num[2]=='o')||
                            (num[0]=='t' && num[1]!='w' &&
                            num[2]=='o')||
                            (num[0]=='t' && num[1]=='w' &&
                            num[2]!='o')||
                            (num[0]=='t' && num[1]=='w' &&
                            num[2]=='o'))
                        {
                            printf("2\n");
                        }
                }
        }
    return 0;
}

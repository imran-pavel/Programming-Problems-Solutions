#include <stdio.h>
#include <string.h>

int main()
{
    char ch,fau;
    int digit,check,terminate=0;

    while(1)
        {
            check=0;
            scanf("%d",&digit);
            scanf("%c",&fau);
            do
                {
                    scanf("%c",&ch);
                    if(ch=='\n') break;
                    if(ch=='0' && digit==0)
                        {
                            terminate++;
                            break;
                        }
                    else if(ch-'0'!=digit)
                        {
                            if(ch!='0')
                                {
                                    printf("%c",ch);
                                    check++;
                                }
                            else
                                {
                                    if(check!=0)
                                        {
                                            printf("%c",ch);
                                        }
                                }
                        }
                }while(1);
            if(terminate!=0) break;
            if(digit!=0 && check==0) printf("0");
            printf("\n");
        }
    return 0;
}

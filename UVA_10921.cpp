#include <stdio.h>
#include <string.h>

int main()
{
    char num[40];
    int length,i;
    while(gets(num))
        {
            length=strlen(num);
            for(i=0;i<length;i++)
                {
                    if(num[i]>='A' && num[i]<='C')
                        {
                            printf("2");
                        }
                    else if(num[i]>='D' && num[i]<='F')
                        {
                            printf("3");
                        }
                    else if(num[i]>='G' && num[i]<='I')
                        {
                            printf("4");
                        }
                    else if(num[i]>='J' && num[i]<='L')
                        {
                            printf("5");
                        }
                    else if(num[i]>='M' && num[i]<='O')
                        {
                            printf("6");
                        }
                    else if(num[i]>='P' && num[i]<='S')
                        {
                            printf("7");
                        }
                    else if(num[i]>='T' && num[i]<='V')
                        {
                            printf("8");
                        }
                    else if(num[i]>='W' && num[i]<='Z')
                        {
                            printf("9");
                        }
                    else printf("%c",num[i]);
                }
            printf("\n");
        }
    return 0;
}

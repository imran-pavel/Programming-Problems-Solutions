#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int i,c,length,k;
    char str[2000];
    for(;;)
        {
            gets(str);
            if(str[0]=='*') break;
            else
                {
                    k=0;
                    if(str[0]>='A'&&str[0]<='Z')
                        {
                            c=str[0]-'A'+1;
                        }
                    else if(str[0]>='a'&&str[0]<='z')
                        {
                            c=str[0]-'a'+1;
                        }
                    length=strlen(str);
                    for(i=1;i<=length-1;i++)
                        {
                            if(str[i]==' ')
                                {
                                    k++;
                                    goto jump;
                                }
                            if(k==1)
                                {
                                    if(!((c==(str[i]-'A'+1))||(c==(str[i]-'a'+1)))) break;
                                    else k=0;
                                }
                            jump:;
                        }
                    if(i==length) printf("Y\n");
                    else printf("N\n");
                }
        }
    return 0;
}

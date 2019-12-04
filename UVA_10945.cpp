#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int palindrome_or_not(char line[],int length)
{
    int i,check2=length,check=length/2;
    check2--;
    for(i=0;i<check;i++,check2--)
        {
            if(line[i]!=line[check2]) return 0;
        }
    return 1;
}

int main()
{
    char ch,fau,line[1000000];
    int i,length,result;
    while(1)
        {
            i=-1;
            do
                {
                    ch=getchar();
                    if(ch!='\n')
                        {
                            if(ch>='A' && ch<='Z')
                                {
                                    i++;
                                    line[i]=ch;
                                }
                            else if(ch>='a' && ch<='z')
                                {
                                    i++;
                                    line[i]=ch-32;
                                }
                        }
                    else
                        {
                            i++;
                            line[i]=0;
                            break;
                        }
                }while(1);
            if(strcmp(line,"DONE")==0) break;
            length=strlen(line);
            result=palindrome_or_not(line,length);
            if(result==1)
                {
                    printf("You won't be eaten!\n");
                }
            else if(result==0)
                {
                    printf("Uh oh..\n");
                }
        }
    return 0;
}

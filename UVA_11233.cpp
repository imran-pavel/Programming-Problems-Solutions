#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct plurals{
    char word[100000];
    char plural[100000];
};

int main()
{
    int l,n,i,j,k,length;
    char temp[100000];

    while(scanf("%d %d",&l,&n)!=EOF)
        {
            k=0;
            struct plurals inputs[l];
            for(i=0;i<l;i++)
                {
                    scanf("%s %s",inputs[i].word,inputs[i].plural);
                }
            for(i=1;i<=n;i++)
                {
                    scanf("%s",temp);
                    length=strlen(temp);
                    for(j=0;j<l;j++)
                        {
                            if(strcmp(inputs[j].word,temp)==0)
                                {
                                    k++;
                                    printf("%s\n",inputs[j].plural);
                                }
                        }
                    if(k==0)
                        {
                            if(temp[length-1]=='o'||temp[length-1]=='s'||(temp[length-1]=='h' && temp[length-2]=='c')||(temp[length-1]=='h' && temp[length-2]=='s')||temp[length-1]=='x')
                                {
                                    printf("%s",temp);
                                    printf("es\n");
                                }
                            else if(temp[length-1]=='y')
                                {
                                    if(temp[length-2]=='a'||temp[length-2]=='e'||temp[length-2]=='i'||temp[length-2]=='o'||temp[length-2]=='u')
                                        {
                                            printf("%s",temp);
                                            printf("s\n");
                                        }
                                    else
                                        {
                                            temp[length-1]='\0';
                                            printf("%s",temp);
                                            printf("ies\n");
                                        }
                                }
                            else
                                {
                                    printf("%s",temp);
                                    printf("s\n");
                                }
                        }
                    k=0;
                }
        }
    return 0;
}

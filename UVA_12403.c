#include<stdio.h>
#include<string.h>
int main()
{
    int i,k=0,a,t;
    char s[50],s1[]="donate";

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%s",s);
        if(strcmp(s1,s)==0)
            {
                scanf("%d",&a);
                k=k+a;
            }
        else printf("%d\n",k);
    }
return 0;
}

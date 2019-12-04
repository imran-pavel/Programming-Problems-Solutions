#include <stdio.h>
#include <string.h>
int main()
{
    long long int n,i,length,y,count,k;
    scanf("%lld",&n);
    char sentence[500],fau[5];
    gets(fau);
    char a[4]="abc",d[4]="def",g[4]="ghi",j[4]="jkl",m[4]="mno",p[5]="pqrs",t[4]="tuv",w[5]="wxyz",space[1]={' '};
    for(i=1;i<=n;i++)
        {
            gets(sentence);
            length=strlen(sentence);
            count=0;
            for(y=0;y<=length-1;y++)
                {
                    if(sentence[y]==space[0]) count++;
                    else if('a'<=sentence[y] && sentence[y]<='c')
                        {
                            for(k=0;k<=2;k++)
                                {
                                    if(sentence[y]==a[k]) break;
                                }
                            k++;
                            count=count+k;
                        }
                    else if('d'<=sentence[y] && sentence[y]<='f')
                        {
                            for(k=0;k<=2;k++)
                                {
                                    if(sentence[y]==d[k]) break;
                                }
                            k++;
                            count=count+k;
                        }
                    else if('g'<=sentence[y] && sentence[y]<='i')
                        {
                            for(k=0;k<=2;k++)
                                {
                                    if(sentence[y]==g[k]) break;
                                }
                            k++;
                            count=count+k;
                        }
                    else if('j'<=sentence[y] && sentence[y]<='l')
                        {
                            for(k=0;k<=2;k++)
                                {
                                    if(sentence[y]==j[k]) break;
                                }
                            k++;
                            count=count+k;
                        }
                    else if('m'<=sentence[y] && sentence[y]<='o')
                        {
                            for(k=0;k<=2;k++)
                                {
                                    if(sentence[y]==m[k]) break;
                                }
                            k++;
                            count=count+k;
                        }
                    else if('p'<=sentence[y] && sentence[y]<='s')
                        {
                            for(k=0;k<=3;k++)
                                {
                                    if(sentence[y]==p[k]) break;
                                }
                            k++;
                            count=count+k;
                        }
                    else if('t'<=sentence[y] && sentence[y]<='v')
                        {
                            for(k=0;k<=2;k++)
                                {
                                    if(sentence[y]==t[k]) break;
                                }
                            k++;
                            count=count+k;
                        }
                    else if('w'<=sentence[y] && sentence[y]<='z')
                        {
                            for(k=0;k<=3;k++)
                                {
                                    if(sentence[y]==w[k]) break;
                                }
                            k++;
                            count=count+k;
                        }
                }
            printf("Case #%lld: %lld\n",i,count);
        }
    return 0;
}

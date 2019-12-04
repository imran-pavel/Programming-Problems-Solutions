#include <stdio.h>
#include <string.h>

int count_brazico,count_mexil,n,m;
char ar[51][51];

void count_area(int x, int y, char ch, int country)
{
    //printf("aa\n");
    if(x>=0 && x<n && y>=0 && y<m)
        {
            if(ar[x][y]==ch)
                {
                    if(country==1)
                        {
                            count_brazico++;
                            ar[x][y]='B';
                            count_area(x,y+1,ch,country);
                            count_area(x-1,y,ch,country);
                            count_area(x,y-1,ch,country);
                            count_area(x+1,y,ch,country);
                        }
                    else if(country==2)
                        {
                            count_mexil++;
                            ar[x][y]='M';
                            count_area(x,y+1,ch,country);
                            count_area(x-1,y,ch,country);
                            count_area(x,y-1,ch,country);
                            count_area(x+1,y,ch,country);
                        }
                }
        }
}

void count_area_for_a_country(int country, char ch)
{
    char cou;
    int i,j;
    if(country==1) cou='B';
    else if(country==2) cou='M';
    for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                {
                    if(ar[i][j]==cou)
                        {
                            count_area(i,j+1,ch,country);
                            count_area(i-1,j,ch,country);
                            count_area(i,j-1,ch,country);
                            count_area(i+1,j,ch,country);
                        }
                }
        }
}

int main()
{
    int i,j,turns,x,len;
    char fau[2],f;
    while(scanf("%d %d",&n,&m)==2)
        {
            gets(fau);
            count_brazico=count_mexil=0;
            memset(ar,0,sizeof(ar));
            for(i=0;i<n;i++)
                {
                    gets(ar[i]);
                }
            /*for(i=0;i<n;i++)
                {
                    puts(ar[i]);
                }*/
            len=strlen(ar[0]);
            //printf("%d\n",len);
            count_area(n-1,0,ar[n-1][0],1);
            count_area(0,m-1,ar[0][len-1],2);
            //printf("%c\n",ar[0][len-1]);
            /*for(i=0;i<n;i++)
                {
                    puts(ar[i]);
                }*/
            scanf("%d",&turns);
            for(j=1;j<=turns;j++)
                {
                    scanf("%d",&x);
                    if(j%2!=0)
                        {
                            count_area_for_a_country(1,(x+'0'));
                        }
                    else count_area_for_a_country(2,(x+'0'));
                }
            /*for(i=0;i<n;i++)
                {
                    puts(ar[i]);
                }*/
            printf("%d\n%d\n",count_brazico,count_mexil);
        }
    return 0;
}

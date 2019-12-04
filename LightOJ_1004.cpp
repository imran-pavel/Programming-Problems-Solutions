#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int ar[200][200];
int safe[200][200];
int rows;

int max(int a, int b)
{
    if(a>b) return a;
    else return b;
}

int dp(int row, int column)
{
    if(row>=(rows*2-1)) return 0;
    else if(ar[row][column]==-1)
        {
            //printf("ar[%d][%d]= %d\n",row,column,ar[row][column]);
            return 0;
        }
    //printf("ar[%d][%d]= %d\n",row,column,ar[row][column]);
    if(safe[row][column]!=-1) return safe[row][column];
    else
        {
            int total1,total2,m;
            total1=total2=0;
            total1=ar[row][column]+dp(row+1,column-1);
            total2=ar[row][column]+dp(row+1,column+1);
           // printf("ar[%d][%d]= %d\n",row,column,ar[row][column]);
           //printf("Total1: %d Total2: %d Total3: %d\n",total1,total2,total3);
            m=max(total1,total2);
            safe[row][column]=m;
           // printf("For ar[%d][%d]= %d  m2=%d\n",row,column,ar[row][column],m2);
            return safe[row][column];
        }
}

int main()
{
    int t_case,i,j,in,k,x,pos,t,t_pos,c;
    scanf("%d",&t_case);
    for(i=1;i<=t_case;i++)
        {
            memset(ar,-1,sizeof(ar));
            memset(safe,-1,sizeof(safe));
            scanf("%d",&rows);
            t=pos=((rows*2)-1)/2;
            for(j=0;j<=t;j++,pos--)
                {
                    for(k=1,t_pos=pos;k<=j+1;k++,t_pos=t_pos+2)
                        {
                            cin >> ar[j][t_pos];
                        }
                }
            pos=pos+2;
            c=k-2;
            for(;j<=(rows*2-1);j++,pos++,c--)
                {
                    for(k=1,t_pos=pos;k<=c;k++,t_pos=t_pos+2)
                        {
                            cin >> ar[j][t_pos];
                        }
                }
           /*for(j=0;j<(rows*2-1);j++)
             {
                 for(k=0;k<(rows*2-1);k++)
                     {
                         printf("%d ",ar[j][k]);
                     }
                 printf("\n");
             }*/
            x=dp(0,t);
            printf("Case %d: %d\n",i,x);
        }
    return 0;
}

#include <stdio.h>
#include <string.h>

int t,w,d[31],v[31],result[31][1001],n,in,temp[31];
int cost1[31][1001],cost2[31][1001];

void in_check(int index, int time)
{
    if(index>=n || time<0) return;
    int t_time=time;
    if(cost1[index][time]>cost2[index][time])
        {
            temp[in]=index;
            in++;
            time=time-(d[index]*w)-2*(d[index]*w);
            in_check(index+1,time);
        }
    else
        {
            in_check(index+1,t_time);
        }
}

int dp(int i, int time)
{

    if(i<n && time>-1)
        {
            if(result[i][time]==-1)
                {
                    int at,dt,res1=0,res2=0;
                    dt=w*(d[i]);
                    at=2*dt;
                    if(time>=(at+dt))
                        {
                            res1=v[i]+dp(i+1,(time-(at+dt)));
                        }
                    res2=dp(i+1,time);
                    cost1[i][time]=res1;
                    cost2[i][time]=res2;
                    if(res1>res2)
                        {
                            result[i][time]=res1;
                            return result[i][time];
                        }
                    else
                        {
                            result[i][time]=res2;
                            return result[i][time];
                        }
                }
            else return result[i][time];
        }
    else return 0;
}

int main()
{
    int i,max_value,count,fau=0;
    while(scanf("%d %d",&t,&w)!=EOF)
        {
            memset(result,-1,sizeof(result));
            if(fau==1) printf("\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
                {
                    scanf("%d %d",&d[i],&v[i]);
                }
            in=count=0;
            max_value=dp(0,t);
            in_check(0,t);
            printf("%d\n%d\n",max_value,in);
            for(i=0;i<in;i++)
                {
                    printf("%d %d\n",d[temp[i]],v[temp[i]]);
                }
            fau=1;
        }
    return 0;
}
#include <queue>
#include <cstdio>
#include <cstring>
#define lli long long int


using namespace std;

lli field[1001][1001],r,c;

struct spots
{
    lli c_x;
    lli c_y;
};


void BFS(spots source)
{
    lli u_x,u_y,v_x,v_y;
    queue <int> x,y;


    x.push(source.c_x);
    y.push(source.c_y);
    while(x.size())
        {
            u_x=x.front();
            u_y=y.front();
            x.pop();
            y.pop();

            if(u_y-1>=0)
                {
                    if(!field[u_x][u_y-1] && field[u_x][u_y-1]!=-1)
                        {
                            x.push(u_x);
                            y.push(u_y-1);
                            field[u_x][u_y-1]=field[u_x][u_y]+1;
                        }
                }
            if(u_y+1<c)
                {
                    if(!field[u_x][u_y+1] && field[u_x][u_y+1]!=-1)
                        {
                            x.push(u_x);
                            y.push(u_y+1);
                            field[u_x][u_y+1]=field[u_x][u_y]+1;
                        }
                }
            if(u_x-1>=0)
                {
                    if(!field[u_x-1][u_y] && field[u_x-1][u_y]!=-1)
                        {
                            x.push(u_x-1);
                            y.push(u_y);
                            field[u_x-1][u_y]=field[u_x][u_y]+1;
                        }
                }
            if(u_x+1<r)
                {
                    if(!field[u_x+1][u_y] && field[u_x+1][u_y]!=-1)
                        {
                            x.push(u_x+1);
                            y.push(u_y);
                            field[u_x+1][u_y]=field[u_x][u_y]+1;
                        }
                }
        }
}

int main()
{
    lli n_r,n_row,i,n_bomb,j,b_c;
    spots source, destination;

    for(;;)
        {
            scanf("%lld %lld",&r,&c);
            if(r==0 && c==0) break;
            memset(field,0,sizeof(field));
            scanf("%lld",&n_r);
            for(i=1;i<=n_r;i++)
                {
                    scanf("%lld %lld",&n_row,&n_bomb);
                    for(j=1;j<=n_bomb;j++)
                        {
                            scanf("%lld",&b_c);
                            field[n_row][b_c]=-1;
                        }
                }
            scanf("%lld %lld",&source.c_x,&source.c_y);
            scanf("%lld %lld",&destination.c_x,&destination.c_y);
            BFS(source);
            printf("%lld\n",field[destination.c_x][destination.c_y]);
        }
    return 0;
}

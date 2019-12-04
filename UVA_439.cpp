#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#define lli long long int

using namespace std;

lli chessboard[8][8];

struct spot
{
    lli c_x;
    lli c_y;
};

void BFS(spot source)
{
    lli u_x,u_y;
    queue <int> x;
    queue <int> y;

    x.push(source.c_x);
    y.push(source.c_y);
    while(x.size())
        {
            u_x=x.front();
            u_y=y.front();
            x.pop();
            y.pop();
            if(u_y+2<8)
                {
                    if(u_x-1>=0)
                        {
                            if(!chessboard[u_x-1][u_y+2])
                                {
                                    chessboard[u_x-1][u_y+2]=chessboard[u_x][u_y]+1;
                                    x.push(u_x-1);
                                    y.push(u_y+2);
                                }
                        }
                    if(u_x+1<8)
                        {
                            if(!chessboard[u_x+1][u_y+2])
                                {
                                    chessboard[u_x+1][u_y+2]=chessboard[u_x][u_y]+1;
                                    x.push(u_x+1);
                                    y.push(u_y+2);
                                }
                        }
                }
            if(u_y-2>=0)
                {
                    if(u_x-1>=0)
                        {
                            if(!chessboard[u_x-1][u_y-2])
                                {
                                    chessboard[u_x-1][u_y-2]=chessboard[u_x][u_y]+1;
                                    x.push(u_x-1);
                                    y.push(u_y-2);
                                }
                        }
                    if(u_x+1<8)
                        {
                            if(!chessboard[u_x+1][u_y-2])
                                {
                                    chessboard[u_x+1][u_y-2]=chessboard[u_x][u_y]+1;
                                    x.push(u_x+1);
                                    y.push(u_y-2);
                                }
                        }
                }
            if(u_x-2>=0)
                {
                    if(u_y+1<8)
                        {
                            if(!chessboard[u_x-2][u_y+1])
                                {
                                    chessboard[u_x-2][u_y+1]=chessboard[u_x][u_y]+1;
                                    x.push(u_x-2);
                                    y.push(u_y+1);
                                }
                        }
                    if(u_y-1>=0)
                        {
                            if(!chessboard[u_x-2][u_y-1])
                                {
                                    chessboard[u_x-2][u_y-1]=chessboard[u_x][u_y]+1;
                                    x.push(u_x-2);
                                    y.push(u_y-1);
                                }
                        }
                }
            if(u_x+2<8)
                {
                    if(u_y+1<8)
                        {
                            if(!chessboard[u_x+2][u_y+1])
                                {
                                    chessboard[u_x+2][u_y+1]=chessboard[u_x][u_y]+1;
                                    x.push(u_x+2);
                                    y.push(u_y+1);
                                }
                        }
                    if(u_y-1>=0)
                        {
                            if(!chessboard[u_x+2][u_y-1])
                                {
                                    chessboard[u_x+2][u_y-1]=chessboard[u_x][u_y]+1;
                                    x.push(u_x+2);
                                    y.push(u_y-1);
                                }
                        }
                }
        }
}

int main()
{
    char s1[4],s2[4];
    spot source,destination;

    while(scanf("%s %s",s1,s2)!=EOF)
        {
            source.c_x=s1[1]-'0'-1;
            source.c_y=s1[0]-'a';
            destination.c_x=s2[1]-'0'-1;
            destination.c_y=s2[0]-'a';
            memset(chessboard,0,sizeof(chessboard));
            if(!(s1[0]==s2[0] && s1[1]==s2[1]))
                {
                    BFS(source);
                }
            printf("To get from %s to %s takes %lld knight moves.\n",s1,s2,chessboard[destination.c_x][destination.c_y]);
        }
    return 0;
}

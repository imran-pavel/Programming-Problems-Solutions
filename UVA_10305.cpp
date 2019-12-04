#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int ar[10000][10000],taken[10000],n;

queue <int> set,output;

int no_incoming_edge(int x)
{
    int i,j;

    for(i=1;i<=n;i++)
        {
            if(ar[i][x]) return 0;
        }
    return 1;
}

void push_nodes(int x)
{
    int i;

    for(i=1;i<=n;i++)
        {
            if(ar[x][i]==1)
                {
                    ar[x][i]=0;
                    if(taken[i]!=1)
                        {
                            if(no_incoming_edge(i))
                                {
                                    set.push(i);
                                    taken[i]=1;
                                }
                        }
                }
        }
}

int main()
{
    int m,a,b,i;

    for(;;)
        {
            cin>>n>>m;
            if(n==0 && m==0) break;
            memset(ar,0,sizeof(ar));
            memset(taken,0,sizeof(taken));
            while(m--)
                {
                    cin>>a>>b;
                    ar[a][b]=1;
                }
            for(i=1;i<=n;i++)
                {
                    if(no_incoming_edge(i)) set.push(i);
                }
            while(set.size())
                {
                    output.push(set.front());
                    push_nodes(set.front());
                    set.pop();
                }
            while(output.size())
                {
                    cout<<output.front()<<' ';
                    output.pop();
                }
            cout<<'\n';
        }
    return 0;
}

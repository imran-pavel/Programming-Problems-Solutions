#include <cstdio>
#include <cstring>
#include <queue>
#define lli long long int
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

lli color[200];
vector <int> graph[200];
bool bi_col;

void clean(int n)
{
    int i;

    for(i=0;i<n;i++)
        {
            graph[i].clear();
        }
    mem(color,0);
}

void BFS(lli source)
{
    lli u,change,i;
    queue <int> q;

    color[source]=1;
    bi_col=true;
    q.push(source);
    while(!q.empty())
        {
            u=q.front();
            q.pop();
            if(color[u]==1) change=2;
            else change=1;
            for(i=0;i<graph[u].size();i++)
                {
                    if(!color[graph[u][i]])
                        {
                            color[graph[u][i]]=change;
                            q.push(graph[u][i]);
                        }
                    else
                        {
                            if(color[graph[u][i]]==color[u])
                                {
                                    bi_col=false;
                                    return;
                                }
                        }
                }
        }
}

int main()
{
    lli n_v,n_e,i,x,y;

    for(;;)
        {
            scanf("%lld",&n_v);
            if(!n_v) break;
            clean(n_v);
            scanf("%lld",&n_e);
            for(i=0;i<n_e;i++)
                {
                    scanf("%lld %lld",&x,&y);
                    graph[x].push_back(y);
                    graph[y].push_back(x);
                }
            BFS(0);
            if(bi_col) printf("BICOLORABLE.\n");
            else printf("NOT BICOLORABLE.\n");
        }
    return 0;
}

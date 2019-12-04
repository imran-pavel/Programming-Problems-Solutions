#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define lli long long int

using namespace std;

vector <lli> adj_list[21];
lli length[21],taken[21];

void clear_list()
{
    lli i;

    for(i=1;i<=20;i++)
        {
            adj_list[i].clear();
        }
}

void take_input(int from,int n)
{
    lli i,vertex;

    for(i=1;i<=n;i++)
        {
            scanf("%lld",&vertex);
            adj_list[from].push_back(vertex);
            adj_list[vertex].push_back(from);
        }
}

void BFS(lli src)
{
    queue <int> q;
    lli u,i,v;

    length[src]=0;
    taken[src]++;
    q.push(src);
    while(q.size())
        {
            u=q.front();
            q.pop();
            for(i=0;i<adj_list[u].size();i++)
                {
                    v=adj_list[u][i];
                    if(!taken[v])
                        {
                            taken[v]++;
                            length[v]=length[u]+1;
                            q.push(v);
                        }
                }
        }
}

int main()
{
    lli n,i,vertex,n_case,src,dstn,t_set=1;

    while(scanf("%lld",&n)!=EOF)
        {
           clear_list();
           take_input(1,n);
            for(i=2;i<=19;i++)
                {
                    scanf("%lld",&n);
                    take_input(i,n);
                }
            scanf("%lld",&n_case);
            for(i=1;i<=n_case;i++)
                {
                    scanf("%lld %lld",&src,&dstn);
                    memset(taken,0,sizeof(taken));
                    memset(length,0,sizeof(length));
                    BFS(src);
                    if(i==1) printf("Test Set #%lld\n",t_set);
                    if(src<10) printf(" %lld",src);
                    else printf("%lld",src);
                    if(dstn<10) printf(" to  %lld: %lld\n",dstn,length[dstn]);
                    else printf(" to %lld: %lld\n",dstn,length[dstn]);
                }
            printf("\n");
            t_set++;
        }
    return 0;
}

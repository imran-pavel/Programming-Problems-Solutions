#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

vector <int> nodes[31];

int bfs(int src, int n, int ttl)
{
    int v,u,taken2[31] = {0},total;
    int dis[31];
    queue <int> q;
    total=dis[src]=0;
    taken2[src]=1;
    q.push(src);
    while(q.size())
    {
        u = q.front();
        q.pop();
        for(int i=0;i<nodes[u].size();i++)
        {
            v=nodes[u][i];
            if(!taken2[v])
            {
                q.push(v);
                dis[v] = dis[u]+1;
                taken2[v]=1;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(!taken2[i]) dis[i]=2140000000;
    }

    for(int i=1;i<n;i++)
    {
        if(dis[i]>ttl) total++;
    }
    return total;
}

int main()
{
    int n,i,from,to,mapped_value,t1,t2,src,ttl,n_case;

    for(n_case=1;;)
    {
        cin>>n;
        if(n==0) break;
        map <int, int> taken;
        for(i=0;i<31;i++) nodes[i].clear();
        for(mapped_value=i=1;i<=n;i++)
        {
            cin>>from>>to;
            t1 = taken[from];
            if(!t1)
            {
                taken[from] = mapped_value++;
                t1 = taken[from];
            }
            t2 = taken[to];
            if(!t2)
            {
                taken[to] = mapped_value++;
                t2 = taken[to];
            }
            nodes[t1].push_back(t2);
            nodes[t2].push_back(t1);
        }
        for(;;n_case++)
        {
            cin>>src>>ttl;
            if(src==0 && ttl==0) break;
            cout<<"Case "<<n_case<<": "<<bfs(taken[src],mapped_value,ttl)<<" nodes not reachable from node "<<src<<" with TTL = "<<ttl<<".\n";
        }
    }
    return 0;
}

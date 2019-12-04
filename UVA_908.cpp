// Md Imran Pavel

#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#define li long int

using namespace std;

int parent[1000000];

struct data
{
    int u,v,cost;
    bool operator < (const data& p) const
    {
        return cost > p.cost;
    }
};

struct parent_info
{
    int parent;
    int tree_size;     // Number of nodes went through to find parent
};

parent_info find_parent(int node, int tree_length)
{
    parent_info p_info;
    if(parent[node]==0)
    {
        p_info.parent = node;
        p_info.tree_size = tree_length;
        return p_info;
    }
    else
    {
        p_info = find_parent(parent[node],tree_length+1);
        return p_info;
    }
}

void update_parents(int u, int v)
{
    if(parent[v]==0)
    {
        parent[v] = u;
        return;
    }
    update_parents(v,parent[v]);
    parent[v] = u;
}

int main()
{
    li n_sites,i,n_k,m,cost_count,edge_count,current_cost_count;
    parent_info u_parent,v_parent;
    data edge;
    li useless_flag = 0;


    while(cin>>n_sites)
    {
        priority_queue <data> p_q,mst_p_q;

        current_cost_count = 0;
        for(i=0;i<n_sites-1;i++)
        {
            cin>>edge.u>>edge.v>>edge.cost;
            //cout<<"edge.u: "<<edge.u<<" edge.v: "<<edge.v<<" edge.cost: "<<edge.cost<<endl;
            parent[edge.u] = parent[edge.v] = 0;
            current_cost_count = edge.cost + current_cost_count;
            mst_p_q.push(edge);    // this q is just to store. There is no need to use it later.
        }
        cin>>n_k;
        for(i=0;i<n_k;i++)
        {
            cin>>edge.u>>edge.v>>edge.cost;
            //cout<<"edge.u: "<<edge.u<<" edge.v: "<<edge.v<<" edge.cost: "<<edge.cost<<endl;
            parent[edge.u] = parent[edge.v] = 0;
            p_q.push(edge);   // This q will hold all the edges. Here the new edges are being taken.
        }

        cin>>m;

        for(i=0;i<m;i++)
        {
            cin>>edge.u>>edge.v>>edge.cost;
            //cout<<"edge.u = "<<edge.u<<"  edge.v = "<<edge.v<<endl;
            parent[edge.u] = parent[edge.v] = 0;
            p_q.push(edge);  // The old edges are taken here.
        }

        edge_count = cost_count = 0;
        while(1)
        {
            if(edge_count==n_sites-1) break;
            edge = p_q.top();
            p_q.pop();

            //cout<<"u: "<<edge.u<<"  v: "<<edge.v<<"  cost: "<<edge.cost<<endl;
            u_parent = find_parent(edge.u,1);
            v_parent = find_parent(edge.v,1);
            //cout<<"u_parent: "<<u_parent.parent<<"  v_parent: "<<v_parent.parent<<endl;
            //cout<<"u_parent tree size: "<<u_parent.tree_size<<"  v_parent tree size: "<<v_parent.tree_size<<endl<<endl;

            if(u_parent.parent != v_parent.parent)
            {
                edge_count++;
                cost_count = edge.cost + cost_count;
                if(u_parent.tree_size > v_parent.tree_size)  // There are 2 trees here. One on u side and the other on v side.
                {
                    update_parents(edge.u,edge.v);   // If the v side tree is smaller update that side's nodes parent list.
                }
                else
                {
                    update_parents(edge.v,edge.u);  // Else if u side is smaller or equal update u side nodes parent list.
                }
            }
            else
            {
                continue;
            }

        }
        if(useless_flag) cout<<"\n"; // this check will be true if there are more than one test cases.
        cout<<current_cost_count<<"\n";
        cout<<cost_count<<"\n";
        useless_flag = 1;
    }
    return 0;
}

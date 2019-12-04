#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <cstring>
#define li long int
#define big 1000000

using namespace std;

struct node
{
    li city_index,weight;
    bool operator < ( const node& p ) const
        {
            return weight < p.weight;
        }
};

map <string,li> city_indexes;
li taken[200];

int main()
{
    li n_city,n_routes,weight,i,index_u,index_v,index,scenario=0;
    string u,v,s,d;
    node temp_node;
    li temp_weight,min_weight,j,source,destination;

    while(1)
    {
        cin>>n_city>>n_routes;
        if(n_city==0 && n_routes==0) break;
        priority_queue <node> max_q;
        vector <node> adjacency_list[200];
        scenario++;
        index=0;
        min_weight=big;
        for(i=0;i<n_routes;i++)
        {
            cin>>u>>v>>weight;
            if(!(index_u=city_indexes[u]))
                {
                    city_indexes[u]=index;
                    index_u=city_indexes[u];
                    index++;
                }
            if(!(index_v=city_indexes[v]))
                {
                    city_indexes[v]=index;
                    index_v=city_indexes[v];
                    index++;
                }

            node single_node;
            single_node.weight=weight;
            single_node.city_index=city_indexes[v];
            adjacency_list[city_indexes[u]].push_back(single_node);
            single_node.city_index=city_indexes[u];
            adjacency_list[city_indexes[v]].push_back(single_node);
        }
        cin>>s>>d;
        source=city_indexes[s];
        destination=city_indexes[d];
        memset(taken,0,sizeof(taken));
        for(j=0;j<adjacency_list[source].size();j++)
        {
            max_q.push(adjacency_list[source][j]);
        }
        taken[source]++;

        while(max_q.size())
        {
            temp_node=max_q.top();
            max_q.pop();
            temp_weight=temp_node.weight;
            min_weight=min(temp_weight,min_weight);
            if(temp_node.city_index==destination) break;
            taken[temp_node.city_index]++;
            for(i=0;i<adjacency_list[temp_node.city_index].size();i++)
            {
                if(!taken[adjacency_list[temp_node.city_index][i].city_index])
                {
                    max_q.push(adjacency_list[temp_node.city_index][i]);
                }
            }
        }
        cout<<"Scenario #"<<scenario<<"\n";
        cout<<min_weight<<" tons\n\n";
    }
    return 0;
}

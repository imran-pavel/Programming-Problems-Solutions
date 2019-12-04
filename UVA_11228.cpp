#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#define li long int

using namespace std;


struct edges
{
    li u,v;
    double cost;
    bool operator < ( const edges& p ) const
    {
        return cost > p.cost;
    }
};

struct city
{
    li x;
    li y;
    li state;
    vector <li> cities_i_am_connected_with;
}cities[1000];


li n,r,n_case,n_states;
double minimum_road,minimum_rail;
double distance_between_cities[1000][1000];
li distance_taken[1000][1000];
li edge_exists_between_states[1000][1000];
li path_taken[1000];
vector <li> states[1000];
priority_queue <edges> edges_between_states;

void clear_everything()
{
    li i,j;

    memset(distance_taken,-1,sizeof(distance_taken));
    memset(edge_exists_between_states,0,sizeof(edge_exists_between_states));
    for(i=0;i<n_states+1;i++)
    {
        for(j=0;j<states[i].size();j++)
        {
            cities[states[i][j]].cities_i_am_connected_with.clear();
        }
        states[i].clear();
    }
    while(edges_between_states.size())
    {
        edges_between_states.pop();
    }
}



double find_distance(li city_index1, li city_index2)
{
    return sqrt((cities[city_index1].x-cities[city_index2].x)*(cities[city_index1].x-cities[city_index2].x) + (cities[city_index1].y-cities[city_index2].y)*(cities[city_index1].y-cities[city_index2].y));
}


bool circle_not_found(li find_this, li find_in_here)
{
    li i,limit;

    limit = cities[find_in_here].cities_i_am_connected_with.size();
    for(i=0;i<limit;i++)
    {
        if(find_this == cities[find_in_here].cities_i_am_connected_with[i])
        {
            return false;
        }
        if(!path_taken[cities[find_in_here].cities_i_am_connected_with[i]])
        {
            path_taken[cities[find_in_here].cities_i_am_connected_with[i]] = 1;
            if(circle_not_found(find_this,cities[find_in_here].cities_i_am_connected_with[i])==false)
            {
                path_taken[cities[find_in_here].cities_i_am_connected_with[i]] = 0;
                return false;
            }
            path_taken[cities[find_in_here].cities_i_am_connected_with[i]] = 0;
        }
    }
    return true;
}



void make_states(li find_state_for_this_city)
{
    edges edge;
    li u,v,number_of_edges_need_to_be_taken;
    queue <li> cities_in_the_same_state;
    priority_queue <edges> edges_between_cities;

    cities_in_the_same_state.push(find_state_for_this_city);
    number_of_edges_need_to_be_taken = -1;
    while(cities_in_the_same_state.size())
    {
        u = cities_in_the_same_state.front();
        cities_in_the_same_state.pop();
        cities[u].state = n_states;
        states[n_states].push_back(u);
        for(v=0;v<n;v++)
        {
            if(u!=v && distance_taken[u][v] == -1)
            {
                edge.u = u;
                edge.v = v;
                edge.cost = distance_between_cities[u][v] = distance_between_cities[v][u] = find_distance(u,v);
                distance_taken[u][v] = distance_taken[v][u] = 1;
                if(edge.cost <= r)
                {
                    edges_between_cities.push(edge);
                    if(cities[edge.v].state == -1)
                    {
                        cities_in_the_same_state.push(edge.v);
                        cities[edge.v].state = n_states;
                    }
                }
                else
                {
                    edges_between_states.push(edge);
                }
            }
        }
    }
    number_of_edges_need_to_be_taken = states[n_states].size() - 1;
    while(edges_between_cities.size())
    {
        edge = edges_between_cities.top();
        edges_between_cities.pop();
        path_taken[edge.v] = 1;
        if(circle_not_found(edge.u,edge.v) == false)
        {
            path_taken[edge.v] = 0;
            continue;
        }
        path_taken[edge.u] = 1;
        if(circle_not_found(edge.v,edge.u) == false)
        {
            path_taken[edge.u] = 0;
            continue;
        }
        path_taken[edge.u] = path_taken[edge.v] = 0;
        minimum_road = minimum_road + edge.cost;
        cities[edge.u].cities_i_am_connected_with.push_back(edge.v);
        cities[edge.v].cities_i_am_connected_with.push_back(edge.u);
        number_of_edges_need_to_be_taken--;
        if(!number_of_edges_need_to_be_taken)
        {
            break;
        }
    }
}


void count_rail_road_extension()
{
    li n_state_edges,i,j,k,l;
    edges edge;
    n_state_edges = n_states;
    while(edges_between_states.size())
    {
        edge = edges_between_states.top();
        edges_between_states.pop();
        if(cities[edge.u].state == cities[edge.v].state || edge_exists_between_states[cities[edge.u].state][cities[edge.v].state])
        {
            continue;
        }
        path_taken[edge.v] = 1;
        if(circle_not_found(edge.u,edge.v) == false)
        {
            path_taken[edge.v] = 0;
            continue;
        }
        path_taken[edge.u] = 1;
        if(circle_not_found(edge.v,edge.u) == false)
        {
            path_taken[edge.u] = 0;
            continue;
        }
        path_taken[edge.u] = path_taken[edge.v] = 0;
        minimum_rail = minimum_rail + distance_between_cities[edge.u][edge.v];
        edge_exists_between_states[cities[edge.u].state][cities[edge.v].state] = 1;
        cities[edge.u].cities_i_am_connected_with.push_back(edge.v);
        cities[edge.v].cities_i_am_connected_with.push_back(edge.u);
        n_state_edges--;
        if(!n_state_edges)
        {
            break;
        }
    }
}


int main()
{
    li i,j;

    cin>>n_case;
    memset(distance_taken,-1,sizeof(distance_between_cities));
    memset(edge_exists_between_states,0,sizeof(edge_exists_between_states));
    memset(path_taken,0,sizeof(path_taken));
    for(i=0;i<n_case;i++)
    {
        cin>>n>>r;

        minimum_road = minimum_rail = 0;
        for(j=0;j<n;j++)
        {
            cin>>cities[j].x>>cities[j].y;
            cities[j].state = -1;
        }
        n_states = -1;
        for(j=0;j<n;j++)
        {
            if(cities[j].state == -1)
            {
                n_states++;
                make_states(j);
            }
        }
        count_rail_road_extension();
        cout<<"Case #"<<i+1<<": "<<n_states+1<<" "<<round(minimum_road)<<" "<<round(minimum_rail)<<"\n";
        clear_everything();
    }
    return 0;
}

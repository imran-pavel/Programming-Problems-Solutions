#include <cstdio>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#define li long int

using namespace std;

li n,found;
string last;
vector <string> inputs[100000],cities;
map <string,string> parent;

void clear_vector()
{
    cities.clear();
    for(li i=0;i<100000;i++) inputs[i].clear();
}


void bfs(string root, string destination, map <string,li> list)
{
    //cout<<"GOT CALLED\n";
    queue <string> q;
    map <string,li> visited;
    found=-1;

    q.push(root);
    parent[root]="";

    //cout<<"ENTERED\n";

    while(!q.empty())
    {
        string u;
        li u_position,i;

        u=q.front();
        q.pop();
        visited[u]=1;
        u_position=list[u];
        for(i=0;i<inputs[u_position].size();i++)
        {
            string v=inputs[u_position][i];
            if(visited[v]!=1)
            {
                parent[v]=u;
                if(v==destination)
                {
                    found=1;
                    last=v;
                }
                visited[v]=1;
                q.push(v);
            }

        }
    }
}

void print_path()
{
    vector <string> route,from,to;

    while(last!="")
    {
        to.push_back(last);
        from.push_back(parent[last]);
        last=parent[last];
    }

    for(li i=from.size()-2;i>-1;i--)
    {
        cout<<from[i]<<" "<<to[i]<<"\n";
    }
}

int main()
{
    string s1,s2,root,destination;
    li pos,first=1;
    while(cin>>n)
    {
        li i;
        map <string,li> list;
        map <string,li> check;
        pos=-1;
        clear_vector();

        if(!first) cout<<"\n";
        //cout<<"First Loop\n";

        for(i=0;i<n;i++)
        {
            cin>>s1>>s2;
            if(!check[s1])
            {
                pos++;
                list[s1]=pos;
                cities.push_back(s1);
                check[s1]++;
            }
            if(!check[s2])
            {
                pos++;
                list[s2]=pos;
                cities.push_back(s2);
                check[s2]++;
            }
            inputs[list[s1]].push_back(s2);
            inputs[list[s2]].push_back(s1);
        }

        //cout<<"GOT OUT\n";

        cin>>root>>destination;

        //cout<<"CALLING\n";
        bfs(root,destination,list);
        //cout<<"FOUND: "<<found<<endl;
        if(found!=-1) print_path();
        else cout<<"No route\n";
        first=0;

        /*for(i=0;i<=pos;i++)
        {
            cout<<cities[i]<<": ";
            for(li j=0;j<inputs[i].size();j++)
            {
                cout<<inputs[i][j]<<" ";
            }
            cout<<endl;
        }*/
    }
    return 0;
}

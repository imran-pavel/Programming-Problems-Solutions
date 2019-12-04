#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#define li long int
#define big 1000000

using namespace std;

struct data
{  int x,y,cost;
    bool operator < ( const data& p ) const {
        return cost > p.cost;
    }
};

li field[1000][1000],big_field[1000][1000];
priority_queue <data> p_q;


void clear_q()
{
    while(p_q.size())
    {
        p_q.pop();
    }
}


void dikjstra(li last_x, li last_y)
{
    data node,temp;

    while(p_q.size())
    {
        node = p_q.top();
        if(node.x==last_x && node.y==last_y)
            {
                clear_q();
                return;
            }
        if(node.x-1>=0)
        {
            if(big_field[node.x-1][node.y]>field[node.x-1][node.y]+field[node.x][node.y])
            {
                field[node.x-1][node.y]=field[node.x-1][node.y]+field[node.x][node.y];
                big_field[node.x-1][node.y]=field[node.x-1][node.y];
                temp.x=node.x-1;
                temp.y=node.y;
                temp.cost=field[node.x-1][node.y];
                p_q.push(temp);
            }
        }
        if(node.y-1>=0)
        {
            if(big_field[node.x][node.y-1]>field[node.x][node.y-1]+field[node.x][node.y])
            {
                field[node.x][node.y-1]=field[node.x][node.y-1]+field[node.x][node.y];
                big_field[node.x][node.y-1]=field[node.x][node.y-1];
                temp.x=node.x;
                temp.y=node.y-1;
                temp.cost=field[node.x][node.y-1];
                p_q.push(temp);
            }
        }
        if(node.x+1<=last_x)
        {
            if(big_field[node.x+1][node.y]>field[node.x+1][node.y]+field[node.x][node.y])
            {
                field[node.x+1][node.y]=field[node.x+1][node.y]+field[node.x][node.y];
                big_field[node.x+1][node.y]=field[node.x+1][node.y];
                temp.x=node.x+1;
                temp.y=node.y;
                temp.cost=field[node.x+1][node.y];
                p_q.push(temp);
            }
        }
        if(node.y+1<=last_y)
        {
            if(big_field[node.x][node.y+1]>field[node.x][node.y+1]+field[node.x][node.y])
            {
                field[node.x][node.y+1]=field[node.x][node.y+1]+field[node.x][node.y];
                big_field[node.x][node.y+1]=field[node.x][node.y+1];
                temp.x=node.x;
                temp.y=node.y+1;
                temp.cost=field[node.x][node.y+1];
                p_q.push(temp);
            }
        }
        p_q.pop();
    }
}


int main()
{
    li n_case,n,m,i,j;

    cin>>n_case;
    while(n_case--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>field[i][j];
                big_field[i][j]=big;
            }
        }
        data node;
        node.x=0;
        node.y=0;
        node.cost=field[0][0];
        big_field[0][0]=field[0][0];
        p_q.push(node);
        dikjstra(n-1,m-1);
        cout<<field[n-1][m-1]<<"\n";
    }
    return 0;
}

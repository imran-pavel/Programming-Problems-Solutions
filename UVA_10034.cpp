#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <cmath>
#define li long int
#define big 1000000000

using namespace std;

struct points
{
    double x;
    double y;
} point_list[100];

li taken[100];

double count_distant(li i, li j)
{
    double a,b;
    a=(point_list[i].x-point_list[j].x)*(point_list[i].x-point_list[j].x);
    b=(point_list[i].y-point_list[j].y)*(point_list[i].y-point_list[j].y);
    return sqrt(a+b);
}

int main()
{
    li n_case,n_point,i,j,hold_j;
    double p_x,p_y,hold_min,ink,distant;
    cin>>n_case;
    while(n_case)
    {
        cin>>n_point;
        for(i=0;i<n_point;i++)
        {
            cin>>point_list[i].x>>point_list[i].y;
        }
        vector <li> taken_nodes;
        memset(taken,0,sizeof(taken));
        ink=0;
        taken_nodes.push_back(0);
        taken[0]++;
        while(taken_nodes.size()!=n_point)
        {
            hold_min=big;
            for(j=0;j<n_point;j++)
            {
                for(i=0;i<taken_nodes.size();i++)
                {
                    if(taken_nodes[i]!=j && !taken[j])
                    {
                        distant=count_distant(taken_nodes[i],j);
                        if(distant<hold_min)
                        {
                            hold_min=distant;
                            hold_j=j;
                        }
                    }
                }
            }
            ink=ink+hold_min;
            taken_nodes.push_back(hold_j);
            taken[hold_j]++;
        }
        printf("%.2lf\n",ink);
        if(n_case!=1) cout<<"\n";
        n_case--;
    }
    return 0;
}

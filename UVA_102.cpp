#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define li long int

using namespace std;

li input[9];
string possible_permutations[6];
vector < vector<int> > b(3),g(3),c(3);

void set_initials()
{
    possible_permutations[0] = "BCG";
    possible_permutations[1] = "BGC";
    possible_permutations[2] = "CBG";
    possible_permutations[3] = "CGB";
    possible_permutations[4] = "GBC";
    possible_permutations[5] = "GCB";

    b[0].push_back(3);
    b[0].push_back(6);
    b[1].push_back(0);
    b[1].push_back(6);
    b[2].push_back(0);
    b[2].push_back(3);

    g[0].push_back(4);
    g[0].push_back(7);
    g[1].push_back(1);
    g[1].push_back(7);
    g[2].push_back(1);
    g[2].push_back(4);

    c[0].push_back(5);
    c[0].push_back(8);
    c[1].push_back(2);
    c[1].push_back(8);
    c[2].push_back(2);
    c[2].push_back(5);
}


li return_n_moves(li nth_string)
{
    li i,total,j;

    for(total=i=0;i<3;i++)
    {
        if(possible_permutations[nth_string][i]=='B')
        {
            for(j=0;j<2;j++)
            {
                total = total+input[b[i][j]];
            }
        }
        else if(possible_permutations[nth_string][i]=='G')
        {
            for(j=0;j<2;j++)
            {
                total = total+input[g[i][j]];
            }
        }
        else
        {
            for(j=0;j<2;j++)
            {
                total = total+input[c[i][j]];
            }
        }
    }
    return total;
}

int main()
{
    li i,j,k,selected_string,minimum_moves,hold;

    set_initials();
    while(cin>>input[0])
    {
        for(i=1;i<9;i++)
        {
            cin>>input[i];
        }
        minimum_moves = '0x3F';

        for(i=0;i<6;i++)
        {
            hold = return_n_moves(i);
            //cout<<"for "<<possible_permutations[i]<<" got "<<hold<<"\n";
            if(minimum_moves>hold)
            {
                minimum_moves = hold;
                selected_string = i;
            }
        }
        cout<<possible_permutations[selected_string]<<" "<<minimum_moves<<"\n";
    }
    return 0;
}

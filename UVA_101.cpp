#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#define li long int

using namespace std;

void print_piles(li n, vector < vector<int> > &piles)
{
    li i,j;

    for(i=0;i<n;i++)
    {
        cout<<i<<":";
        for(j=0;j<piles[i].size();j++)
        {
            cout<<" "<<piles[i][j];
        }
        cout<<"\n";
    }
}


void set_initial_piles(li n, li pile_location[], vector < vector <int> > &piles)
{
    li i;

    for(i=0;i<n;i++)
    {
        piles[i].push_back(i);
        pile_location[i] = i;
    }
}

li find_index(li a_or_b, li pile_location[], vector < vector<int> > &piles)
{
    li i;

    for(i=0;i<piles[pile_location[a_or_b]].size();i++)
    {
        if(piles[pile_location[a_or_b]][i] == a_or_b)
        {
            return i;
        }
    }
}

void return_to_initial(li pile_number, li start, li pile_location[], vector < vector<int> > &piles)
{
    li i;
    for(i=start;i<piles[pile_number].size();i++)
    {
        piles[piles[pile_number][i]].push_back(piles[pile_number][i]);
        pile_location[piles[pile_number][i]] = piles[pile_number][i];
    }
}

void move_onto(li a, li b, li pile_location[], vector < vector<int> > &piles)
{
    li i,index_a,index_b,hold_a;

    index_a = find_index(a,pile_location,piles);
    hold_a = piles[pile_location[a]][index_a];
    return_to_initial(pile_location[a],index_a+1,pile_location,piles);
    piles[pile_location[a]].erase(piles[pile_location[a]].begin()+index_a,piles[pile_location[a]].begin()+piles[pile_location[a]].size());

    index_b = find_index(b,pile_location,piles);
    return_to_initial(pile_location[b],index_b+1,pile_location,piles);
    piles[pile_location[b]].erase(piles[pile_location[b]].begin()+index_b+1,piles[pile_location[b]].begin()+piles[pile_location[b]].size());

    piles[pile_location[b]].push_back(a);
    pile_location[a] = pile_location[b];
}


void move_over(li a, li b, li pile_location[], vector < vector<int> > &piles)
{
    li i,index_a,index_b,hold_a;

    index_a = find_index(a,pile_location,piles);
    hold_a = piles[pile_location[a]][index_a];
    return_to_initial(pile_location[a],index_a+1,pile_location,piles);
    piles[pile_location[a]].erase(piles[pile_location[a]].begin()+index_a,piles[pile_location[a]].begin()+piles[pile_location[a]].size());

    piles[pile_location[b]].push_back(a);
    pile_location[a] = pile_location[b];
}

void pile_up_on_b(li index_a, li a, li b, li pile_location[], vector < vector<int> > &piles)
{
    li i,current_pile_location;

    current_pile_location = pile_location[a];
    for(i=index_a;i<piles[current_pile_location].size();i++)
    {
        piles[pile_location[b]].push_back(piles[current_pile_location][i]);
        pile_location[piles[current_pile_location][i]] = pile_location[b];
    }
}

void pile_onto(li a, li b, li pile_location[], vector < vector<int> > &piles)
{
    li index_a,index_b,current_pile_location;

    index_b = find_index(b,pile_location,piles);
    return_to_initial(pile_location[b],index_b+1,pile_location,piles);
    piles[pile_location[b]].erase(piles[pile_location[b]].begin()+index_b+1,piles[pile_location[b]].begin()+piles[pile_location[b]].size());


    index_a = find_index(a,pile_location,piles);
    current_pile_location = pile_location[a];
    pile_up_on_b(index_a,a,b,pile_location,piles);
    piles[current_pile_location].erase(piles[current_pile_location].begin()+index_a,piles[current_pile_location].begin()+piles[current_pile_location].size());
}

void pile_over(li a, li b, li pile_location[], vector < vector<int> > &piles)
{
    li index_a,current_pile_location;

    index_a = find_index(a,pile_location,piles);
    current_pile_location = pile_location[a];
    pile_up_on_b(index_a,a,b,pile_location,piles);
    piles[current_pile_location].erase(piles[current_pile_location].begin()+index_a,piles[current_pile_location].begin()+piles[current_pile_location].size());
}



int main()
{
    li n,i,j,a,b;
    string command1,command2;

    while(cin>>n)
    {
        vector < vector <int> > piles(24);
        li pile_location[24];

        set_initial_piles(n, pile_location, piles);
        while(cin>>command1)
        {
            if(!command1.compare("quit"))
            {
                break;
            }
            else
            {
                cin>>a>>command2>>b;
                if(a==b || pile_location[a]==pile_location[b])
                {
                    continue;
                }
                if(!command1.compare("move") && !command2.compare("onto"))
                {
                    move_onto(a,b,pile_location,piles);
                }
                else if(!command1.compare("move") && !command2.compare("over"))
                {
                    move_over(a,b,pile_location,piles);
                }
                else if(!command1.compare("pile") && !command2.compare("onto"))
                {
                    pile_onto(a,b,pile_location,piles);
                }
                else
                {
                    pile_over(a,b,pile_location,piles);
                }
            }
        }
        print_piles(n,piles);
    }
    return 0;
}

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define li long int

using namespace std;

int main()
{
    li n_problem,n_team,n_submission,time,id,i,j,already_solved;
    string verdict;
    char problem;

    while(scanf("%ld %ld %ld",&n_problem,&n_team,&n_submission)==3)
    {
        vector<int>submissions[101];
        map<char,int> blood_time,b_team;
        for(i=1;i<=n_submission;i++)
        {
            cin>>time>>id>>problem>>verdict;
            if(verdict=="Yes")
            {
                already_solved=0;
                for(j=0;j<submissions[id].size();j++)
                {
                    if(submissions[id][j]==problem)
                    {
                        already_solved++;
                    }
                }
                if(!already_solved)
                {
                    blood_time[problem]=time;
                    b_team[problem]=id;
                    submissions[id].push_back(problem);
                }
            }
        }
        for(i=65;i<65+n_problem;i++)
        {
            problem=i;
            if(b_team[problem]!=0)
            {
                cout<<problem<<" "<<blood_time[problem]<<" "<<b_team[problem]<<"\n";
            }
            else
            {
                cout<<problem<<" - -"<<"\n";
            }
        }
    }
    return 0;
}

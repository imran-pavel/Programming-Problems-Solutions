#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#define MaxNPeople 10

using namespace std;
typedef long long int i64;


i64 NPeople;
string Names[MaxNPeople];


int main()
{
    i64 i, j, AmountToDistribute, IsFirst;

    IsFirst = 1;
    while(cin>>NPeople)
    {
        string Name, FriendsName;
        vector < vector<string> > FriendsList(NPeople);
        map < string, i64 > StartingAmount, CurrentAmount;
        map < string, i64 > NFriends, NthIndex;

        for(i=0; i<NPeople; i++)
        {
            cin >> Names[i];
            NthIndex[Names[i]] = i;
        }
        for(i=0; i<NPeople; i++)
        {
            cin >> Name;
            cin >> StartingAmount[Name];
            cin >> NFriends[Name];
            for(j=0; j<NFriends[Name]; j++)
            {
                cin >> FriendsName;
                FriendsList[NthIndex[Name]].push_back(FriendsName);
            }
        }

        for(i=0; i<NPeople; i++)
        {
            if(StartingAmount[Names[i]] == 0 || NFriends[Names[i]] == 0)
            {
                CurrentAmount[Names[i]] += StartingAmount[Names[i]];
                continue;
            }
            AmountToDistribute = StartingAmount[Names[i]] / NFriends[Names[i]];
            CurrentAmount[Names[i]] += StartingAmount[Names[i]] - AmountToDistribute * NFriends[Names[i]];
            for(j=0; j<NFriends[Names[i]]; j++)
            {
                CurrentAmount[FriendsList[i][j]] += AmountToDistribute;
            }
        }
        if(IsFirst)
        {
            IsFirst = 0;
        }
        else
        {
            cout << "\n";
        }
        for(i=0; i<NPeople; i++)
        {
            cout << Names[i] << " " << CurrentAmount[Names[i]] - StartingAmount[Names[i]] << "\n";
        }
    }
    return 0;
}

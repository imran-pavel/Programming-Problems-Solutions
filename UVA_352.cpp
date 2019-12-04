#include <iostream>
#include <string.h>

using namespace std;

int count,n;
string field[25];

void flood_fill(int x, int y)
{
    if(field[x][y]!='1') return;
    field[x][y]='A';
    if(y+1<n) flood_fill(x,y+1);
    if(x-1>-1 && y+1<n) flood_fill(x-1,y+1);
    if(x+1<n && y+1<n) flood_fill(x+1,y+1);
    if(x-1>-1) flood_fill(x-1,y);
    if(x+1<n) flood_fill(x+1,y);
    if(y-1>-1) flood_fill(x,y-1);
    if(x-1>-1 && y-1>-1) flood_fill(x-1,y-1);
    if(x+1<n && y-1>-1) flood_fill(x+1,y-1);
}

int main()
{
    int i,n_case=1,j;
    char fau[2];

    while(cin>>n)
        {
            count=0;
            for(i=0;i<n;i++)
                {
                    cin>>field[i];
                }
            for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                        {
                            if(field[i][j]=='1')
                                {
                                    count++;
                                    flood_fill(i,j);
                                }
                        }
                }
            cout<<"Image number "<<n_case<<" contains "<<count<<" war eagles.\n";
            n_case++;
        }
    return 0;
}

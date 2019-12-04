#include <cstdio>
#include <cstring>
#include <iostream>
#define li long int

using namespace std;

char input[101][101];
li lengths[100];

int main()
{
    li i,j,max_length,k;

    i=0;
    max_length = -1;
    while(gets(input[i]))
    {
        lengths[i] = strlen(input[i]);
        if(max_length<lengths[i])
        {
            max_length = lengths[i];
        }
        i++;
    }
    for(j=0;j<max_length;j++)
    {
        for(k=i-1;k>-1;k--)
        {
            if(j>=lengths[k])
            {
                cout<<" ";
                continue;
            }
            cout<<input[k][j];
        }
        cout<<"\n";
    }
    return 0;
}

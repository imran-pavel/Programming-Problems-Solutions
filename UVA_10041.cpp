#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#define li long int

using namespace std;

li inputs[500];

int main()
{
    li n_case,i,n_input,j,res;

    cin>>n_case;
    while(n_case--)
    {
        cin>>n_input;
        for(j=0;j<n_input;j++)
        {
            cin>>inputs[j];
        }
        sort(inputs,inputs+n_input);
        res=0;
        if(n_input>1)
        {
            for(j=0;j<n_input;j++)
            {
                res=res+abs(inputs[j]-inputs[n_input/2]);
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}

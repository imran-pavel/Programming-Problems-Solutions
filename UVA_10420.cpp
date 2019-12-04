#include <iostream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long int lli;

pair <string,int> outputs[1000000];

char input[76],country[74];

void find_country_name()
{
    lli i=0;
    while(input[i]!=' ')
        {
            country[i]=input[i];
            i++;
        }
    country[i]=0;
}

int match_a_country(int limit)
{
    lli i;
    for(i=0;i<=limit;i++)
        {
            if(outputs[i].first==country)
                {
                    outputs[i].second++;
                    return 1;
                }
        }
    return 0;
}

void print(int limit)
{
    lli i;

    for(i=0;i<limit;i++)
        {
            cout<<outputs[i].first<<' '<<outputs[i].second<<'\n';
        }
}

int main()
{
    lli i,n_case,in=-1;
    char fau[2];
    cin>>n_case;
    gets(fau);

    for(i=1;i<=n_case;i++)
        {
            gets(input);
            find_country_name();
            if(in==-1)
                {
                    in++;
                    outputs[in].first=country;
                    outputs[in].second=1;
                }
            else if(!(match_a_country(in)))
                {
                    in++;
                    outputs[in].first=country;
                    outputs[in].second=1;
                }
        }
    in++;
    sort(outputs,outputs+in);
    print(in);
    return 0;
}

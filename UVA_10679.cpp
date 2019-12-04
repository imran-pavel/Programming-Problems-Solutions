#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int check(string a, string q)
{
    int i;
    for(i=0;i<q.size();i++)
        {
            if(q[i]!=a[i]) return 0;
        }
    return 1;
}

int main()
{
    int n,t_case,i,x;
    string a,q;

    cin>>n;
    while(n)
        {
            cin>>a;
            cin>>t_case;
            while(t_case)
                {
                    cin>>q;
                    x=check(a,q);
                    if(x==1) cout<<"y\n";
                    else cout<<"n\n";
                    t_case--;
                }
            n--;
        }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#define li long int

using namespace std;

bool is_great(li a, li b, li c, li d)
{
    if(b >= 2*a && c >= 2*a && d >= 2*a) return true;
    if(a/2 >= b && a/2 >= c && a/2 >= d) return true;
    return false;
}

int main()
{
    string a,b,c,d,great;
    li great_counter,l_a,l_b,l_c,l_d;
    while(cin>>a)
    {
        cin>>b>>c>>d;
        great_counter=0;
        l_a = a.length();
        l_a = l_a-2;
        l_b = b.length();
        l_b = l_b-2;
        l_c = c.length();
        l_c = l_c-2;
        l_d = d.length();
        l_d = l_d-2;
        if(is_great(l_a,l_b,l_c,l_d))
        {
            great_counter++;
            great="A";
        }
        if(is_great(l_b,l_a,l_c,l_d))
        {
            great_counter++;
            great="B";
        }
        if(is_great(l_c,l_b,l_a,l_d))
        {
            great_counter++;
            great="C";
        }
        if(is_great(l_d,l_b,l_c,l_a))
        {
            great_counter++;
            great="D";
        }
        if(great_counter!=1) great="C";
        cout<<great<<"\n";
    }
    return 0;
}
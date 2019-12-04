#include <iostream>

using namespace std;

int right_angle(int a, int b, int c)
{
    if(a*a+b*b==c*c) return 1;
    return 0;
}

int main()
{
    int n,a,b,c;
    cin>>n;
    while(n--)
        {
            cin>>a>>b>>c;
            if(right_angle(a,b,c)||right_angle(b,c,a)||right_angle(a,c,b)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    return 0;
}

#include <cstdio>
#include <iostream>
#define li long int

using namespace std;

int main()
{
    li n,num1,num2;

    cin >> n;
    while(n--)
    {
        cin>>num1>>num2;
        if(num2%num1!=0)
        {
            cout<<-1<<"\n";
        }
        else
        {
            cout<<num1<<" "<<num2<<"\n";
        }
    }
    return 0;
}

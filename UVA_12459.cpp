#include <iostream>

using namespace std;

typedef long long int lli;

lli fib_nums[79];

void generate_fib_numbers()
{
    lli i;

    fib_nums[0]=1;
    fib_nums[1]=2;
    for(i=2;;i++)
        {
            fib_nums[i]=fib_nums[i-1]+fib_nums[i-2];
            //cout<<"Position "<<i+1<<":   Fib Number: "<<fib_nums[i]<<endl;
            if(i==79) break;
        }
}

int main()
{
    generate_fib_numbers();

    lli n_ancestor;

    for(;;)
        {
            cin>>n_ancestor;
            if(n_ancestor) cout<<fib_nums[n_ancestor-1]<<'\n';
            else break;
        }
    return 0;
}

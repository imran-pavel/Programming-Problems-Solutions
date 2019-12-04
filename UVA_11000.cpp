#include <iostream>

using namespace std;

typedef long long int lli;

lli fib_nums[48];

void generate_fib_numbers()
{
    lli i;

    fib_nums[0]=fib_nums[1]=1;
    for(i=2;;i++)
        {
            fib_nums[i]=fib_nums[i-1]+fib_nums[i-2];
            //cout<<"Position "<<i+1<<":   Fib Number: "<<fib_nums[i]<<endl;
            if(i==47) break;
        }
}

int main()
{
    generate_fib_numbers();

    lli n_year,i,m_bee,t_bee;

    for(;;)
        {
            cin>>n_year;
            if(n_year==-1) break;
            m_bee=0,t_bee=1;
            if(n_year==0) cout<<m_bee<<" "<<t_bee<<'\n';
            else
                {
                    for(i=1;;i++)
                        {
                            m_bee=m_bee+fib_nums[i-1];
                            t_bee=t_bee+fib_nums[i];
                            if(i==n_year)
                                {
                                    cout<<m_bee<<" "<<t_bee<<'\n';
                                    break;
                                }
                        }
                }
        }
    return 0;
}


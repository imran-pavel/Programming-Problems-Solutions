#include <stdio.h>
#include <string.h>

typedef long long int lli;

lli fib_numbers[45],n_fib_num,input_fib[1000000],h_l,l_l,mid;
lli positions[1000000];

void generate_fibonacci_number()
{
    lli i;
    fib_numbers[0]=1;
    fib_numbers[1]=2;

    for(i=2;i<45;i++)
        {
            fib_numbers[i]=fib_numbers[i-1]+fib_numbers[i-2];
        }
}

lli binary_search(lli num)
{
    l_l=0,h_l=44;
    while(l_l<=h_l)
        {
            mid=(l_l+h_l)/2;
            if(fib_numbers[mid]==num) return mid;
            else if(fib_numbers[mid]>num) h_l=mid-1;
            else l_l=mid+1;
        }
}

int main()
{
    generate_fibonacci_number();

    lli n,i,j,k,max;
    char fau[2],input[101],output[101];

    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        {
            scanf("%lld",&n_fib_num);
            for(j=0;j<n_fib_num;j++)
                {
                    scanf("%lld",&input_fib[j]);
                    positions[j]=binary_search(input_fib[j]);
                }
            gets(fau);
            gets(input);
            memset(output,' ',sizeof(output));
            max=k=j=0;
            int ab;
            while(j<n_fib_num && input[k])
                {
                    if(input[k]>='A' && input[k]<='Z')
                        {
                            output[positions[j]]=input[k];
                            if(positions[j]>=max) max=positions[j];
                            j++;
                        }
                    k++;
                }
            output[max+1]=0;
            puts(output);
        }
    return 0;
}

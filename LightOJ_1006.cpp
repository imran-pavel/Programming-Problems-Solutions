#include <stdio.h>
#include <string.h>
#define lli long long int

lli a, b, c, d, e, f;
lli storage[100000];


int fn( int n )
{
    if( n == 0 ) return storage[n];
    if( n == 1 ) return storage[n];
    if( n == 2 ) return storage[n];
    if( n == 3 ) return storage[n];
    if( n == 4 ) return storage[n];
    if( n == 5 ) return storage[n];
    lli i;
    for(i=6;i<=n;i++)
        {
            storage[i]=(storage[i-1]%10000007+storage[i-2]%10000007+storage[i-3]%10000007+storage[i-4]%10000007+storage[i-5]%10000007+storage[i-6]%10000007)% 10000007;
        }
    return storage[n];
}
int main()
{
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- )
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        storage[0]=a;
        storage[1]=b;
        storage[2]=c;
        storage[3]=d;
        storage[4]=e;
        storage[5]=f;
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}

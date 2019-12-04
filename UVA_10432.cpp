#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip>
#define pi acos(-1)

using namespace std;

int main()
{
    double res,r,n;

    while(cin>>r>>n)
    {
        res = ((n*(r*r))/2) * sin((2*pi)/n);
        printf("%.3lf\n",res);
    }
}

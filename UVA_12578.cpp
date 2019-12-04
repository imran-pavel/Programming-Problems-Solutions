#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n,l;
    double r,c=(1.0*3)/5,a,pi=acos(-1);

    cin>>n;
    while(n)
        {
            cin>>l;
            r=((double)l)/5;
            r=pi*(r*r);
            a=((l*c)*l)-r;
            printf("%.2lf %.2lf\n",r,a);
            n--;
        }
    return 0;
}

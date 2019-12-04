#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,s,d,r;
    while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
    {
        s=(a+b+c)/2;
        d=sqrt(s*(s-a)*(s-b)*(s-c));
        r=(4*d)/3;
        if(r>0.000)
        printf("%.3lf\n",r);
        else
        printf("-1.000\n");
    }
   return 0;
}
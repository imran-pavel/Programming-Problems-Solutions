#include <stdio.h>
int main()
{
    long long int a,b;
    while(scanf("%lld %lld",&a,&b)!=EOF)
        {
            for(;;a++)
                {
                    b=b-a;
                    if(b==0||b<0) break;
                }
            printf("%lld\n",a);
        }
    return 0;
}

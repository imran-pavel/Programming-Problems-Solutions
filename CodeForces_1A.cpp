#include <stdio.h>

int main()
{
    __int64 n,m,a,temp1,temp2,x;

    while(scanf("%I64d %I64d %I64d",&n,&m,&a)!=EOF)
        {
            temp1=n/a;
            if(n%a!=0) temp1++;
            temp2=m/a;
            if(m%a!=0) temp2++;
            x=temp1*temp2;
            printf("%I64d\n",x);
        }
    return 0;
}

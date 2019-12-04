#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binary_count(int num)
{
    int count=0,c;
    for(;;)
        {
            c=num%2;
            if(c==1) count++;
            if(num/2==0) return count;
            num=num/2;
        }
}

int hexa_conversion(int num)
{
    int i,sum=0,digit;
    for(i=0;;i++)
        {
            digit=(num%10);
            sum=sum+(pow(16,i)*digit);
            num=num/10;
            if(num==0) return sum;
        }
}

int main()
{
    int n,i,num,binary_parity,hexa_parity;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
            scanf("%d",&num);
            binary_parity=binary_count(num);
            num=hexa_conversion(num);
            hexa_parity=binary_count(num);
            printf("%d %d\n",binary_parity,hexa_parity);
        }
    return 0;
}

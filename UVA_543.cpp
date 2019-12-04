#include <stdio.h>
#include <math.h>

int prime_or_not(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
        {
            if(n%i==0) return 0;
        }
    return 1;
}

int main()
{
    int number,temp,x,check1,check2,i;
    for(;;)
        {
            scanf("%d",&number);
            x=0;
            if(number==0) break;
            else
                {
                    for(i=2;i<number-1;i++)
                        {
                            temp=number-i;
                            check1=prime_or_not(temp);
                            check2=prime_or_not(i);
                            if(check1==1 && check2==1)
                                {
                                    printf("%d = %d + %d\n",number,i,temp);
                                    x++;
                                    break;
                                }
                        }
                    if(x==0) printf("Goldbach's conjecture is wrong.\n");
                }
        }
    return 0;
}

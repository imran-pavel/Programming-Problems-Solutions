#include <stdio.h>

void result(int number)
{
    int i,limit=number/2,check=0;

    for(i=1;i<=limit;i++)
        {
            if(number%i==0) check=check+i;
        }
    if(check==number)
        {
            printf("%5d  PERFECT\n",number);
        }
    else if(check>number)
        {
            printf("%5d  ABUNDANT\n",number);
        }
    else if(check<number)
        {
            printf("%5d  DEFICIENT\n",number);
        }
}

int main()
{
    int num,inputs[100],i=0;
    while(1)
        {
            scanf("%d",&num);
            if(num==0) break;
            inputs[i]=num;
            i++;
        }
    inputs[i]=-1;
    printf("PERFECTION OUTPUT\n");
    for(i=0;;i++)
        {
            if(inputs[i]==-1) break;
            result(inputs[i]);
        }
    printf("END OF OUTPUT\n");
    return 0;
}

#include <stdio.h>
#define li long int

int main()
{
    li N,i,MaxStreak,Sum,Value;
    while(1)
    {
        scanf("%ld",&N);
        if(!N) break;
        MaxStreak = -1;
        Sum = 0;
        for(i=0;i<N;i++)
        {
            scanf("%ld",&Value);
            Sum = Sum + Value;
            if(Value > 0)
            {
                if(Sum > MaxStreak) MaxStreak = Sum;
            }
            if(Sum < 0) Sum = 0;
        }
        if(Sum<=0)
        {
            printf("Losing streak.\n");
        }
        else
        {
            printf("The maximum winning streak is %ld.\n",MaxStreak);
        }
    }
    return 0;
}

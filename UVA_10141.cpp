#include <cstdio>
#include <iostream>
#include <cstring>
#define li long int

using namespace std;

char useless[85],winner[85],fau[2],name[85];

int main()
{
    li n,p,i,n_met,winner_met,serial_number,newline_flag,j;
    double price,winner_price;

    newline_flag = 0;
    serial_number = 1;
    while(1)
    {
        scanf("%ld %ld",&n,&p);
        gets(fau);
        winner_met = -1;
        winner_price = -1;
        if(!n && !p)
        {
            break;
        }
        for(i=1;i<=n;i++)
        {
            gets(useless);
        }
        for(i=1;i<=p;i++)
        {
            gets(name);
            scanf("%lf %ld",&price,&n_met);
            gets(fau);
            for(j=1;j<=n_met;j++)
            {
                gets(useless);
            }
            if(winner_met<n_met)
            {
                strcpy(winner,name);
                winner_met = n_met;
                winner_price = price;
            }
            else if(winner_met == n_met)
            {
                if(price < winner_price)
                {
                    strcpy(winner,name);
                    winner_met = n_met;
                    winner_price = price;
                }
            }
        }
        if(newline_flag)
        {
            printf("\n");
        }
        printf("RFP #%ld\n",serial_number);
        printf("%s\n",winner);
        newline_flag = 1;
        serial_number++;
    }
    return 0;
}

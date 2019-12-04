#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n,amount,i,x;
    double tax;

    cin>>n;
    for(i=1;i<=n;i++)
        {
            cin>>amount;
            if(amount<=180000) cout<<"Case "<<i<<": 0\n";
            else
                {
                    amount=amount-180000;
                    if(amount<300000) tax=((double)amount*10)/100;
                    else
                        {
                            tax=((double)300000*10)/100;
                            amount=amount-300000;
                            if(amount<400000) tax=tax+((double)amount*15)/100;
                            else
                                {
                                    tax=tax+((double)400000*15)/100;
                                    amount=amount-400000;
                                    if(amount<300000) tax=tax+((double)amount*20)/100;
                                    else
                                        {
                                            tax=tax+((double)300000*20)/100;
                                            amount=amount-300000;
                                            if(amount!=0) tax=tax+((double)amount*25)/100;
                                        }
                                }
                        }
                    if(tax>0 && tax<2000) tax=2000;
                    x=ceil(tax);
                    cout<<"Case "<<i<<": "<<x<<'\n';
                }
        }
    return 0;
}
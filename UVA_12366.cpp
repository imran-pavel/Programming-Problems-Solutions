#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

lli ar[3],x,card1,card2,card3;

void print(lli card1, lli card2, lli card3)
{
    ar[0]=card1,ar[1]=card2,ar[2]=card3;
    sort(ar,ar+3);
    cout<<ar[0]<<' '<<ar[1]<<' '<<ar[2]<<'\n';
}

void change_set(lli v)
{
    v++;
    if(v>13)
        {
            x=1;
            return;
        }
    else
        {
            card1=card2=card3=v;
        }
}

void change_pair(lli c1, lli c2, lli c3)
{
    c3++;
    if(c3==c1) c3++;
    if(c3>13)
        {
            ++c1;
            ++c2;
            if(c1>13) c1=c2=1;
            print(c1,c2,1);
        }
    else
        {
            print(c1,c2,c3);
        }
}

int main()
{
    for(;;)
        {
            cin>>card1>>card2>>card3;
            if(card1==0 && card2==0 && card3==0) break;
            x=0;
            if(card1==card2 && card2==card3)
                {
                    change_set(card1);
                    if(x==1) cout<<"*\n";
                    else print(card1,card3,card2);
                }
            else
                {
                    if(card1==card2)
                        {
                            change_pair(card1,card2,card3);
                        }
                    else if(card2==card3)
                        {
                            change_pair(card2,card3,card1);
                        }
                    else if(card1==card3)
                        {
                            change_pair(card1,card3,card2);
                        }
                    else
                        {
                            print(1,1,2);
                        }
                }
        }
    return 0;
}

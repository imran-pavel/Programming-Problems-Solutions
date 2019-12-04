#include <iostream>
#include <queue>

using namespace std;

typedef long long int lli;

lli thrown[51];
queue <int> cards,temp;

void set_queue(lli n)
{
    lli i;

    while(cards.size())
        {
            cards.pop();
        }

    for(i=1;i<=n;i++)
        {
            cards.push(i);
        }
}

int main()
{
    lli n,count,t,j;

    for(;;)
        {
            cin>>n;
            if(n==0) break;
            else
                {
                    if(n==1)
                        {
                            cout<<"Discarded cards:\n";
                            cout<<"Remaining card: 1\n";
                        }
                    else
                        {
                            set_queue(n);
                            j=0;
                            while(cards.size()>1)
                                {
                                    thrown[j]=cards.front();
                                    cards.pop();
                                    j++;
                                    cards.push(cards.front());
                                    cards.pop();
                                }
                            cout<<"Discarded cards: ";
                            for(t=0;t<j-1;t++) cout<<thrown[t]<<','<<' ';
                            cout<<thrown[t]<<'\n';
                            cout<<"Remaining card: "<<cards.front()<<'\n';
                        }
                }
        }
    return 0;
}
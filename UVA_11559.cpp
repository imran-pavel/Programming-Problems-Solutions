#include <iostream>

using namespace std;

int weeks[13],n,b,h,w,price,i;

int cost(int w)
{
    int i,minimum=-1,temp;

    for(i=0;i<w;i++)
        {
            if(weeks[i]>=n)
                {
                    temp=n*price;
                    if(temp<=b)
                        {
                            if(minimum==-1) minimum=temp;
                            else if(temp<minimum) minimum=temp;
                        }
                }
        }
    return minimum;
}

int main()
{
    int temp,c;
    while(cin>>n>>b>>h>>w)
        {
            temp=0;
            while(h--)
                {
                    cin>>price;
                    for(i=0;i<w;i++)
                        {
                            cin>>weeks[i];
                        }
                    c=cost(w);
                    if(temp==0 && c!=-1) temp=c;
                    else if(temp!=0 && c!=-1 && temp>c) temp=c;
                }
            if(temp!=0) cout<<temp<<'\n';
            else cout<<"stay home\n";
        }
    return 0;
}

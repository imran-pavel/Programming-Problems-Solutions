#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

pair<int , int > inputs[5000];

int main()
{
    int i,a,x,b,y,petya,vasya,k;
    while(scanf("%d %d %d %d",&x,&y,&a,&b)!=EOF)
    {
        k=0;
        for(vasya=a;vasya<=x;vasya++)
            {
                for(petya=b;vasya>petya;petya++)
                    {
                        if(y<petya) break;
                        inputs[k].first=vasya;
                        inputs[k].second=petya;
                        k++;
                    }
            }
        sort(inputs,inputs+k);
        printf("%d\n",k);
        for(i=0;i<k;i++)
            {
                printf("%d %d\n",inputs[i].first,inputs[i].second);
            }
    }
    return 0;
}

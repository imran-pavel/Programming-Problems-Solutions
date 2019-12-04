#include <stdio.h>
int main()
{
    int event,k=0,i,j=1,x,l=0;
    for(;;)
        {
            scanf("%d",&event);
            int ar[event];
            if(event!=0)
                {
                    for(i=1;i<=event;i++)
                        {
                            scanf("%d",&ar[i-1]);
                            if(ar[i-1]==0) k++;
                            else if(ar[i-1]!=0) l++;
                        }
                    x=l-k;
                    printf("Case %d: %d\n",j,x);
                    l=0;
                    k=0;
                    j++;
                }
            else if(event==0) break;
        }
    return 0;
}

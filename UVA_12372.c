#include <stdio.h>
int main()
{
    int n,l,w,h,j,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {

                    scanf("%d %d %d",&l,&w,&h);
                    if((l>0 && l<21)&&(w>0 && w<21)&&(h>0 && h<21))printf("Case %d: good\n",i);
                    else printf("Case %d: bad\n",i);
        }
    return 0;
}

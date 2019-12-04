#include <stdio.h>

int main()
{
    int n,total;
    for(;;)
        {
            scanf("%d",&n);
            if(n==0) break;
            else
                {
                    total=0;
                    for(;;n--)
                        {
                            total=total+(n*n);
                            if(n*n==1) break;
                        }
                    printf("%d\n",total);
                }
        }
    return 0;
}

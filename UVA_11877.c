#include <stdio.h>
int main()
{
    int i,num,a,b,drank=0,k=0;
    for(;;)
        {
            scanf("%d",&num);
            if(num!=0)
                {
                    for(;;)
                        {
                            a=num/3;
                            b=num%3;
                            drank=drank+a;
                            if(a==1 && b==0)
                                {
                                    printf("%d\n",drank);
                                    a=0,b=0;
                                    drank=0;
                                    break;
                                }
                            if(a+b==2)
                                {
                                    num=a+b+1;
                                }
                            else num=a+b;
                        }
                }
            else if(num==0) break;
        }
    return 0;
}

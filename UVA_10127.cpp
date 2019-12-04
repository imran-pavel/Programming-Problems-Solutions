#include <stdio.h>

int counter(int num)
{
    int count=1,len=1;
    for(;;)
        {
            if(len%num==0) return count;
            else
                {
                    len=(len%num)*10+1;
                    count++;
                }
        }
}

int main()
{
    int num,result;
    while(scanf("%d",&num)!=EOF)
        {
            result=counter(num);
            printf("%d\n",result);
        }
    return 0;
}

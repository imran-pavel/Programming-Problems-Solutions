#include <stdio.h>

typedef long int lli;

int main()
{
    lli n,i,c_d,c_m,c_y,b_d,b_m,b_y,age,x;

    scanf("%ld",&n);
    for(i=1;i<=n;i++)
        {
            scanf("%ld/%ld/%ld",&c_d,&c_m,&c_y);
            scanf("%ld/%ld/%ld",&b_d,&b_m,&b_y);
            x=0;
            if(c_y<b_y)
                {
                    printf("Case #%ld: Invalid birth date\n",i);
                    x++;
                }
            else
                {
                    if(c_y==b_y)
                        {
                            if(c_m<b_m)
                                {
                                    printf("Case #%ld: Invalid birth date\n",i);
                                    x++;
                                }
                            else
                                {
                                    if(c_m>b_m) age=0;
                                    else
                                        {
                                            if(c_d<b_d)
                                                {
                                                    printf("Case #%ld: Invalid birth date\n",i);
                                                    x++;
                                                }
                                            else age=0;
                                        }
                                }
                        }
                    else
                        {
                            if(c_m>b_m) age=c_y-b_y;
                            else if(c_m<b_m) age=c_y-b_y-1;
                            else
                                {
                                    if(c_d>=b_d) age=c_y-b_y;
                                    else if(c_d<b_d) age=c_y-b_y-1;
                                }
                        }
                    if(x==0)
                        {
                            if(age>130) printf("Case #%ld: Check birth date\n",i);
                            else printf("Case #%ld: %ld\n",i,age);
                        }
                }
        }
    return 0;
}
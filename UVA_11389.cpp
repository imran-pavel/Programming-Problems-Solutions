#include <stdio.h>

int main()
{
    int n,d,r,i,j,temp,total;
    for(;;)
        {
            scanf("%d %d %d",&n,&d,&r);
            if(n==0 && d==0 && r==0) break;
            else
                {
                    int m_routes[n],e_routes[n];
                    for(i=0;i<n;i++)
                        {
                            scanf("%d",&m_routes[i]);
                        }
                    for(i=0;i<n;i++)
                        {
                            scanf("%d",&e_routes[i]);
                        }
                    for(i=1;i<n;i++)
                        {
                            for(j=n-1;j>=i;j--)
                                {
                                    if(m_routes[j]<m_routes[j-1])
                                        {
                                            temp=m_routes[j];
                                            m_routes[j]=m_routes[j-1];
                                            m_routes[j-1]=temp;
                                        }
                                }
                        }
                    for(i=1;i<n;i++)
                        {
                            for(j=n-1;j>=i;j--)
                                {
                                    if(e_routes[j]<e_routes[j-1])
                                        {
                                            temp=e_routes[j];
                                            e_routes[j]=e_routes[j-1];
                                            e_routes[j-1]=temp;
                                        }
                                }
                        }
                    total=0;
                    for(i=0,j=n-1;i<n;i++,j--)
                        {
                           if((m_routes[i]+e_routes[j])>d)
                            {
                                total=total+(m_routes[i]+e_routes[j]-d);
                            }
                        }
                    total=total*r;
                    printf("%d\n",total);
                }
        }
    return 0;
}

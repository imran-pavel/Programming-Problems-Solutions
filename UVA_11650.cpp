#include <stdio.h>

int main()
{
    int n,a;
    double m,h,h_s,m_s;
    scanf("%d",&n);
    while(n--)
        {
            scanf("%lf:%lf",&h,&m);
            if(h==12 && m==0) printf("%.0lf:00\n",h);
            else if(h==6 && m==0) printf("0%.0lf:00\n",h);
            else if(h==9 && m==0) printf("03:00\n");
            else if(h==3 && m==0) printf("09:00\n");
            else
                {
                    m_s=m*6;
                    if(h==12) h=0;
                    h_s=h*30+((double)m*((1.0*1)/2));
                    m_s=360-m_s;
                    h_s=360-h_s;
                    m=(((double)60)/360)*m_s;
                    if(m==60) m=0;
                    h=/*((double)60/30)*/h_s;
                    if(h>=0 && h<30) h=12;
                    else if(h>=30 && h<60) h=1;
                    else if(h>=60 && h<90) h=2;
                    else if(h>=90 && h<120) h=3;
                    else if(h>=120 && h<150) h=4;
                    else if(h>=150 && h<180) h=5;
                    else if(h>=180 && h<210) h=6;
                    else if(h>=210 && h<240) h=7;
                    else if(h>=240 && h<270) h=8;
                    else if(h>=270 && h<300) h=9;
                    else if(h>=300 && h<330) h=10;
                    else if(h>=330 && h<360) h=11;
                    else h=12;
                    if(m>9 && h>9) printf("%.0lf:%.0lf\n",h,m);
                    else if(m<10 && h>9) printf("%.0lf:0%.0lf\n",h,m);
                    else if(m>9 && h<10) printf("0%.0lf:%.0lf\n",h,m);
                    else if(m<10 && h<10) printf("0%.0lf:0%.0lf\n",h,m);
                }
        }
    return 0;
}
#include <cstdio>
#include <iostream>
#define li long int

using namespace std;

li inputs[30];
li up_seq[30],down_seq[30];

double av(li is, li array[])
{
    li i,sum;
    double d;

    for(sum=i=0;i<=is;i++)
    {
        sum=sum+array[i];
    }
    d=((double)sum)/(is+1);
    return d;
}

int main()
{
    li i,in_len,state,path,us,ds,last_flag;
    double n,av_up,av_down;

    while(cin>>n)
    {
        i=-1;
        if(!n) break;
        inputs[++i]=n;
        while(cin>>n)
        {
            if(!n) break;
            inputs[++i]=n;
        }
        in_len=i+1;
        path=0;
        if(in_len==1)
        {
            av_up=av_down=0;
        }
        else
        {
            us=ds=state=-1;
            for(i=1;i<in_len;i++)
            {
                if(inputs[i-1]==inputs[i])
                {
                    path++;
                    last_flag=1;
                    continue;
                }
                else
                {
                    if(state==-1)
                    {
                        if(inputs[i-1]>inputs[i])
                        {
                            state=1; // means previous value is larger than the next one
                            path++;
                        }
                        else
                        {
                            state=0; // means previous value is smaller than the next one
                            path++;
                        }
                    }
                    else
                    {
                        if(inputs[i-1]>inputs[i] && state==1)
                        {
                            path++;
                            last_flag=1;
                        }
                        else if(inputs[i-1]<inputs[i] && state==1)
                        {
                            down_seq[++ds]=path;
                            path=1;
                            state=0;
                            last_flag=1;
                        }
                        else if(inputs[i-1]<inputs[i] && state==0)
                        {
                            path++;
                            last_flag=1;
                        }
                        else
                        {
                            up_seq[++us]=path;
                            path=1;
                            state=1;
                            last_flag=1;
                        }
                    }
                }
            }
        }
        if(last_flag && state!=-1)
        {
            if(state)
            {
                down_seq[++ds]=path;
            }
            else if(!state)
            {
                up_seq[++us]=path;
            }
        }
        if(ds>-1)
        {
            av_down=av(ds,down_seq);
        }
        else av_down=0;

        if(us>-1)
        {
            av_up=av(us,up_seq);
        }
        else av_up=0;
        cout<<"Nr values = "<<in_len<<":  ";
        printf("%.6lf %.6lf\n",av_up,av_down);
    }
    return 0;
}

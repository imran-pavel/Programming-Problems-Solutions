#include <stdio.h>

int x,check;
int inputs[102][2];

void faces(int top_value, int in)
{
    if(top_value==inputs[in][0] || top_value==inputs[in][1])
        {
            check++;
            return;
        }
    else
        {
            if(7-inputs[in][0]==top_value || 7-inputs[in][1]==top_value)
                {
                    check++;
                    return;
                }
            else
                {
                    in++;
                    if(in==x) return;
                    top_value=7-top_value;
                    faces(top_value,in);
                }
        }
}

int main()
{
    int i;
    while(scanf("%d",&x)!=EOF)
    {
        int t;
        check=0;
        scanf("%d",&t);
        for(i=0;i<x;i++)
            {
                scanf("%d %d",&inputs[i][0],&inputs[i][1]);
            }
        faces(t,0);
        if(check==0)
            {
                printf("YES\n");
            }
        else printf("NO\n");
    }
    return 0;
}

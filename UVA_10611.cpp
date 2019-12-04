#include <stdio.h>

int n,lower,upper,num,heights[50000],queries[25000];

void lower_upper(int in)
{
    int i;
    for(i=in-1;i>-1;i--)
        {
            if(heights[i]!=num)
                {
                    lower=heights[i];
                    break;
                }
        }
    for(i=in+1;i<n;i++)
        {
            if(heights[i]!=num)
                {
                    upper=heights[i];
                    return;
                }
        }
}

void binary_search()
{
    int start,end,mid;

    start=0;
    end=n-1;
    while(!(start>end))
        {
            mid=(start+end)/2;
            if(heights[mid]==num)
                {
                    lower_upper(mid);
                    return;
                }
            else if(heights[mid]>num) end=mid-1;
            else start=mid+1;
        }
    upper=heights[start];
    if(end>-1) lower=heights[end];
    else lower=-1;
}

int main()
{
    int q,i,j;

    while(scanf("%d",&n)!=EOF)
        {
            for(i=0;i<n;i++)
                {
                    scanf("%d",&heights[i]);
                }
            scanf("%d",&q);
            for(i=0;i<q;i++)
                {
                    scanf("%d",&queries[i]);
                }
            for(i=0;i<q;i++)
                {
                    num=queries[i];
                    lower=upper=-1;
                    binary_search();
                    if(lower!=-1 && lower!=0) printf("%d ",lower);
                    else printf("X ");
                    if(upper!=-1 && upper!=0) printf("%d\n",upper);
                    else printf("X\n");
                }
        }
    return 0;
}
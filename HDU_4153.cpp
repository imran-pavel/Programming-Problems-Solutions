#include <stdio.h>
#include <string.h>

int main()
{
    int n,w,i,j,ar[150],k,v,max,last,color,l;
	double total_consumption;
    while(1)
        {
            scanf("%d %d",&n,&w);
            if(n==0 && w==0) break;
            memset(ar,0,sizeof(ar));
            last=max=color=0;
            for(i=1;i<=n;i++)
                {
					scanf("%d",&v);
					for(j=0,k=w-1;;j=j+w,k=k+w)
					{
						if(v>=j && v<=k)
						{
							//if(ar[j]==0) color++;
							ar[j]++;
							//printf("%d %d %d\n",j,ar[j],color);
							if(ar[j]>max) max=ar[j];
							if(j>last) last=j;
							break;
						}
					}
                }
            //printf("max: %d  last: %d\n",max,last);
			color=(0+last+w)/w;
			//printf("%d\n",color);
			--color;
			l=color;
			//printf("Colored bar numbers: %d\n",color);
			for(total_consumption=j=0;j<=last;j=j+w,l--)
			{
				if(ar[j]!=0)
				{
					//printf("%d %d",j,ar[j]);
					//printf("Color: %.lf  Height: %.lf\n",((1.0*l)/color),(1.0*ar[j])/max);
					total_consumption=total_consumption+(((1.0*l)/color)*((1.0*ar[j])/max));
					//l--;
				}
			}
			total_consumption=total_consumption+.01;
			printf("%.6lf\n",total_consumption);
        }
    return 0;
}

#include <stdio.h>

int main()
{
	int n,i,max,num,j,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(j=1;j<=x;j++)
		{
			scanf("%d",&num);
			if(j==1) max=num;
			else
			{
				if(num>max) max=num;
			}
		}
		printf("Case %d: %d\n",i,max);
	}
	return 0;
}
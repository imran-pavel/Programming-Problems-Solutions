#include <stdio.h>

int main()
{
	long long int x,check,i,total;
	while(scanf("%lld",&x)!=EOF)
	{
		if(x>-1) check=0;
		else
		{
			x=x*(-1);
			check=1;
		}
		total=0;
		for(i=2;i<=x;i++)
		{
			total=total+i;
		}
		if(check==0) total++;
		else
		{
			total=total*(-1);
		}
		printf("%lld\n",total);
	}
	return 0;
}
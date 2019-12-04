#include <stdio.h>
#include <string.h>

int main()
{
	long long int n,i,length,j,c,k,length_for_check;
	char line[100000],fau[2],indexes[100000];
	scanf("%lld",&n);
	gets(fau);
	for(i=1;i<=n;i++)
	{
		gets(line);
		c=0;
		k=-1;
		length=strlen(line);
		length_for_check=length;
		for(j=0;j<length;j++)
		{
			if(j==0)
			{

				if(line[j]==')' || line[j]==']')
					{
						c++;
						break;
					}
				else
				{
					k++;
					indexes[k]=line[j];
				}
			}
			else
			{
				if(line[j]=='(' || line[j]=='[')
				{
					k++;
					indexes[k]=line[j];
				}
				else
				{
					if(line[j]==')')
					{
						if(indexes[k]!='(')
						{
							c++;
							break;
						}
						else
						{
							if(length_for_check>-1)
							{
								length_for_check=length_for_check-2;
								k--;
							}
							else
							{
								c++;
								break;
							}
						}
					}
					else if(line[j]==']')
					{
						if(indexes[k]!='[')
						{
							c++;
							break;
						}
						else
						{
							if(length_for_check>-1)
							{
								length_for_check=length_for_check-2;
								k--;
							}
							else
							{
								c++;
								break;
							}
						}
					}
				}
			}
		}
		if(length_for_check!=0) c++;
		if(c==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

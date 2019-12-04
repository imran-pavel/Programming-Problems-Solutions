#include<stdio.h>
#include<string.h>
int summ(int n)
{
	int sum;
 if(n%9!=0)
	 sum=n%9;
 else
	 sum=9;
 return sum;
}
int main()
{
	char name1[26],name2[26];
   int i,sum1,sum2,len1,len2;
   	
   float result;
	while(gets(name1))
	{
		result=0;
		gets(name2);
		len1=strlen(name1);
		len2=strlen(name2);
		sum1=0,sum2=0;
		for(i=0;i<len1;i++)
		{
			if(name1[i]>='a' && name1[i]<='z')
			{
				sum1=sum1+name1[i]-'a'+1;
			}
			else if (name1[i]>='A' && name1[i]<='Z')
			{
				sum1=sum1+name1[i]-'A'+1;
			}
		}
		
		for(i=0;i<len2;i++)
		{
			if(name2[i]>='a' && name2[i]<='z')
			{
				sum2=sum2+name2[i]-'a'+1;
			}
			else if (name2[i]>='A' && name2[i]<='Z')
			{
				sum2=sum2+name2[i]-'A'+1;
			}
		}
		if(sum1>9)
		{
			sum1=summ(sum1);
		}
		else
		{
			sum1=sum1;
		}
		if(sum2>9){
		   sum2=summ(sum2);
		}
	   else
	   {
		   sum2=sum2;
	   }
	   
	   if(sum1>sum2)
	   {
				result=(((float)(sum2))/((float)(sum1))*100.00);
				printf("%.2f %%\n",result);

	   }
	   else
	   {
				result=(((float)(sum1))/((float)(sum2))*100.00);
				printf("%.2f %%\n",result);
	   }
		
	}
	return 0;
}
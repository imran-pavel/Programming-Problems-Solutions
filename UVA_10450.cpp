#include <stdio.h>
int main()
{ long long int n[300]={0};
n[1]=2;
n[2]=3;
int t,d,j;
for(j=3;j<=200;j++)
n[j]=n[j-2]+n[j-1];
scanf("%d",&t);
d=0;

while(t--)
{
d++;
int k,i;
scanf("%d",&i);
printf("Scenario #%d:\n%lld\n\n",d,n[i]);

}
return 0;
}

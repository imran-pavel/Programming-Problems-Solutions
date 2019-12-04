#include <stdio.h>
#include <string.h>

int main()
{
    char line1[100000],line2[100000];
    int length1,length2,i,j,k;

    while(scanf("%s",line1)!=EOF)
        {
            scanf("%s",line2);
            length1=strlen(line1);
            length2=strlen(line2);
            if(length2<length1) printf("No\n");
            else
                {
                    j=0;
                    k=0;
                    for(i=0;i<length2;i++)
                        {
                            if(line2[i]==line1[j])
                                {
                                    j++;
                                    if(j==length1)
                                        {
                                            printf("Yes\n");
                                            k++;
                                            break;
                                        }
                                }
                        }
                    if(k==0) printf("No\n");
                }
        }
    return 0;
}

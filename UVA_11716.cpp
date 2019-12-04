#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int n,i,length,sr_length,j,k,l;
    char fau[1];
    scanf("%d",&n);
    gets(fau);
    char line[10001];
    for(i=1;i<=n;i++)
        {
            gets(line);
            length=strlen(line);
            sr_length=sqrt(length);
            if(!((sr_length*sr_length)==length))
                {
                    printf("INVALID\n");
                }
            else
                {
                    l=0;
                    char decrypted_text[sr_length][sr_length];
                    for(j=0;j<sr_length;j++)
                        {
                            for(k=0;k<sr_length;k++,l++)
                                {
                                    decrypted_text[j][k]=line[l];
                                }
                        }
                    for(j=0;j<sr_length;j++)
                        {
                            for(k=0;k<sr_length;k++)
                                {
                                    printf("%c",decrypted_text[k][j]);
                                }
                        }
                    printf("\n");
                }
        }
    return 0;
}

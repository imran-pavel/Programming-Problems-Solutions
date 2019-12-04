#include <stdio.h>
#include <string.h>

int n_line,i,n_case;

struct inputs{
    char line[501];
}strings[50];

void print()
{
    int k,check,j;

    for(k=0;k<n_line;k++)
        {
            check=j=0;
            while(strings[k].line[j])
                {
                    if(strings[k].line[j]==' ')
                        {
                            if(check==0)
                                {
                                    printf("%c",strings[k].line[j]);
                                    check=1;
                                }
                        }
                    else
                        {
                            printf("%c",strings[k].line[j]);
                            check=0;
                        }
                    j++;
                }
            printf("\n");
        }
    if(i!=n_case) printf("\n");
}

int main()
{
    int j;
    char fau[2];

    scanf("%d",&n_case);
    for(i=1;i<=n_case;i++)
        {
            scanf("%d",&n_line);
            gets(fau);
            for(j=0;j<n_line;j++)
                {
                    gets(strings[j].line);
                }
            printf("Case %d:\n",i);
            print();
        }
    return 0;
}

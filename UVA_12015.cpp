#include <stdio.h>
#include <string.h>

struct url_n_relevance{
    char url[102];
    int relevance;
};

int main()
{
    int n,i,j,max_relevance,k=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
            struct url_n_relevance sites[11];
            int max_relevance_site_indexes[11];
            memset(max_relevance_site_indexes,0,sizeof(max_relevance_site_indexes));
            for(j=1;j<=10;j++)
                {
                    scanf("%s %d",sites[j-1].url,&sites[j-1].relevance);
                    if(j==1)
                        {
                            max_relevance=sites[j-1].relevance;
                            max_relevance_site_indexes[k]=j-1;
                        }
                    else
                        {
                            if(sites[j-1].relevance==max_relevance)
                                {
                                    k++;
                                    max_relevance_site_indexes[k]=j-1;
                                }
                            else if(sites[j-1].relevance>max_relevance)
                                {
                                    memset(max_relevance_site_indexes,0,sizeof(max_relevance_site_indexes));
                                    max_relevance=sites[j-1].relevance;
                                    k=0;
                                    max_relevance_site_indexes[k]=j-1;
                                }
                        }
                }
            printf("Case #%d:\n",i);
            for(j=0;j<=k;j++)
                {
                    printf("%s\n",sites[max_relevance_site_indexes[j]].url);
                }
        }
    return 0;
}

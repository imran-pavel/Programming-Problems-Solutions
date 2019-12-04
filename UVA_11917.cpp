#include <stdio.h>
#include <string.h>

struct subjects{
    char subj_name[25];
    int completion_time;
};

int main()
{
    int n,n_of_case,day_limit,l,i,j;
    char due_subject[25];
    scanf("%d",&n);
    for(j=1;j<=n;j++)
        {
            l=0;
            scanf("%d",&n_of_case);
            struct subjects inputs[n_of_case];
            for(i=0;i<n_of_case;i++)
                {
                    scanf("%s",inputs[i].subj_name);
                    scanf("%d",&inputs[i].completion_time);
                }
            scanf("%d",&day_limit);
            scanf("%s",due_subject);
            for(i=0;i<n_of_case;i++)
                {
                    if(strcmp(inputs[i].subj_name,due_subject)==0)
                        {
                            if(inputs[i].completion_time<=day_limit)
                                {
                                    printf("Case %d: Yesss\n",j);
                                    l++;
                                    break;
                                }
                            else if(inputs[i].completion_time<=(day_limit+5))
                                {
                                    printf("Case %d: Late\n",j);
                                    l++;
                                    break;
                                }
                            else break;
                        }
                }
            if(l==0) printf("Case %d: Do your own homework!\n",j);
        }
    return 0;
}

#include <stdio.h>
#include <string.h>

int main()
{
    char ar[50];
    int i=1;
    while(i)
        {
            scanf("%s",ar);
            if(strcmp(ar,"Hajj")==0) printf("Case %d: Hajj-e-Akbar\n",i);
            else if(strcmp(ar,"Umrah")==0) printf("Case %d: Hajj-e-Asghar\n",i);
            else break;
            i++;
        }
    return 0;
}

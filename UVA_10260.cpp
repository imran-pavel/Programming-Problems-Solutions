#include <stdio.h>
#include <string.h>

int soundex_number(char ch)
{
    switch(ch)
        {
            case 'B':
            case 'F':
            case 'P':
            case 'V':
            return 1;

            case 'C':
            case 'G':
            case 'J':
            case 'K':
            case 'Q':
            case 'S':
            case 'X':
            case 'Z':
            return 2;

            case 'D':
            case 'T':
            return 3;

            case 'L':
            return 4;

            case 'M':
            case 'N':
            return 5;

            case 'R':
            return 6;
        }
}


int main()
{
    int check,i,length,soundex_code[100000],j,result;
    char line[100000];

    while(gets(line))
        {
            length=strlen(line);
            j=-1;
            check=0;
            for(i=0;i<length;i++)
                {
                    if(line[i]!='A' && line[i]!='I' && line[i]!='E' && line[i]!='O' && line[i]!='U' && line[i]!='H' && line[i]!='W' && line[i]!='Y')
                        {
                            result=soundex_number(line[i]);
                            if(i==0)
                                {
                                    j++;
                                    soundex_code[i]=result;
                                    check=1;
                                }
                            else
                                {
                                    if(result==soundex_code[j])
                                        {
                                            if(check==0)
                                                {
                                                    j++;
                                                    soundex_code[j]=result;
                                                    check=1;
                                                }
                                        }
                                    else
                                        {
                                            j++;
                                            soundex_code[j]=result;
                                            check=1;
                                        }
                                }
                        }
                    else check=0;
                }
            for(i=0;i<=j;i++)
                {
                    printf("%d",soundex_code[i]);
                }
            printf("\n");
        }
    return 0;
}

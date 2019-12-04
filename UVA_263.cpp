#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstdio>

using namespace std;
int digits[9],len,results[1000];

void take_digits(int num)
{
    int i;

    for(i=1;;i++)
        {
           digits[i-1]=num%10;
           num=num/10;
           if(num==0)
            {
                len=i;
                return;
            }
        }
}

int larger_number()
{
    int i,x;

    for(x=i=0;i<len;i++)
        {
            x=x+(digits[i]*pow(10,i));
        }
    return x;
}

int smaller_number()
{
    int i,x,j;

    for(j=x=0,i=len-1;i>-1;i--,j++)
        {
            x=x+(digits[i]*pow(10,j));
        }
    return x;
}

int main()
{
    long long int num,chain,l,s,k,check;
    string a;
    stringstream temp;

    for(;;)
        {
            cin>>num;
            if(num==0) break;
            cout<<"Original number was "<<num<<'\n';
            for(check=k=0,chain=1;;chain++,k++)
                {
                    take_digits(num);
                    sort(digits,digits+len);
                    l=larger_number();
                    s=smaller_number();
                    num=l-s;
                    if(k==0) results[k]=num;
                    else
                        {
                            for(k=0;k<chain-1;k++)
                                {
                                    if(num==results[k])
                                        {
                                            check++;
                                            break;
                                        }
                                }
                            if(check==0) results[k]=num;
                        }
                    cout<<l<<' '<<'-'<<' '<<s<<' '<<'='<<' '<<num<<'\n';
                    if(check)
                        {
                            cout<<"Chain length "<<chain<<"\n\n";
                            break;
                        }
                }
        }
    return 0;
}

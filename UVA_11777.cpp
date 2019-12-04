#include <iostream>

using namespace std;

int largest(int a, int b, int c)
{
    if(a>=b)
        {
            if(b>c) return a+b;
            return a+c;
        }
    else if(a<b)
        {
            if(a>c) return a+b;
            return b+c;
        }
}

int main()
{
    int n,i,temp,a,b,c,j;
    double sum;

    cin>>n;
    for(j=1;j<=n;j++)
        {
            sum=0;
            for(i=1;i<=4;i++)
                {
                    cin>>temp;
                    sum=temp+sum;
                }
            cin>>a>>b>>c;
            //cout<<sum<<endl;
            sum=sum+((double)largest(a,b,c)/2);
            //cout<<sum;
            if(sum>=90) cout<<"Case "<<j<<": A\n";
            else if(sum>=80 && sum<90) cout<<"Case "<<j<<": B\n";
            else if(sum>=70 && sum<80) cout<<"Case "<<j<<": C\n";
            else if(sum>=60 && sum<70) cout<<"Case "<<j<<": D\n";
            else  cout<<"Case "<<j<<": F\n";
        }
    return 0;
}

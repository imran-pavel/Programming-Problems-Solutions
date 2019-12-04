#include <iostream>

using namespace std;

int n,ar[99][99],check,a,b;

void change_bit(int x, int y, int bit)
{
    //cout<<"Changing Here "<<x<<' '<<y<<"THIS "<<bit<<'\n';
    if(bit==1) ar[x][y]=0;
    else ar[x][y]=1;
}

int count1_r_c(int r, int c)
{
    int i,c1,c2;

    for(c2=c1=i=0;i<n;i++)
        {
            if(ar[r][i]) c1++;
            if(ar[i][c]) c2++;
        }
    //cout<<"\n\n\n\n"<<"Sum of row after bit changed: "<<c1<<"\n";
    //cout<<"Sum of column after bit changed: "<<c2<<'\n';
    if(c1%2!=0 || c2%2!=0) return 0;
    return 1;
}


int bit_change_row(int r)
{
    int i;

    for(i=0;i<n;i++)
        {
            //cout<<"Before bit changed at "<<r<<' '<<i<<" "<<ar[r][i]<<'\n';
            change_bit(r,i,ar[r][i]);
           // cout<<"After bit changed at "<<r<<' '<<i<<" "<<ar[r][i]<<'\n';
            if(count1_r_c(r,i))
                {
                    check++;
                    a=r;
                    b=i;
                    return 1;
                }
            change_bit(r,i,ar[r][i]);
        }
    return 0;
}

int bit_change_column(int c)
{
    int i;

    for(i=0;i<n;i++)
        {
            change_bit(i,c,ar[i][c]);
            if(count1_r_c(i,c))
                {
                    check++;
                    a=i;
                    b=c;
                    return 1;
                }
            change_bit(i,c,ar[i][c]);
        }
    return 0;
}

int main()
{
    int i,j,count_r_1,count_c_1,x;

    while(1)
        {
            cin>>n;
            if(n==0) break;
            for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                        {
                            cin>>ar[i][j];
                        }
                }
            for(x=check=i=0;i<n;i++)
                {
                    for(count_c_1=count_r_1=j=0;j<n;j++)
                        {
                            if(ar[i][j]==1) count_r_1++;
                            if(ar[j][i]==1) count_c_1++;
                        }
                    //cout<<"Row: "<<i<<" Total 1s: "<<count_r_1<<'\n';
                   // cout<<"Column: "<<i<<" Total 1s: "<<count_c_1<<'\n';
                    if(count_r_1%2!=0)
                        {
                            if(check==0)
                                {
                                    if(!(bit_change_row(i)))
                                        {
                                            //cout<<bit_change_row(i)<<'\n';
                                            cout<<"Corrupt\n";
                                            x++;
                                            break;
                                        }
                                }
                            else
                                {
                                    cout<<"Corrupt\n";
                                    x++;
                                    break;
                                }
                        }
                    else if(count_c_1%2!=0)
                        {
                            if(check==0)
                                {
                                    if(!(bit_change_column(i)))
                                        {
                                            cout<<"Corrupt\n";
                                            x++;
                                            break;
                                        }
                                }
                            else
                                {
                                    cout<<"Corrupt\n";
                                    x++;
                                    break;
                                }
                        }
                }
            if(x==0 && check==0) cout<<"OK\n";
            else if(x==0 && check!=0) cout<<"Change bit ("<<a+1<<','<<b+1<<")\n";
        }
    return 0;
}

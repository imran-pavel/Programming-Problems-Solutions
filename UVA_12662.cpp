#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define li long int

using namespace std;

void print_left_right(string left_or_right, li n)
{
    li i;

    for(i=1;i<=n;i++)
    {
        cout<<left_or_right<<" of ";
    }
}


int main()
{
    li i,n_names,n_query,position,j,n;
    string student_names[101],left_right;
    vector<int>name_position;

    cin>>n_names;
    for(i=0;i<n_names;i++)
    {
        cin>>student_names[i];
        if(student_names[i]!="?")
        {
            name_position.push_back(i);
        }
    }
    cin>>n_query;
    for(i=0;i<n_query;i++)
    {
        cin>>position;
        position--;
        if(student_names[position]!="?")
        {
            cout<<student_names[position]<<"\n";
        }
        else
        {
            j=0;
            li prev=-1,next=name_position[j];

            while(position>=next)
            {
                if(j+1>=name_position.size())
                {
                    prev=next;
                    next=-1;
                    break;
                }
                prev=next;
                j++;
                next=name_position[j];
            }
            if(prev!=-1 && next!=-1)
            {
                if(position-prev==next-position)
                {
                    cout<<"middle of "<<student_names[prev]<<" and "<<student_names[next]<<"\n";
                }
                else if(position-prev<next-position)
                {
                    n=position-prev;
                    left_right="right";
                    print_left_right(left_right,n);
                    cout<<student_names[prev]<<"\n";
                }
                else
                {
                    n=next-position;
                    left_right="left";
                    print_left_right(left_right,n);
                    cout<<student_names[next]<<"\n";
                }
            }
            else
            {
                if(prev==-1)
                {
                    n=next-position;
                    left_right="left";
                    print_left_right(left_right,n);
                    cout<<student_names[next]<<"\n";
                }
                else
                {
                    n=position-prev;
                    left_right="right";
                    print_left_right(left_right,n);
                    cout<<student_names[prev]<<"\n";
                }
            }
        }
    }
    return 0;
}

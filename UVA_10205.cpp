#include <cstdio>
#include <iostream>
#include <cstring>
#define lli long long int

using namespace std;

lli shuffles[5201],deck[53],temp_deck[53],shuffle_id;

void get_shuffle_id(char s_id[])
{
    lli i,s_len;

    shuffle_id=0;
    s_len=strlen(s_id);
    for(i=0;i<s_len;i++)
    {
        shuffle_id=shuffle_id*10+s_id[i]-'0';
    }
}

void make_deck()
{
    lli i;

    for(i=1;i<53;i++)
    {
        deck[i]=i;
    }
}

void copy_deck()
{
    lli i;

    for(i=1;i<=52;i++)
    {
        temp_deck[i]=deck[i];
    }
}


void shuffle_deck(lli u_limit, lli l_limit)
{
    lli i,j,in;

    for(j=l_limit;j<=u_limit;j++)
    {
        i=shuffles[j];
        in=j%52;
        in==0 ? in=52: in=in;
        deck[in]=temp_deck[i];
    }
}

void print_deck()
{
    string clubs="of Clubs\n",diamonds="of Diamonds\n";
    string hearts="of Hearts\n",spades="of Spades\n";
    string ace="Ace ",king="King ",queen="Queen ",jack="Jack ";
    string o_string;
    lli value;

    lli i;

    for(i=1;i<=52;i++)
    {
        if(deck[i]<=13) o_string=clubs;
        else if(deck[i]>13 && deck[i]<=26) o_string=diamonds;
        else if(deck[i]>26 && deck[i]<=39) o_string=hearts;
        else if(deck[i]>39 && deck[i]<=52) o_string=spades;
        value=deck[i]%13+1;
        if(value==1)
            {
                cout<<ace<<o_string;
            }
        else if(value==0)
            {
                cout<<king<<o_string;
            }
        else if(value>10)
            {
                switch(value)
                {
                    case 11:
                    cout<<jack<<o_string;
                    break;

                    case 12:
                    cout<<queen<<o_string;
                    break;

                    case 13:
                    cout<<king<<o_string;
                    break;
                }
            }
        else
            {
                cout<<value<<" "<<o_string;
            }
    }
}

int main()
{
    lli n_case,n_shuffles,lim,i,u_limit,l_limit;
    char s_id[5],fau[2];

    cin>>n_case;
    while(n_case)
    {
        make_deck();
        cin>>n_shuffles;
        lim=52*n_shuffles;
        for(i=1;i<=lim;i++)
        {
            cin>>shuffles[i];
        }
        gets(fau);
        while(gets(s_id))
        {
            if(s_id[0]=='\n' || s_id[0]=='\0') break;
            get_shuffle_id(s_id);
            u_limit=shuffle_id*52;
            l_limit=u_limit-52+1;
            copy_deck();
            shuffle_deck(u_limit,l_limit);
        }
        print_deck();
        --n_case;
        if(n_case) printf("\n");
    }
    return 0;
}

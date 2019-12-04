#include <stdio.h>

int InputTimeLeft, Constant, NTreasures, Depths[30], Values[30], Cost1Storage[30][1001];
int NTakenTreasures, TakenTreasures[30], Cost2Storage[30][1001], Storage[30][1001];
int IsFirst;

void Reset()
{
    int i, j;

    NTakenTreasures = 0;
    for(i=0; i<30; i++)
    {
        for(j=0; j<1001; j++)
        {
            Storage[i][j] = -1;
        }
    }
}


void GetTakenIndexes(int NthTreasure, int TimeLeft)
{
    if( NthTreasure >= NTreasures || TimeLeft < 1 )
    {
        return;
    }

    if( Cost1Storage[NthTreasure][TimeLeft] > Cost2Storage[NthTreasure][TimeLeft] )
    {
        TakenTreasures[NTakenTreasures] = NthTreasure;
        NTakenTreasures++;
        GetTakenIndexes(NthTreasure+1, TimeLeft-(3*Constant*Depths[NthTreasure]));
    }
    else
    {
        GetTakenIndexes(NthTreasure+1, TimeLeft);
    }
}


void PrintTakenIndexes()
{
    int i;

    printf("%d\n", NTakenTreasures);
    for(i=0; i<NTakenTreasures; i++)
    {
        printf("%d %d\n", Depths[TakenTreasures[i]], Values[TakenTreasures[i]]);
    }
}


int DP(int NthTreasure, int TimeLeft)
{
    if(NthTreasure>=NTreasures || TimeLeft<1)
    {
        return 0;
    }

    if(Storage[NthTreasure][TimeLeft]!=-1)
    {
        return Storage[NthTreasure][TimeLeft];
    }

    int Cost1, Cost2;

    Cost1 = Cost2 = 0;

    if( TimeLeft-(3*Constant*Depths[NthTreasure]) > -1 )
    {
        Cost1 = DP(NthTreasure+1, (TimeLeft-(3*Constant*Depths[NthTreasure])) ) + Values[NthTreasure];
    }
    Cost2 = DP(NthTreasure+1, TimeLeft);

    Cost1Storage[NthTreasure][TimeLeft] = Cost1;
    Cost2Storage[NthTreasure][TimeLeft] = Cost2;

    if(Cost1>Cost2)
    {
        Storage[NthTreasure][TimeLeft] = Cost1;
    }
    else
    {
        Storage[NthTreasure][TimeLeft] = Cost2;
    }

    return Storage[NthTreasure][TimeLeft];
}



int main()
{
    int i;

    IsFirst = 1;
    while(scanf("%d %d", &InputTimeLeft, &Constant)==2)
    {
        scanf("%d",&NTreasures);
        for(i=0; i<NTreasures; i++)
        {
            scanf("%d %d", &Depths[i], &Values[i]);
        }

        if(IsFirst)
        {
            IsFirst = 0;
        }
        else
        {
            printf("\n");
        }
        Reset();
        printf("%d\n", DP(0, InputTimeLeft));
        GetTakenIndexes(0, InputTimeLeft);
        PrintTakenIndexes();
    }
    return 0;
}

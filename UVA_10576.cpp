#include <stdio.h>

int Max, MonthFlags[9], FiveMonthReports[9];
int InputSurplus, InputDeficit;


int CheckValidity(int NMonths)
{
    int i;

    for(i=1; i<=NMonths; i++)
    {
        if(MonthFlags[i]==5 && FiveMonthReports[i]>0)
        {
            return 0;
        }
    }

    return 1;
}


int CheckForValidity(int NthMonthFlag)
{
    if(NthMonthFlag > 8)
    {
        return CheckValidity(8);
    }
    return CheckValidity(NthMonthFlag-1);
}


void StoreCurrentData(int *StoredMonthFlags, int *StoredFiveMonthReports)
{
    int i;

    for(i=0; i<9; i++)
    {
        StoredMonthFlags[i] = MonthFlags[i];
        StoredFiveMonthReports[i] = FiveMonthReports[i];
    }
}



void RestoreCurrentData(int *StoredMonthFlags, int *StoredFiveMonthReports)
{
    int i;

    for(i=0; i<9; i++)
    {
        MonthFlags[i] = StoredMonthFlags[i];
        FiveMonthReports[i] = StoredFiveMonthReports[i];
    }
}




void UpdateCurrentData(int NthMonthFlag, int CurrentSorD)
{
    int i;

    for(i=1; i<=NthMonthFlag; i++)
    {
        if( i < 9 && MonthFlags[i] < 5)
        {
            FiveMonthReports[i] += CurrentSorD;
            MonthFlags[i]++;
        }
    }
}




void BruteForce(int NthMonthFlag, int CurrentTotal)
{
    if(!CheckForValidity(NthMonthFlag))
    {
        return;
    }

    if(NthMonthFlag >= 13)
    {
        if( Max < CurrentTotal )
        {
            Max = CurrentTotal;
        }
        return;
    }



    int StoredMonthFlags[9], StoredFiveMonthReports[9];


    StoreCurrentData(StoredMonthFlags, StoredFiveMonthReports);


    UpdateCurrentData(NthMonthFlag, InputSurplus);
    BruteForce(NthMonthFlag+1, CurrentTotal+InputSurplus);


    RestoreCurrentData(StoredMonthFlags, StoredFiveMonthReports);

    UpdateCurrentData(NthMonthFlag, -InputDeficit);
    BruteForce(NthMonthFlag+1, CurrentTotal-InputDeficit);

    RestoreCurrentData(StoredMonthFlags, StoredFiveMonthReports);
}




int main()
{
    while(scanf("%d %d", &InputSurplus, &InputDeficit) == 2)
    {
        Max = -1;
        BruteForce(1, 0);
        if(Max > 0)
        {
            printf("%d\n", Max);
        }
        else
        {
            printf("Deficit\n");
        }
    }
}

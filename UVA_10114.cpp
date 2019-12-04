#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int i, NthMonthSelected, NthMonth[101];
    double NMonths, FirstPayment, RemainingLoan, NDepreciationRecords, CarValue, MonthlyPay;
    double DepreciationRecords[100];

    while(cin >> NMonths >> FirstPayment >> RemainingLoan >> NDepreciationRecords)
    {
        if(NMonths < 0)
        {
            break;
        }
        for(i=0; i<NDepreciationRecords; i++)
        {
            cin >> NthMonth[i] >> DepreciationRecords[i];
        }
        NthMonth[i] = 101;
        CarValue = FirstPayment + RemainingLoan;
        CarValue = ( CarValue * (1.0-DepreciationRecords[0]));
        MonthlyPay = RemainingLoan / NMonths;
        for(i=0, NthMonthSelected=1; CarValue <= RemainingLoan && i < NMonths; i++ )
        {
            if(i+1 < NthMonth[NthMonthSelected])
            {
                CarValue = ( CarValue * (1.0-DepreciationRecords[NthMonthSelected-1]));
            }
            else
            {
                CarValue = ( CarValue * (1.0-DepreciationRecords[NthMonthSelected]));
                NthMonthSelected++;
            }
            RemainingLoan -= MonthlyPay;
        }
        if(i == 1)
        {
            cout << i << " month\n";
        }
        else
        {
            cout << i << " months\n";
        }
    }

    return 0;
}

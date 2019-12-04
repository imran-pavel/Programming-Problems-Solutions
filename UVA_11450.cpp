#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#define MaxAmount 201
#define MaxNDifferentClothItems 21

using namespace std;


int TotalBudget, NDifferentClothItems, Storage[MaxAmount][MaxNDifferentClothItems];

int DP(int AmountNeededToMake, int NthClothElementIndex, int NDifferentClothItems, vector<vector<int>> & DifferentClothesPrices)
{
	if (AmountNeededToMake < 0)
	{
		return -1;
	}
	if (NthClothElementIndex == NDifferentClothItems)
	{
		return (TotalBudget - AmountNeededToMake);
	}
	if (Storage[AmountNeededToMake][NthClothElementIndex] != -1)
	{
		return Storage[AmountNeededToMake][NthClothElementIndex];
	}

	int i, Max;

	for (i = 0, Max = -1; i < DifferentClothesPrices[NthClothElementIndex].size(); i++)
	{
		Max = max(Max, DP(AmountNeededToMake-DifferentClothesPrices[NthClothElementIndex][i], NthClothElementIndex+1, NDifferentClothItems, DifferentClothesPrices));
	}

	Storage[AmountNeededToMake][NthClothElementIndex] = Max;
	return Storage[AmountNeededToMake][NthClothElementIndex];
}



int main()
{
	int i, j, NCases, NPrices, ClothPrice, Result;
	
	cin >> NCases;
	while (NCases--)
	{
		cin >> TotalBudget >> NDifferentClothItems;
		vector<vector<int>> DifferentClothesPrices(NDifferentClothItems);

		for (i = 0; i<DifferentClothesPrices.size(); i++)
		{
			cin >> NPrices;
			for (j = 0; j<NPrices; j++)
			{
				cin >> ClothPrice;
				DifferentClothesPrices[i].push_back(ClothPrice);
			}
		}

		memset(Storage, -1, sizeof(Storage));
		Result = DP(TotalBudget, 0, NDifferentClothItems, DifferentClothesPrices);
		if (Result == -1)
		{
			cout << "no solution\n";
		}
		else
		{
			cout << Result << "\n";
		}
	}
	return 0;
}
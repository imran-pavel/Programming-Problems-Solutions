#include <cstdio>
#include <string>
#include <iostream>
#include <map>

using namespace std;
typedef long long int i64;


int CountCommonCds(bool CheckCounter, i64 NCds, map < string, i64 > &CommonCds)
{
	i64 i, Output;
	string CdCatalogNumber;

	for (Output = i = 0; i < NCds; i++)
	{
		cin >> CdCatalogNumber;
		CommonCds[CdCatalogNumber]++;
		if (CheckCounter)
		{
			if (CommonCds[CdCatalogNumber] > 1)
			{
				Output++;
			}
		}
	}

	return Output;
}


int main()
{
	i64 i, NJackCds, NJillCds;

	while (cin >> NJackCds >> NJillCds && NJackCds && NJillCds)
	{
		map < string, i64 > CommonCds;

		CountCommonCds(false, NJackCds, CommonCds);
		cout << CountCommonCds(true, NJillCds, CommonCds) << "\n";
	}
	return 0;
}
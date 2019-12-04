#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int i64;


i64 NCases, NSpots, SpotList[20];


i64 CalculateWalkingDistance()
{
	i64 i, TotalDistance;

	TotalDistance = 0;
	for (i = 0; i < NSpots-1; i++)
	{
		TotalDistance += (SpotList[i + 1] - SpotList[i]);
	}
	TotalDistance += (SpotList[NSpots - 1] - SpotList[0]);

	return TotalDistance;
}



int main()
{
	i64 i, j;

	cin >> NCases; 
	for (i = 0; i < NCases; i++)
	{
		cin >> NSpots;
		for (j = 0; j < NSpots; j++)
		{
			cin >> SpotList[j];
		}
		sort(SpotList, SpotList + NSpots);
		cout << CalculateWalkingDistance() << "\n";
	}
	return 0;
}
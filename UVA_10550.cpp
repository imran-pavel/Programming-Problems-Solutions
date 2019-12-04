#include <cstdio>
#include <iostream>

using namespace std;
typedef long long int i64;


i64 StartPosition, C1, C2, C3, TotalNDegrees;


int main()
{
	while (cin >> StartPosition >> C1 >> C2 >> C3 && (StartPosition || C1 || C2 || C3))
	{
		if (StartPosition == C1 && C1 == C2 && C2 == C3)
		{
			cout << 1080 << "\n";
			continue;
		}
		TotalNDegrees = 80;
		if (StartPosition > C1)
		{
			TotalNDegrees += (StartPosition - C1);
		}
		else
		{
			TotalNDegrees += (40 - (C1 - StartPosition));
		}
		TotalNDegrees += 40;
		if (C2 > C1)
		{
			TotalNDegrees += (C2 - C1);
		}
		else
		{
			TotalNDegrees += (40 - (C1 - C2));
		}
		if (C2 > C3)
		{
			TotalNDegrees += (C2 - C3);
		}
		else
		{
			TotalNDegrees += (40 - (C3 - C2));
		}
		cout << TotalNDegrees * 9 << "\n";
	}
	return 0;
}
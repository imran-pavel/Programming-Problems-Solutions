#include <cstdio>
#include <iostream>
#include <map>

using namespace std;


int main()
{
	int position, inputNumber;
	map < int, int > frequencyCounter, positionMarker, taken;
	map < int, int > ::iterator loopVariable;

	position = 0;
	while (cin >> inputNumber)
	{
		frequencyCounter[inputNumber]++;
		if (taken[inputNumber] == 0)
		{
			position++;
			positionMarker[position] = inputNumber;
			taken[inputNumber] = 1;
		}
	}

	for (loopVariable = positionMarker.begin(); loopVariable != positionMarker.end(); loopVariable++)
	{
		cout << positionMarker[loopVariable->first] << " " << frequencyCounter[positionMarker[loopVariable->first]] << "\n";
	}

	return 0;
}
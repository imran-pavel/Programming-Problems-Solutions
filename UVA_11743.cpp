#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int getSum(string &creditCardNumber)
{
	int i, total, doubledValue;

	for (i = total = 0; i < creditCardNumber.length(); i++)
	{
		if (i % 2 == 0)
		{
			doubledValue = (creditCardNumber[i] - '0') * 2;
			if (doubledValue > 9)
			{
				doubledValue -= 9; // https://en.wikipedia.org/wiki/Luhn_algorithm
			}
			total += doubledValue;
		}
		else
		{
			total += (creditCardNumber[i] - '0');
		}
	}

	return total;
}


int main()
{
	int nCases;
	string creditCardNumber, creditCardNumberP1, creditCardNumberP2, creditCardNumberP3, creditCardNumberP4;

	cin >> nCases;
	cin.ignore();
	while (nCases--)
	{
		cin >> creditCardNumberP1 >> creditCardNumberP2 >> creditCardNumberP3 >> creditCardNumberP4;
		creditCardNumber = creditCardNumberP1 + creditCardNumberP2 + creditCardNumberP3 + creditCardNumberP4;
		if (getSum(creditCardNumber) % 10 == 0)
		{
			cout << "Valid\n";
		}
		else
		{
			cout << "Invalid\n";
		}
	}
	return 0;
}
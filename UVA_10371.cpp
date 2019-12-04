#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;


struct Time
{
	int hour, minute;
};


void SaveTimeZoneDifferences(map < string, struct Time> &timeZoneDifferences)
{
	Time temp;

	temp.hour = 0;
	temp.minute = 0;
	
	timeZoneDifferences["UTC"] = timeZoneDifferences["GMT"] = timeZoneDifferences["WET"] = temp;

	temp.hour = 1;
	temp.minute = 0;
	timeZoneDifferences["BST"] = timeZoneDifferences["IST"] = timeZoneDifferences["WEST"] = timeZoneDifferences["CET"] = temp;
	
	temp.hour = 2;
	timeZoneDifferences["CEST"] = timeZoneDifferences["EET"] = temp;

	temp.hour = 3;
	timeZoneDifferences["EEST"] = timeZoneDifferences["MSK"] = temp;

	temp.hour = 4;
	timeZoneDifferences["MSD"] = temp;

	temp.hour = -4;
	timeZoneDifferences["AST"] = timeZoneDifferences["EDT"] = temp;

	temp.hour = -3;
	timeZoneDifferences["ADT"] = temp;

	temp.minute = -30;
	timeZoneDifferences["NST"] = temp;

	temp.hour = -2;
	timeZoneDifferences["NDT"] = temp;

	temp.hour = -5;
	temp.minute = 0;
	timeZoneDifferences["EST"] = timeZoneDifferences["CDT"] = temp;

	temp.hour = -6;
	timeZoneDifferences["CST"] = timeZoneDifferences["MDT"] = temp;

	temp.hour = -7;
	timeZoneDifferences["MST"] = timeZoneDifferences["PDT"] = temp;

	temp.hour = -8;
	timeZoneDifferences["PST"] = timeZoneDifferences["AKDT"] = temp;

	temp.hour = -10;
	timeZoneDifferences["HST"] = temp;

	temp.hour = -9;
	timeZoneDifferences["AKST"] = temp;

	temp.hour = 10;
	timeZoneDifferences["AEST"] = temp;

	temp.hour = 11;
	timeZoneDifferences["AEDT"] = temp;

	temp.hour = 9;
	temp.minute = 30;
	timeZoneDifferences["ACST"] = temp;

	temp.hour = 10;
	timeZoneDifferences["ACDT"] = temp;

	temp.hour = 8;
	temp.minute = 0;
	timeZoneDifferences["AWST"] = temp;
}


Time tokenizeTime(string givenTime)
{
	Time tokenizedTime;
	stringstream stringStream1, stringStream2, stringStream3;
	string sHour, sMinute, temp;

	stringStream1.str(givenTime);
	getline(stringStream1, sHour, ':');
	getline(stringStream1, sMinute, ':');

	stringStream2.str(sHour);
	stringStream3.str(sMinute);
	stringStream2 >> tokenizedTime.hour;
	stringStream3 >> tokenizedTime.minute;

	return tokenizedTime;
}



void tokenizeInputLine(string inputLine, string &givenTime, string &amOrPm, string &fromTimeZone, string &toTimeZone)
{
	int delimiterPosition, previousDelimiterPosition;

	delimiterPosition = inputLine.find_first_of(" \n", 0);
	givenTime = inputLine.substr(0, delimiterPosition - 0);
	previousDelimiterPosition = delimiterPosition;

	if (givenTime != "noon" && givenTime != "midnight")
	{
		delimiterPosition = inputLine.find_first_of(" \n", previousDelimiterPosition + 1);
		amOrPm = inputLine.substr(previousDelimiterPosition + 1, delimiterPosition - (previousDelimiterPosition + 1));
		previousDelimiterPosition = delimiterPosition;
	}

	delimiterPosition = inputLine.find_first_of(" \n", previousDelimiterPosition + 1);
	fromTimeZone = inputLine.substr(previousDelimiterPosition + 1, delimiterPosition - (previousDelimiterPosition + 1));
	previousDelimiterPosition = delimiterPosition;

	delimiterPosition = inputLine.find_first_of(" \n", previousDelimiterPosition + 1);
	toTimeZone = inputLine.substr(previousDelimiterPosition + 1, delimiterPosition - (previousDelimiterPosition + 1));
}


Time changeTimeTo24HourFormat(Time &currentTime, string noonOrMidnight, string amOrPm)
{
	if (noonOrMidnight == "")
	{
		if (amOrPm == "a.m." && currentTime.hour == 12)
		{
			currentTime.hour = 0;
		}
		else if (amOrPm == "p.m." && currentTime.hour >= 1 && currentTime.hour <= 11)
		{
			currentTime.hour += 12;
		}
	}
	else
	{
		if (noonOrMidnight == "noon")
		{
			currentTime.hour = 12;
			currentTime.minute = 0;
		}
		else
		{
			currentTime.hour = 0;
			currentTime.minute = 0;
		}
	}
	return currentTime;
}



Time changeTime(Time &currentTime, Time timeChanges, int multiplier)
{
	currentTime.minute += (timeChanges.minute * multiplier);
	if (currentTime.minute >= 60)
	{
		currentTime.minute %= 60;
		currentTime.hour++;
	}
	else if (currentTime.minute < 0)
	{
		currentTime.minute += 60;
		currentTime.hour--;
	}

	currentTime.hour += (timeChanges.hour * multiplier);
	if (currentTime.hour >= 24)
	{
		currentTime.hour %= 24;
	}
	else if (currentTime.hour < 0)
	{
		currentTime.hour += 24;
	}

	return currentTime;
}






int main()
{
	int nCases;
	string inputString, givenTime, fromTimeZone, toTimeZone, ampmString;
	map < string, struct Time> newMap;
	Time currentTime;

	SaveTimeZoneDifferences(newMap);
	cin >> nCases;
	cin.ignore();
	while (nCases--)
	{
		getline(cin, inputString);
		tokenizeInputLine(inputString, givenTime, ampmString, fromTimeZone, toTimeZone);
		if (givenTime == "noon" || givenTime == "midnight")
		{
			changeTimeTo24HourFormat(currentTime, givenTime, "");
		}
		else
		{
			currentTime = tokenizeTime(givenTime);
			currentTime = changeTimeTo24HourFormat(currentTime, "", ampmString);
		}
		currentTime = changeTime(currentTime, newMap[fromTimeZone], -1);
		if (toTimeZone != "UTC" && toTimeZone != "GMT")
		{
			currentTime = changeTime(currentTime, newMap[toTimeZone], 1);
		}
		if (currentTime.hour == 0 && currentTime.minute == 0)
		{
			cout << "midnight\n";
		}
		else if (currentTime.hour == 12 && currentTime.minute == 0)
		{
			cout << "noon\n";
		}
		else
		{
			if (currentTime.hour >= 0 && currentTime.hour < 12)
			{
				ampmString = "a.m.";
			}
			else
			{
				ampmString = "p.m.";
			}
			currentTime.hour %= 12;
			if (currentTime.hour == 0)
			{
				currentTime.hour = 12;
			}
			cout << currentTime.hour << ":";
			if (currentTime.minute < 10)
			{
				cout << "0";
			}
			cout << currentTime.minute << " " << ampmString << "\n";
		}
	}


	return 0;
}
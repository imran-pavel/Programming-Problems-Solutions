#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

typedef long long int i64;

stringstream StringStream;


i64 LastReached;
bool ReturnedFromLeaf;


i64 ConvertToNumber(string Number)
{
    i64 i, TensPower, ConvertedNumber = 0, NegativeSign = 1, StartIndex = 0;

    if( Number[StartIndex] == '-' )
    {
        NegativeSign = -NegativeSign;
        StartIndex++;
    }
    for(i=Number.length()-1, TensPower=0; i>=StartIndex; i--, TensPower++)
    {
        ConvertedNumber = ConvertedNumber + ( (Number[i]-'0') * ((i64)pow(10, TensPower)) );
    }

    ConvertedNumber *= NegativeSign;

    //cout << "StartIndex: " << StartIndex << "  EndIndex: " << EndIndex << " " << ConvertedNumber << endl;
    return ConvertedNumber;
}


int SumTree( i64 Sum, i64 Index, vector < char > & Input,  map < i64, i64 > & Number, map < i64, i64 > & NextPositionAfterNumber, map < string, i64 > & Output )
{
    if( Input[Index+1] == ')' )
    {
        LastReached = Index+1;
        ReturnedFromLeaf = 1;
        return Sum;
    }

    i64  Child1Sum, Child2Sum, NumberOfLeafChilds = 0;

    Child1Sum = SumTree((Sum+Number[Index+1]), NextPositionAfterNumber[Index+1], Input, Number, NextPositionAfterNumber, Output);
    if(ReturnedFromLeaf)
    {
        NumberOfLeafChilds++;
    }
    ReturnedFromLeaf = 0;
    Child2Sum = SumTree((Sum+Number[Index+1]), LastReached+1, Input, Number, NextPositionAfterNumber, Output);
    if(ReturnedFromLeaf)
    {
        NumberOfLeafChilds++;
    }
    if( Child1Sum == Child2Sum && NumberOfLeafChilds == 2 )
    {
        StringStream.str(string());
        StringStream << Child1Sum;
        //cout << "Child1Sum: " << Child1Sum << endl;
        Output[StringStream.str()] = 1;
    }

    LastReached++;
    ReturnedFromLeaf = 0;
}

i64 GetN(string InputTree, string & N)
{
    i64 NumberStarted, StartIndex, n, i;
    string Value = "";

    for(i=NumberStarted=0; i<InputTree.length(); i++)
    {
        if( ( InputTree[i]=='-' || ( InputTree[i]>='0' && InputTree[i]<='9')) )
        {
            NumberStarted = 1;
            Value = Value + InputTree[i];
        }
        else
        {
            if( NumberStarted && !( InputTree[i]>='0' && InputTree[i]<='9') )
            {
                n = ConvertToNumber(Value);
                StringStream.str(string());
                StringStream << n;
                N = StringStream.str();
                return i;
            }
        }
    }
    n = ConvertToNumber(Value);
    StringStream.str(string());
    StringStream << n;
    N = StringStream.str();
    return i;
}

/*
void PrintMap( map < i64, i64 > & MappedNumbers )
{
    std::map<i64,i64>::iterator IT;

    for(IT = MappedNumbers.begin(); IT!=MappedNumbers.end(); IT++)
    {
        cout << IT->first << " " << IT->second <<  endl;
    }
}

*/



int main()
{
    i64 ValueI, i, NumberStartIndex, NumberStarted, NumberMapIndex, ParenthesisTaken;
    string InputTree, N, Value;
    bool ReadLine;

    while ( getline( cin, InputTree ) )
    {
        if( InputTree.empty() || InputTree.find_first_not_of(' ') == string::npos )
        {
            continue;
        }
        stack < char > ParenthesisStack;
        vector < char > Input;
        map < i64, i64 > Number, NextPositionAfterNumber;
        map < string, i64 > Output;

        Value = N = "";
        i = GetN(InputTree, N);
        ReadLine = false;
        ParenthesisTaken = NumberStarted = 0;
        do
        {
            if( ReadLine )
            {
                getline( cin, InputTree );
                i = 0;
            }
            for(; i<InputTree.length(); i++)
            {
                if( InputTree[i] == '-' )
                {
                    Input.push_back(InputTree[i]);
                    Value = Value + InputTree[i];
                    if( !NumberStarted )
                    {
                        NumberMapIndex = Input.size()-1;
                        NumberStartIndex = i;
                        NumberStarted = 1;
                        continue;
                    }
                }
                else if( InputTree[i] >= '0' && InputTree[i] <= '9' )
                {
                    Input.push_back(InputTree[i]);
                    Value = Value + InputTree[i];
                    if( !NumberStarted )
                    {
                        NumberMapIndex = Input.size()-1;
                        NumberStartIndex = i;
                        NumberStarted = 1;
                    }
                }
                else if( InputTree[i] == '(' )
                {
                    if( NumberStarted )
                    {
                        Number[NumberMapIndex] = ConvertToNumber(Value);
                        NextPositionAfterNumber[NumberMapIndex] = Input.size();
                        NumberStarted = 0;
                        Value = "";
                    }
                    Input.push_back(InputTree[i]);
                    ParenthesisStack.push(InputTree[i]);
                    ParenthesisTaken = 1;
                }
                else if ( InputTree[i] == ')' )
                {
                    Input.push_back(InputTree[i]);
                    ParenthesisStack.pop();
                }
                else
                {
                    /*if( NumberStarted )
                    {
                        Number[NumberMapIndex] = ConvertToNumber(NumberStartIndex, i-1, InputTree);
                        NextPositionAfterNumber[NumberMapIndex] = Input.size();
                        NumberStarted = 0;
                    }*/
                }
            }
            ReadLine = true;
        }while( !ParenthesisStack.empty() || !ParenthesisTaken );

        /*cout << "Output: " << Input.size() << " ";
        for(i=0; i<Input.size(); i++)
        {
            cout << Input[i];
        }
        cout << endl;

        PrintMap(Number);*/

        SumTree( 0, 0, Input, Number, NextPositionAfterNumber, Output );
        //cout << "N: " << N << endl;
        if( Output[N] )
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}

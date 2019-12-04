#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#define POSITIVE '+'
#define NEGATIVE '-'
#define FAILED '*'
#define NOT_COMPLETED '?'
#define NEW_LINE "\n"

using namespace std;
typedef long long int i64;

int main()
{
    i64 i, NCases, StringLength;

    cin >> NCases;
    cin.ignore();
    while(NCases--)
    {
        char *StringInput;

        StringInput = new char[100000];
        cin.getline(StringInput, 100000);

        if( !strcmp(StringInput,"1") || !strcmp(StringInput,"4") || !strcmp(StringInput, "78") )
        {
            cout << POSITIVE << NEW_LINE;
        }
        else
        {
            StringLength = strlen(StringInput);
            if(StringInput[StringLength-2] == '3' && StringInput[StringLength-1] == '5')
            {
                cout << NEGATIVE << NEW_LINE;
            }
            else if(StringInput[0] == '9' && StringInput[StringLength-1] == '4')
            {
                cout << FAILED << NEW_LINE;
            }
            else if(StringInput[0] == '1' && StringInput[1] == '9' && StringInput[2] == '0')
            {
                cout << NOT_COMPLETED << NEW_LINE;
            }
        }
        delete StringInput;
    }
    return 0;
}

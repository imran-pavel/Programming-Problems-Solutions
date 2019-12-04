#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;


typedef long long int i64;



int main()
{
    i64 i;
    string Word, Hold;
    vector < string > Ananagrams;
    map < string, i64 > FrequencyCount;
    map < string, string > RealInputWord;
    map < string, i64 > :: iterator It;


    while( cin >> Word )
    {
        if( Word.compare("#") == 0 )
        {
            break;
        }
        Hold = Word;
        transform(Word.begin(), Word.end(), Word.begin(), ::tolower);
        sort(Word.begin(),Word.end());
        FrequencyCount[Word]++;
        RealInputWord[Word] = Hold;
    }

    for(It = FrequencyCount.begin(); It != FrequencyCount.end(); ++It)
    {
        if( It->second == 1 )
        {
            Ananagrams.push_back(RealInputWord[It->first]);
        }
    }

    sort(Ananagrams.begin(), Ananagrams.end());

    for(i=0; i<Ananagrams.size(); i++)
    {
        cout << Ananagrams[i] << "\n";
    }

    return 0;
}

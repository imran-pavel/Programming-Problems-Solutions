#include <cstdio>

#include <map>

#include <vector>

#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long int i64;


bool NoBiggerLetterTaken( char CurrentLetter, vector < string > & UpdatedBiggerLettersList, map < char, i64 > & Taken )
{
    i64 i;

    for(i=0; i<UpdatedBiggerLettersList[CurrentLetter].size(); i++)
    {
        if( Taken[UpdatedBiggerLettersList[CurrentLetter][i]] )
        {
            return false;
        }
    }
    return true;
}



void BackTrack( string Output, vector < char > & Letters, map < char, i64 > & Taken, vector < string > & UpdatedBiggerLettersList )

{
    if( Output.length() == Letters.size() )

    {
        cout << Output << "\n";
        return;
    }

    i64 i;

    for(i=0; i<Letters.size(); i++)
    {
        if( !Taken[Letters[i]] )
        {
            if( !NoBiggerLetterTaken(Letters[i], UpdatedBiggerLettersList, Taken) )
            {
                return;
            }
            Taken[Letters[i]] = 1;
            Output = Output + Letters[i];
            BackTrack(Output, Letters, Taken, UpdatedBiggerLettersList);
            Output.erase(Output.begin()+Output.length()-1);
            Taken[Letters[i]] = 0;
        }
    }
}



string UpdateList(char Letter, vector < vector < char > > & InitialConstraintsList, vector < string > & UpdatedBiggerLettersList, map < char, i64 > & Updated)
{
    i64 i;
    string BiggerList = "";

    for(i=0; i<InitialConstraintsList[Letter].size(); i++)
    {
        if( Updated[InitialConstraintsList[Letter][i]] )
        {
            BiggerList = BiggerList + InitialConstraintsList[Letter][i] + UpdatedBiggerLettersList[InitialConstraintsList[Letter][i]];
            continue;
        }
        UpdatedBiggerLettersList[InitialConstraintsList[Letter][i]] = UpdateList(InitialConstraintsList[Letter][i], InitialConstraintsList, UpdatedBiggerLettersList, Updated);
        Updated[InitialConstraintsList[Letter][i]] = 1;
        BiggerList = BiggerList + InitialConstraintsList[Letter][i] + UpdatedBiggerLettersList[InitialConstraintsList[Letter][i]];
    }

    return BiggerList;
}


void UpdateBiggerLettersList( vector < char > & Letters, vector < vector < char > > & InitialConstraintsList, vector < string > & UpdatedBiggerLettersList)
{

    i64 i;
    map < char, i64 > Updated;

    for(i=0; i<Letters.size(); i++)
    {
        if( !Updated[Letters[i]] )

        {
            UpdatedBiggerLettersList[Letters[i]] = UpdateList(Letters[i], InitialConstraintsList, UpdatedBiggerLettersList, Updated);
            Updated[Letters[i]] = 1;
        }
    }
}




int main()
{
    stringstream StringStream;
    string InputLetters, Constraints;
    char Letter;
    i64 i, LetterIndex;
    bool PrintNewLine = false;

    while( getline( cin, InputLetters ) )
    {
        vector < vector < char > > InitialConstraintsList(123);
        vector < string > UpdatedBiggerLettersList(123);
        vector < char > Letters;
        map < char, i64 > Taken;

        getline( cin, Constraints );
        StringStream.clear();
        StringStream.str(InputLetters);
        if( PrintNewLine )
        {
            cout << "\n";
        }
        while( StringStream >> Letter )
        {
            Letters.push_back(Letter);
        }
        i = 0;
        StringStream.clear();
        StringStream.str(Constraints);
        while( StringStream >> Letter )
        {
            if( ++i % 2 )
            {
                LetterIndex = Letter;
                continue;
            }
            InitialConstraintsList[LetterIndex].push_back(Letter);
            i = 0;
        }
        UpdateBiggerLettersList(Letters, InitialConstraintsList, UpdatedBiggerLettersList);
        sort( Letters.begin(), Letters.end() );
        BackTrack("", Letters, Taken, UpdatedBiggerLettersList);
        PrintNewLine = true;
    }
    return 0;

}

#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

typedef long long int lli;


lli NRows, NColumns;
lli CalculatedLengths[51][51];
char Grid[51][51];

struct Position
{
    lli X, Y;
};


void FindAs( vector < struct Position > & APositions )
{
    lli i, j;
    struct Position NewPosition;

    for(i=0; i<NRows; i++)
    {
        for(j=0; j<NColumns; j++)
        {
            if(Grid[i][j] == 'A')
            {
                NewPosition.X = i;
                NewPosition.Y = j;
                APositions.push_back(NewPosition);
            }
        }
    }
}


lli DFS( Position CurrentPosition, char TargetCharacter )
{
    if( CalculatedLengths[CurrentPosition.X][CurrentPosition.Y] != -1 )
    {
        return CalculatedLengths[CurrentPosition.X][CurrentPosition.Y];
    }
    if( Grid[CurrentPosition.X][CurrentPosition.Y] == 'Z' )
    {
        CalculatedLengths[CurrentPosition.X][CurrentPosition.Y] = 26;
        return CalculatedLengths[CurrentPosition.X][CurrentPosition.Y];
    }

    struct Position NewPosition;
    vector < struct Position > TargetCharacterPositions;
    lli i, Length, MaxLength = -1;


    if( CurrentPosition.Y+1 < NColumns )
    {
        if( Grid[CurrentPosition.X][CurrentPosition.Y+1] == TargetCharacter )
        {
            NewPosition.X = CurrentPosition.X;
            NewPosition.Y = CurrentPosition.Y+1;
            TargetCharacterPositions.push_back(NewPosition);
        }
    }

    if( CurrentPosition.X-1 >= 0 && CurrentPosition.Y+1 < NColumns )
    {
        if( Grid[CurrentPosition.X-1][CurrentPosition.Y+1] == TargetCharacter )
        {
            NewPosition.X = CurrentPosition.X-1;
            NewPosition.Y = CurrentPosition.Y+1;
            TargetCharacterPositions.push_back(NewPosition);
        }
    }

    if( CurrentPosition.X-1 >= 0 )
    {
        if( Grid[CurrentPosition.X-1][CurrentPosition.Y] == TargetCharacter )
        {
            NewPosition.X = CurrentPosition.X-1;
            NewPosition.Y = CurrentPosition.Y;
            TargetCharacterPositions.push_back(NewPosition);
        }
    }

    if( CurrentPosition.X-1 >= 0 && CurrentPosition.Y-1 >= 0 )
    {
        if( Grid[CurrentPosition.X-1][CurrentPosition.Y-1] == TargetCharacter )
        {
            NewPosition.X = CurrentPosition.X-1;
            NewPosition.Y = CurrentPosition.Y-1;
            TargetCharacterPositions.push_back(NewPosition);
        }
    }

    if( CurrentPosition.Y-1 >= 0 )
    {
        if( Grid[CurrentPosition.X][CurrentPosition.Y-1] == TargetCharacter )
        {
            NewPosition.X = CurrentPosition.X;
            NewPosition.Y = CurrentPosition.Y-1;
            TargetCharacterPositions.push_back(NewPosition);
        }
    }

    if( CurrentPosition.X+1 < NRows && CurrentPosition.Y-1 >= 0 )
    {
        if( Grid[CurrentPosition.X+1][CurrentPosition.Y-1] == TargetCharacter )
        {
            NewPosition.X = CurrentPosition.X+1;
            NewPosition.Y = CurrentPosition.Y-1;
            TargetCharacterPositions.push_back(NewPosition);
        }
    }

    if( CurrentPosition.X+1 < NRows )
    {
        if( Grid[CurrentPosition.X+1][CurrentPosition.Y] == TargetCharacter )
        {
            NewPosition.X = CurrentPosition.X+1;
            NewPosition.Y = CurrentPosition.Y;
            TargetCharacterPositions.push_back(NewPosition);
        }
    }

    if( CurrentPosition.X+1 < NRows && CurrentPosition.Y+1 < NColumns )
    {
        if( Grid[CurrentPosition.X+1][CurrentPosition.Y+1] == TargetCharacter )
        {
            NewPosition.X = CurrentPosition.X+1;
            NewPosition.Y = CurrentPosition.Y+1;
            TargetCharacterPositions.push_back(NewPosition);
        }
    }


    if( TargetCharacterPositions.size() == 0 )
    {
        return ( TargetCharacter-'A');
    }


    for(i=0; i<TargetCharacterPositions.size(); i++)
    {
        Length = DFS( TargetCharacterPositions[i], TargetCharacter+1 );
        if( Length > MaxLength )
        {
            MaxLength = Length;
        }
    }

    CalculatedLengths[CurrentPosition.X][CurrentPosition.Y] = MaxLength;
    return CalculatedLengths[CurrentPosition.X][CurrentPosition.Y];
}



int main()
{
    lli i, NThCase, Length, MaxLength;

    NThCase = 0;
    while( cin >> NRows >> NColumns )
    {
        if( NRows == 0 && NColumns == 0 )
        {
            break;
        }

        NThCase++;
        MaxLength = -1;
        memset(CalculatedLengths, -1, sizeof(CalculatedLengths));
        cin.ignore();
        for(i=0; i<NRows; i++)
        {
            cin.getline(Grid[i],NColumns+1);
        }

        vector < struct Position > APositions;

        FindAs(APositions);
        if(APositions.size() == 0)
        {
            cout << "Case " << NThCase << ": 0\n";
            continue;
        }

        for(i=0; i<APositions.size(); i++)
        {
            Length = DFS(APositions[i], 'B');
            if( Length > MaxLength )
            {
                MaxLength = Length;
            }
        }

        cout << "Case " << NThCase << ": " << MaxLength << "\n";
    }
    return 0;
}

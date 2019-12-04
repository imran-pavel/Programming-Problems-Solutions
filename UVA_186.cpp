#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <sstream>
#include <climits>
#include <iomanip>

using namespace std;

typedef long long int i64;


i64 WeightMatrix[100][100], PathMatrix[100][100];


void InitializeWeightMatrix( i64 Size )
{
    i64 i;

    for(i=0; i<Size; i++)
    {
        fill( &WeightMatrix[i][0], &WeightMatrix[i][0]+Size, INT_MAX);
    }
}

vector < string > Tokenize( char Segment[] )
{
    char *Token;
    vector < string > Tokens;

    Token = strtok(Segment, ",");
    while( Token!=NULL )
    {
        Tokens.push_back(Token);
        Token = strtok(NULL, ",");
    }

    return Tokens;
}


void FloydWarshall( i64 Size, map < string, i64 > & StringToInteger, map < i64, string > & IntegerToString )
{
    i64 From, To, IntermediateNode;

    for( IntermediateNode = 1; IntermediateNode <= Size; IntermediateNode++ )
    {
        for( From = 1; From <= Size; From++ )
        {
            for( To = 1; To <= Size; To++ )
            {
                if( WeightMatrix[From][To] > WeightMatrix[From][IntermediateNode] + WeightMatrix[IntermediateNode][To] )
                {
                    WeightMatrix[From][To] = WeightMatrix[From][IntermediateNode] + WeightMatrix[IntermediateNode][To];
                    PathMatrix[From][To] = PathMatrix[IntermediateNode][To];
                }
            }
        }
    }
}


void GetPathCities( i64 SourceCity, i64 DestinationCity, vector < i64 > & PathCities )
{
    if( !PathMatrix[SourceCity][DestinationCity] )
    {
        PathCities.clear();
    }
    else if( PathMatrix[SourceCity][DestinationCity] == SourceCity )
    {
        PathCities.push_back(SourceCity);
    }
    else
    {
        GetPathCities(SourceCity, PathMatrix[SourceCity][DestinationCity], PathCities);
        GetPathCities(PathMatrix[SourceCity][DestinationCity], DestinationCity, PathCities);
    }
}


int main()
{
    char Segment[75];
    i64 Distance, MappedIndex, i, j, Total;
    map < i64, map < i64, string > > RouteName;
    map < i64, map < i64, i64 > > Cost;
    map < string, i64 > Taken, StringToInteger;
    map < i64, string > IntegerToString;
    map < i64, map < i64, i64 > > :: iterator It1;
    map < i64, i64 > :: iterator It2;

    MappedIndex = 0;
    while( cin.getline(Segment,75) && Segment[0]!= 0 )
    {
        vector < string > SegmentTokens;

        SegmentTokens = Tokenize(Segment);
        if( !Taken[SegmentTokens[0]] )
        {
            MappedIndex++;
            StringToInteger[SegmentTokens[0]] = MappedIndex;
            IntegerToString[MappedIndex] = SegmentTokens[0];
            Taken[SegmentTokens[0]] = 1;
        }
        if( !Taken[SegmentTokens[1]] )
        {
            MappedIndex++;
            StringToInteger[SegmentTokens[1]] = MappedIndex;
            IntegerToString[MappedIndex] = SegmentTokens[1];
            Taken[SegmentTokens[1]] = 1;
        }

        stringstream StringStream;

        StringStream << SegmentTokens[3];
        StringStream >> Distance;
        if( Cost[StringToInteger[SegmentTokens[0]]][StringToInteger[SegmentTokens[1]]] )
        {
            if( Cost[StringToInteger[SegmentTokens[0]]][StringToInteger[SegmentTokens[1]]] > Distance )
            {
                Cost[StringToInteger[SegmentTokens[0]]][StringToInteger[SegmentTokens[1]]] = Distance;
                Cost[StringToInteger[SegmentTokens[1]]][StringToInteger[SegmentTokens[0]]] = Distance;
                RouteName[StringToInteger[SegmentTokens[0]]][StringToInteger[SegmentTokens[1]]] = SegmentTokens[2];
                RouteName[StringToInteger[SegmentTokens[1]]][StringToInteger[SegmentTokens[0]]] = SegmentTokens[2];
            }
        }
        else
        {
            Cost[StringToInteger[SegmentTokens[0]]][StringToInteger[SegmentTokens[1]]] = Distance;
            Cost[StringToInteger[SegmentTokens[1]]][StringToInteger[SegmentTokens[0]]] = Distance;
            RouteName[StringToInteger[SegmentTokens[0]]][StringToInteger[SegmentTokens[1]]] = SegmentTokens[2];
            RouteName[StringToInteger[SegmentTokens[1]]][StringToInteger[SegmentTokens[0]]] = SegmentTokens[2];
        }
    }

    InitializeWeightMatrix(MappedIndex+1);

    for( It1 = Cost.begin(); It1 != Cost.end(); It1++ )
    {
        for( It2 = Cost[It1->first].begin(); It2 != Cost[It1->first].end(); It2++ )
        {
            WeightMatrix[It1->first][It2->first] = It2->second;
            WeightMatrix[It2->first][It1->first] = It2->second;
            PathMatrix[It1->first][It2->first] = It1->first;
            PathMatrix[It2->first][It1->first] = It2->first;

            WeightMatrix[It1->first][It1->first] = 0;
            WeightMatrix[It2->first][It2->first] = 0;
            PathMatrix[It1->first][It1->first] = It1->first;
            PathMatrix[It2->first][It2->first] = It2->first;
        }
    }

    FloydWarshall(MappedIndex, StringToInteger, IntegerToString);

    while( cin.getline(Segment,75) )
    {
        vector < string > SegmentTokens;
        vector < i64 > PathCities;
        Total = 0;

        SegmentTokens = Tokenize(Segment);
        GetPathCities( StringToInteger[SegmentTokens[0]], StringToInteger[SegmentTokens[1]], PathCities );
        PathCities.push_back(StringToInteger[SegmentTokens[1]]);

        cout << "\n\n";
        cout << setw(20) << left << "From" << " " << setw(20) << left << "To" << " " << setw(10) << left << "Route" << " " << setw(5) << left << "Miles\n";
        cout << "-------------------- -------------------- ---------- -----\n";
        for(i=0; i<PathCities.size()-1; i++)
        {
            cout << setw(20) << left << IntegerToString[PathCities[i]] << " " << setw(20) << left << IntegerToString[PathCities[i+1]] << " " << setw(10) << left << RouteName[PathCities[i]][PathCities[i+1]] << " " << setw(5) << right << WeightMatrix[PathCities[i]][PathCities[i+1]] << "\n";
            Total += WeightMatrix[PathCities[i]][PathCities[i+1]];
        }
        cout << "                                                     -----\n";
        cout << "                                          Total      " << setw(5) << right << Total << "\n";
    }

    return 0;
}

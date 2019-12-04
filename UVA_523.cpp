#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <algorithm>

using namespace std;


typedef long long int i64;

i64 WeightMatrix[10001][10001];
i64 PathMatrix[10001][10001];
i64 IntermediateCosts[10001];


void InitializeWeightMatrix( i64 Size )
{
    i64 i;

    for(i=0; i<Size; i++)
    {
        fill( &WeightMatrix[i][0], &WeightMatrix[i][0]+Size, INT_MAX);
    }
}

i64 GetIntegerNumber( string StringNumber )
{
    stringstream StringStream;
    i64 IntegerNumber;

    StringStream << StringNumber;
    StringStream >> IntegerNumber;

    return IntegerNumber;
}


vector < i64 > Tokenize( char DataSetFirstLine[] )
{
    int i, j;
    char *StringNumber;
    vector < i64 > IntegerNumbers;

    StringNumber = strtok(DataSetFirstLine, " ");
    if( StringNumber != NULL )
    {
        IntegerNumbers.push_back(GetIntegerNumber(StringNumber));
    }
    while(StringNumber != NULL)
    {
        StringNumber = strtok(NULL," ");
        if(StringNumber!=NULL)
        {
            IntegerNumbers.push_back(GetIntegerNumber(StringNumber));
        }
    }

    return IntegerNumbers;
}



void FloydWarshall( i64 Size )
{
    i64 U, V, IntermediateNode;

    for(IntermediateNode=0; IntermediateNode<Size; IntermediateNode++)
    {
        for(U=0; U<Size; U++)
        {
            for(V=0; V<Size; V++)
            {
                if( WeightMatrix[U][V] > ( WeightMatrix[U][IntermediateNode] + WeightMatrix[IntermediateNode][V] + IntermediateCosts[IntermediateNode] ) )
                {
                    WeightMatrix[U][V] = WeightMatrix[U][IntermediateNode] + WeightMatrix[IntermediateNode][V] + IntermediateCosts[IntermediateNode];
                    PathMatrix[U][V] = PathMatrix[IntermediateNode][V];
                }
            }
        }
    }
}






void PrintWeightMatrix( i64 Size )
{
    i64 i, j;

    for(i=0; i<Size; i++)
    {
        for(j=0; j<Size; j++)
        {
            cout << WeightMatrix[i][j] << " ";
        }
        cout << endl;
    }
}



void PrintPath( i64 Source, i64 Destination )
{
    if( PathMatrix[Source][Destination] == Source )
    {
        cout << PathMatrix[Source][Destination] + 1 << "-->";
        return;
    }
    else
    {
        PrintPath( Source, PathMatrix[Source][Destination] );
        PrintPath( PathMatrix[Source][Destination], Destination );
    }
}



int main()
{
    i64 i, j, NDataSets, Cost;
    char DataSetFirstLine[1000000], Query[1000000];
    vector < i64 > SourceNTarget;

    cin >> NDataSets;
    cin.ignore();

    while(NDataSets--)
    {
        vector < i64 > WeightMatrixFirstLine;

        while( cin.getline(DataSetFirstLine,1000000) && DataSetFirstLine[0] == 0 );
        WeightMatrixFirstLine = Tokenize(DataSetFirstLine);
        InitializeWeightMatrix(WeightMatrixFirstLine.size());

        for(i=1; i<WeightMatrixFirstLine.size(); i++)
        {
            for(j=0; j<WeightMatrixFirstLine.size(); j++)
            {
                cin >> Cost;
                if( Cost != -1 )
                {
                    WeightMatrix[i][j] = Cost;
                    PathMatrix[i][j] = i;
                }
            }
        }

        for(i=0; i<WeightMatrixFirstLine.size(); i++)
        {
            cin >> IntermediateCosts[i];
        }
        cin.ignore();

        for(i=0; i<WeightMatrixFirstLine.size(); i++)
        {
            if( WeightMatrixFirstLine[i] != - 1 )
            {
                WeightMatrix[0][i] =WeightMatrixFirstLine[i];
                PathMatrix[0][i] = 0;
            }
        }

        FloydWarshall(WeightMatrixFirstLine.size());
        while( cin.getline(Query, 1000000) && Query[0] != 0)
        {
            SourceNTarget = Tokenize(Query);
            cout << "From " << SourceNTarget[0] << " to " << SourceNTarget[1] << " :\n";
            cout << "Path: ";
            PrintPath(SourceNTarget[0]-1, SourceNTarget[1]-1);
            cout << SourceNTarget[1] << "\n";
            cout << "Total cost : " << WeightMatrix[SourceNTarget[0]-1][SourceNTarget[1]-1] << "\n";
        }
    }
    return 0;
}

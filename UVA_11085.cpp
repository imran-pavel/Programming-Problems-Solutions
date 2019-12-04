#include <stdio.h>


int MinMoveCount, InputQueenPostions[9], TempQueenPositions[9];


int AbsoluteValue(int Value)
{
    if(Value < 0)
    {
        return -Value;
    }
    return Value;
}


int IsSafeToPlace(int NthRow, int NthColumn)
{
    int i;

    for(i=1; i<NthColumn; i++)
    {
        if( TempQueenPositions[i] == NthRow || AbsoluteValue(NthColumn-i) == AbsoluteValue(TempQueenPositions[i]-NthRow))
        {
            return 0;
        }
    }

    return 1;
}



void PlaceQueen(int NthQueen, int TotalMoves)
{
    if(NthQueen >= 9)
    {
        if(TotalMoves < MinMoveCount)
        {
            MinMoveCount = TotalMoves;
        }
        return;
    }

    int i;

    for(i=1; i<=8; i++)
    {
        if(IsSafeToPlace(i, NthQueen))
        {
            TempQueenPositions[NthQueen] = i;
            if(i == InputQueenPostions[NthQueen])
            {
               PlaceQueen(NthQueen+1, TotalMoves);
            }
            else
            {
                PlaceQueen(NthQueen+1, TotalMoves+1);
            }
        }
    }

}






int main()
{
    int NthCase;

    NthCase = 0;
    while(scanf("%d %d %d %d %d %d %d %d", &InputQueenPostions[1], &InputQueenPostions[2], &InputQueenPostions[3], &InputQueenPostions[4], &InputQueenPostions[5], &InputQueenPostions[6], &InputQueenPostions[7], &InputQueenPostions[8]) == 8)
    {
        MinMoveCount = 10;
        PlaceQueen(1, 0);
        printf("Case %d: %d\n", ++NthCase, MinMoveCount);
    }
}

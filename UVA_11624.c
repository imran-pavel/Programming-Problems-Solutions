#include <stdio.h>
#define QSize 10000000
#define MazeSize 10000

int NCases, NRows, NColumns, JoeQTop, FireQTop, JoeQBottom, FireQBottom, JoeEscaped;
int JoeQX[QSize], JoeQY[QSize], FireQX[QSize], FireQY[QSize];
int JoeTime[MazeSize][MazeSize], FireTime[MazeSize][MazeSize];
char Decoy[2], Maze[MazeSize][MazeSize];


void Reset()
{
    JoeEscaped = JoeQTop = FireQTop = 0;
    JoeQBottom = FireQBottom = -1;

    int i, j;

    for(i=0; i<NRows; i++)
    {
        for(j=0; j<NColumns; j++)
        {
            JoeTime[i][j] = FireTime[i][j] = -1;
        }
    }
}


void FindInitialPositions()
{
    int i, j;

    for(i=0; i<NRows; i++)
    {
        for(j=0; j<NColumns; j++)
        {
            if(Maze[i][j] == 'F')
            {
                FireQBottom++;
                FireQX[FireQBottom] = i;
                FireQY[FireQBottom] = j;

                FireTime[i][j] = 0;
            }
            else if(Maze[i][j] == 'J')
            {
                JoeQBottom++;
                JoeQX[JoeQBottom] = i;
                JoeQY[JoeQBottom] = j;

                JoeTime[i][j] = 0;
            }
        }
    }
}



int IsPossibleToEscape(int X, int Y)
{
    if(Y+1 >= NColumns || X-1 < 0 || Y-1 < 0 || X+1 >= NRows)
    {
        return 1;
    }
    return 0;
}



int IsQEmpty(int QTop, int QBottom)
{
    if(QTop>QBottom)
    {
        return 1;
    }
    return 0;
}



void Fire_BFS()
{
    int UX, UY;

    while(!IsQEmpty(FireQTop, FireQBottom))
    {
        UX = FireQX[FireQTop];
        UY = FireQY[FireQTop];
        FireQTop++;

        if(UY+1 < NColumns && Maze[UX][UY+1] != '#' && (FireTime[UX][UY+1] == -1 || FireTime[UX][UY+1] > FireTime[UX][UY]+1))
        {
            FireTime[UX][UY+1] = FireTime[UX][UY]+1;
            FireQBottom++;
            FireQX[FireQBottom] = UX;
            FireQY[FireQBottom] = UY+1;
        }

        if(UX-1 >= 0 && Maze[UX-1][UY] != '#' && (FireTime[UX-1][UY] == -1 || FireTime[UX-1][UY] > FireTime[UX][UY]+1))
        {
            FireTime[UX-1][UY] = FireTime[UX][UY]+1;
            FireQBottom++;
            FireQX[FireQBottom] = UX-1;
            FireQY[FireQBottom] = UY;
        }

        if(UY-1 >= 0 && Maze[UX-1][UY] != '#' && (FireTime[UX][UY-1] == -1 || FireTime[UX][UY-1] > FireTime[UX][UY]+1))
        {
            FireTime[UX][UY-1] = FireTime[UX][UY] + 1;
            FireQBottom++;
            FireQX[FireQBottom] = UX;
            FireQY[FireQBottom] = UY-1;
        }

        if(UX+1 < NRows && Maze[UX+1][UY] != '#' && (FireTime[UX+1][UY] == -1 || FireTime[UX+1][UY] > FireTime[UX][UY]+1))
        {
            FireTime[UX+1][UY] = FireTime[UX][UY] + 1;
            FireQBottom++;
            FireQX[FireQBottom] = UX+1;
            FireQY[FireQBottom] = UY;
        }
    }
}




void Joe_BFS()
{
    int UX, UY;

    while(!IsQEmpty(JoeQTop, JoeQBottom))
    {
        UX = JoeQX[JoeQTop];
        UY = JoeQY[JoeQTop];
        if(IsPossibleToEscape(UX, UY))
        {
            JoeEscaped = 1;
            return;
        }
        JoeQTop++;

        if(UY+1 < NColumns && Maze[UX][UY+1] != '#' && JoeTime[UX][UY+1] == -1 && (FireTime[UX][UY+1] == -1 || FireTime[UX][UY+1] > JoeTime[UX][UY]+1))
        {
            JoeTime[UX][UY+1] = JoeTime[UX][UY] +1;
            JoeQBottom++;
            JoeQX[JoeQBottom] = UX;
            JoeQY[JoeQBottom] = UY+1;
        }

        if(UX-1 >= 0 && Maze[UX-1][UY] != '#' && JoeTime[UX-1][UY] == -1 && (FireTime[UX-1][UY] == -1 || FireTime[UX-1][UY] > JoeTime[UX][UY]+1))
        {
            JoeTime[UX-1][UY] = JoeTime[UX][UY]+1;
            JoeQBottom++;
            JoeQX[JoeQBottom] = UX-1;
            JoeQY[JoeQBottom] = UY;
        }

        if(UY-1 >= 0 && Maze[UX][UY-1] != '#' && JoeTime[UX][UY-1] == -1 && (FireTime[UX][UY-1] == -1 || FireTime[UX][UY-1] > JoeTime[UX][UY]+1))
        {
            JoeTime[UX][UY-1] = JoeTime[UX][UY] + 1;
            JoeQBottom++;
            JoeQX[JoeQBottom] = UX;
            JoeQY[JoeQBottom] = UY-1;
        }

        if(UX+1 < NRows && Maze[UX+1][UY] != '#' && JoeTime[UX+1][UY] == -1 && (FireTime[UX+1][UY] == -1 || FireTime[UX+1][UY] > JoeTime[UX][UY]+1))
        {
            JoeTime[UX+1][UY] = JoeTime[UX][UY] + 1;
            JoeQBottom++;
            JoeQX[JoeQBottom] = UX+1;
            JoeQY[JoeQBottom] = UY;
        }
    }
}





int main()
{
    int i, j;

    scanf("%d", &NCases);
    for(i=1; i<=NCases; i++)
    {
        scanf("%d %d", &NRows, &NColumns);
        gets(Decoy);
        for(j=0; j<NRows; j++)
        {
            gets(Maze[j]);
        }
        Reset();
        FindInitialPositions();
        Fire_BFS();
        Joe_BFS();
        if(JoeEscaped)
        {
            printf("%d\n", JoeTime[JoeQX[JoeQTop]][JoeQY[JoeQTop]]+1);
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}

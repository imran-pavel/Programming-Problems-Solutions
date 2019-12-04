#include <stdio.h>
#include <math.h>
#define Pi 3.141592653589793

double X1, Y1, X2, Y2, X3, Y3;
double LineALength, LineBLength, LineCLength;


double CalculateDistance(double X1, double Y1, double X2, double Y2)
{
    return sqrt( ((X1-X2)*(X1-X2)) + ((Y1-Y2)*(Y1-Y2)) );
}


int main()
{
    double Radius;

    while(scanf("%lf %lf %lf %lf %lf %lf", &X1, &Y1, &X2, &Y2, &X3, &Y3) == 6)
    {
        LineALength = CalculateDistance(X1, Y1, X2, Y2);
        LineBLength = CalculateDistance(X2, Y2, X3, Y3);
        LineCLength = CalculateDistance(X3, Y3, X1, Y1);

        /* The Following Line Is A Formula. If You Don't Know It Already Then Google "Circumcircle of a triangle" */
        Radius = (LineALength * LineBLength * LineCLength) / sqrt((LineALength+LineBLength+LineCLength) * (LineALength+LineBLength-LineCLength) * (LineALength+LineCLength-LineBLength) * (LineBLength+LineCLength-LineALength));
        printf("%.2lf\n", 2*Pi*Radius);
    }

    return 0;
}

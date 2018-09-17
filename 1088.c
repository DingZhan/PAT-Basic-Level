#include <stdio.h>

void PrintResult(int myScore, double otherScore)
{
    if(myScore>otherScore)
        printf("Gai");
    else if(myScore<otherScore)
        printf("Cong");
    else
        printf("Ping");
}

int main()
{
    int A, B, M, X, Y, D, bFind = 0;
    double C;
    scanf("%d%d%d", &M, &X, &Y);
    for(A=99; A>=10; --A)
    {
        B = A%10*10 + A/10;
        D = abs(A-B);
        C = (double)D/X;
        if(fabs(B-C*Y)<1.0e-6)
        {
            bFind = 1;
            break;
        }
    }
    if(bFind)
    {
        printf("%d ", A);
        PrintResult(M, A);
        printf(" ");
        PrintResult(M, B);
        printf(" ");
        PrintResult(M, C);
        printf("\n");
    }
    else
        printf("No Solution\n");

}

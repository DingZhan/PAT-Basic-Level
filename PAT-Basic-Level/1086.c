#include <stdio.h>


int main()
{
    int A, B, C, bFirstPrint=1;
    scanf("%d%d", &A, &B);
    C = A*B;
    while(C)
    {
        if(!(C%10==0&& bFirstPrint))
        {
            printf("%d", C%10);
            bFirstPrint = 0;
        }
        C = C/10;
    }
}
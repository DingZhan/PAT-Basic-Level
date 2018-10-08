#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10002
double laceLens[MAX_N];
int laceNum;
int Compare(const void *a, const void *b)
{
    double *aa = (double*)a;
    double *bb = (double*)b;
    if(*aa<*bb)
        return -1;
    else if(*aa>*bb)
        return 1;
    else
        return 0;
}
int main()
{
    int N, i, len;
    double lenD;
    scanf("%d", &N);
    laceNum = N;
    for(i=0; i<N; ++i)
    {
        scanf("%d", &len);
        laceLens[i] = len;
    }
    qsort(laceLens, laceNum, sizeof(double), Compare);

    for(i=0; i+1<laceNum; ++i)
    {
        lenD = (laceLens[i]+laceLens[i+1])*0.5;
        laceLens[i+1] = lenD;
    }
    printf("%d", (int)laceLens[laceNum-1]);
    return 0;
}

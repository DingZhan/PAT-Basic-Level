#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1001

typedef struct Pie_
{
    double amount;
    double price;
}Pie;

int Compare(const void* a, const void* b)
{
    Pie *aa=(Pie*)a;
    Pie *bb=(Pie*)b;
    double pa = aa->price/aa->amount;
    double pb = bb->price/bb->amount;
    if( pa < pb)
        return 1;
    else if(pa > pb)
        return -1;
    else
        return 0;
}

int  main()
{
    Pie pies[MAX_N];
    int N, D, i;
    double sumAmount = 0.0, sumPrice=0.0;
    scanf("%d%d", &N, &D);
    for(i=0; i<N; ++i)
        scanf("%lf", &(pies[i].amount));
    for(i=0; i<N; ++i)
        scanf("%lf", &(pies[i].price));

        /*
    for(i=0; i<N; ++i)
    {
        printf("%g %g\n", pies[i].amount, pies[i].price);
    }*/
    qsort(pies, N, sizeof(Pie), Compare);

    for(i=0; i<N; ++i)
    {
        if(sumAmount + pies[i].amount<=D)
        {
            sumPrice+=pies[i].price;
            sumAmount+=pies[i].amount;
        }
        else
        {
            sumPrice += pies[i].price/pies[i].amount*(D-sumAmount);
            break;
        }
    }
    printf("%.2f\n", sumPrice);

    return 0;
}

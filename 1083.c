#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 10001

int compare(const void*a, const void *b)
{
    int *aa = (int*)b;
    int *bb = (int*)a;
    return *aa-*bb;
}

int main()
{
    int i, N, cards[MAX_N], last, count;

    scanf("%d", &N);
    for(i=1; i<=N; ++i)
    {
        scanf("%d", cards+i);
        cards[i] = abs(cards[i]-i);
    }
    qsort(cards+1, N, sizeof(cards[0]), compare);

    last = cards[1];
    count = 1;
    for(i=2; i<=N; ++i)
    {
        if(last==cards[i])
            ++count;
        else
        {
            if(count!=1)
                printf("%d %d\n", last, count);
            last = cards[i];
            count = 1;
        }
    }

    if(count!=1)
        printf("%d %d\n", last, count);
    return 0;
}

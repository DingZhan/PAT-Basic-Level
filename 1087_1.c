#include <stdio.h>

#define MAX_3N 30000

int buckets[MAX_3N];

int main()
{
    int n, N, v, count=0;
    scanf("%d", &N);
    for(n=1; n<=N; ++n)
    {
        v = n/2+n/3+n/5;
        buckets[v] = 1;
    }
    for(n=0; n<MAX_3N; ++n)
    {
        if(buckets[n])
            ++count;
    }
    printf("%d\n", count);
}

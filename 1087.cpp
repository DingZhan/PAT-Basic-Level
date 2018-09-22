#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 30003
char takens[MAX_N] = {0};

int main()
{
    int i,v, N;
    scanf("%d", &N);
    for(i=1; i<=N; ++i)
    {
        v = i/2+i/3+i/5;
        takens[v]=1;
    }
    v = 0;
    for(i=0; i<MAX_N; ++i)
    {
        if(takens[i])
            ++v;
    }
    printf("%d\n", v);
    return 0;
}

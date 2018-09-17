#include <stdio.h>

int main()
{
    int m, n, i, lastM = -1, count=0;
    scanf("%d", &n);
    for(i=1; i<=n; ++i)
    {
        m = i/2+i/3+i/5;
        if(m!=lastM)
        {
            ++count;
        }
        lastM = m;
    }
    printf("%d", count);
    return 0;
}
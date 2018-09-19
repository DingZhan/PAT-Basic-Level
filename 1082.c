#include <stdio.h>

int main()
{
    int N, i, worstScore, worstID, bestID, bestScore;
    int X, Y, ID, dis;
    scanf("%d", &N);

    worstScore = -1;
    bestScore = 10000000;
    for(i=0; i<N; ++i)
    {
        scanf("%d%d%d", &ID, &X, &Y);
        dis = X*X+Y*Y;
        if(dis>worstScore)
        {
            worstScore = dis;
            worstID = ID;
        }
        if(dis<bestScore)
        {
            bestScore = dis;
            bestID = ID;
        }
    }
    printf("%04d %04d\n", bestID, worstID);
}

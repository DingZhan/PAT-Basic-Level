#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
int main()
{
    double G1, G2, G, minG, maxG;
    int N, M, i, j, validNum;
    int scores[MAX_N];

    scanf("%d%d", &N, &M);
    for(i=0; i<N;++i)
    {
        scanf("%lf", &G2);
        G1 = 0.0;
        validNum = 0;
        for(j=1; j<N; ++j)
        {
            scanf("%lf", &G);
            if(G>=0 && G<=M)
            {
                G1+=G;
                ++validNum;
                if(validNum==1)
                {
                    minG = maxG = G;
                }
                else
                {
                    if(minG>G)
                        minG = G;
                    else if(maxG<G)
                        maxG = G;
                }
            }
        }
        G1=(G1-maxG-minG)/(validNum-2);
        G = (G1+G2)*0.5;
        scores[i] = (int)(G+0.5);
    }
    for(i=0; i<N; ++i)
        printf("%d\n",scores[i]);
    return 0;
}

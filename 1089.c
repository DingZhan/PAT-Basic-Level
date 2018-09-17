#include <stdio.h>

#define MAX_N 102

/*
Condition 1.
w1 is a wolf and a lier, w2 is a wolf but not a lier,
only one lier in others.

Condition 2.
w2 is a wolf and a lier, w1 is a wolf but not a lier,
only one lier in others.
*/

int Check(int w1, int w2, int words[], int N)
{
    int w1w, w2w, i;
    w1w = words[w1];
    w2w = words[w2];
    if((w1w>0 && (w1w==w1 || w1w==w2) ||
       w1w<0 && (-w1w!=w1 && -w1w!=w2))
       &&
       (w2w>0 && (w2w!=w1 && w2w!=w2) ||
       w2w<0 && (-w2w==w1 || -w2w==w2))
        )
    {
        int lierCount=0;
        for(i=1; i<=N; ++i)
        {
            if(i==w1 || i==w2)
                continue;
            int w = words[i];
            if(w>0 && (w==w1 || w==w2))
                ++lierCount;
            else if(w<0 && (-w!=w1 && -w!=w2))
                ++lierCount;
        }
        if(lierCount==1)
            return 1;
    }
    return 0;
}

int main()
{
    int i, N, words[MAX_N], w1, w2, bFind=0;
    scanf("%d", &N);
    for(i=1; i<=N; ++i)
        scanf("%d", &(words[i]));
    for(w1=1; w1<=N; ++w1)
    {
        for(w2 = w1+1; w2<=N; ++w2 )
        {
            if(Check(w1, w2, words, N)||
               Check(w2, w1, words, N))
            {
                bFind = 1;
                break;
            }
        }
        if(bFind)
            break;
    }
    if(bFind)
    {
        printf("%d %d\n", w1, w2);
    }
    else
    {
        printf("No Solution\n");
    }

}

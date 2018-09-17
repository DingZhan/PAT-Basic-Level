#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100002
#define MAX_M  102


int *unmatch[MAX_N]={0};
int unmatchMaxNum[MAX_N]={0};
int unmatchNum[MAX_N]={0};

int main()
{
    int N, M, i, a, b, K, g, t, j, jj;
    int *p;
    int goods[MAX_N];
    short bSucc=1;

    scanf("%d%d", &N, &M);
    for(i=0; i<N; ++i)
    {
        scanf("%d%d", &a, &b);
        if(unmatchNum[a]>=unmatchMaxNum[a])
        {
            p = (int*)malloc((unmatchNum[a]+6)*sizeof(int));
            unmatchMaxNum[a]+=6;
            if(unmatch[a])
                memcpy(p, unmatch[a], sizeof(unmatchNum[a]*sizeof(int)));
            free(unmatch[a]);
            unmatch[a]=p;
        }
        unmatch[a][unmatchNum[a]++]= b;
        if(unmatchNum[b]>=unmatchMaxNum[b])
        {
            p = (int*)malloc((unmatchNum[b]+6)*sizeof(int));
            unmatchMaxNum[b]+=6;
            if(unmatch[b])
                memcpy(p, unmatch[b], sizeof(unmatchNum[b]*sizeof(int)));
            free(unmatch[b]);
            unmatch[b]=p;
        }
        unmatch[b][unmatchNum[b]++]= a;
    }

    for(i=0; i<M; ++i)
    {
        scanf("%d", &K);
        bSucc=1;
        for(j=0; j<K; ++j)
        {
            scanf("%d", &g);
            goods[j]=g;
            //test conflicts
            for(t=0; t<j; ++t)
            {
                a = goods[j];
                //no conflicts record at all
                if(!unmatch[a])
                    continue;
                for(jj=0; jj<unmatchNum[a]; ++jj)
                {
                    if(unmatch[a][jj]==goods[t])
                    {
                        bSucc=0;
                        break;
                    }
                }
            }
        }
        if(bSucc)
            printf("Yes\n");
        else
            printf("No\n");
    }
    for(i=0; i<MAX_N; ++i)
    {
        if(unmatch[i])
            free(unmatch[i]);
    }
}

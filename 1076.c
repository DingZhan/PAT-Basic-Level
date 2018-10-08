#include <stdio.h>
#include <stdlib.h>

#define MAX_N 101

int main()
{
    int N, i, j;
    char str[4], pass[MAX_N];
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        for(j=0; j<4; ++j)
        {
            scanf("%s", str);
            if(str[2]=='T')
                pass[i] = str[0]-'A'+'1';
        }
    }
    pass[i] = '\0';
    printf("%s\n", pass);
}

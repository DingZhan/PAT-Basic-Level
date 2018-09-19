#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100000
int main()
{
    char str[MAX_LEN], str2[MAX_LEN];
    char lastChar;
    int d, N, i, j, count, curLen, rawLen;
    scanf("%d%d", &d, &N);
    str[0] = d+'0';
    str[1] = '\0';

    for(i=1; i<N; ++i)
    {
        lastChar = str[0];
        count = 1;
        curLen = 0;
        rawLen = strlen(str);
        for(j=1; j<rawLen; ++j)
        {
            if(str[j]!=lastChar)
            {
                str2[curLen++] = lastChar;
                str2[curLen++] = count+'0';
                count = 1;
                lastChar = str[j];
            }
            else
                ++count;
        }
        str2[curLen++] = lastChar;
        str2[curLen++] = count+'0';
        str2[curLen] = '\0';
        strcpy(str, str2);
    }
    printf("%s\n", str);
    return 0;
}

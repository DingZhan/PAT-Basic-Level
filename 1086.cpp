#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int A, B, C, len, bFirst=1;
    char buffer[50];
    scanf("%d%d", &A, &B);
    C = A*B;
    sprintf(buffer, "%d", C);
    len = strlen(buffer);
    while(len>0)
    {
        if(buffer[len-1]=='0')
        {
            if(bFirst)
            {
                --len;
                continue;
            }
        }
        printf("%c", buffer[--len]);
        bFirst=0;
    }
    printf("\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1001
int main()
{
    char str[MAX_N], op, lastChar;
    int i, j, count=0;

    scanf("%c", &op);
    //eat enter
    gets(str);
    gets(str);
    if(op=='C')
    {
        lastChar = str[0];
        count = 1;
        for(i=1; str[i]!='\0'; ++i)
        {
            if(str[i]==lastChar)
            {
                ++count;
            }
            else
            {
                if(count==1)
                    printf("%c", lastChar);
                else
                    printf("%d%c", count, lastChar);
                count = 1;
                lastChar = str[i];
            }
        }
        if(count==1)
            printf("%c", lastChar);
        else
            printf("%d%c", count, lastChar);
    }
    else
    {
        count = 0;
        for(i=0; str[i]!='\0'; ++i)
        {
            if(isdigit(str[i]))
            {
                count = count*10+str[i]-'0';
            }
            else
            {
                if(count)
                {
                    for(j=0; j<count; ++j)
                        printf("%c", str[i]);
                }
                else
                {
                    printf("%c", str[i]);
                }
                count = 0;
            }
        }
    }
    printf("\n");
    return 0;
}

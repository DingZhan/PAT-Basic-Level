#include <stdio.h>

int main()
{
    int N, i;
    char str[81], *p;
    short bLetter, bDigit, bDot, bIllegal, len;
    gets(str);
    N = atoi(str);
    for(i=0; i<N; ++i)
    {
        gets(str);
        bLetter = bDigit = bIllegal = len = 0;
        for(p = str; *p!='\0'; ++p, ++len)
        {
            if((*p)>='a' && (*p)<='z'||
               (*p)>='A' && (*p)<='Z')
                bLetter = 1;
            else if((*p)>='0' && (*p)<='9')
                bDigit = 1;
            else if((*p)!='.')
                bIllegal = 1;
        }
        if(len>=6 && !bIllegal && bDigit && bLetter)
            printf("Your password is wan mei.\n");
        else if(len<6)
            printf("Your password is tai duan le.\n");
        else if(len>=6 && bIllegal)
            printf("Your password is tai luan le.\n");
        else if(len>=6 && !bDigit &&bLetter)
            printf("Your password needs shu zi.\n");
        else if(len>=6 && bDigit &&!bLetter)
            printf("Your password needs zi mu.\n");
    }
}

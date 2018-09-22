#include <iostream>
#include <cstring>

/*
1234567 368782971
3695Q8118
*/

int main()
{
    const int LEN=1001;
    int i, j, len1, len2, sum;
    bool bOdd=true;
    char A[LEN], B[LEN], result[LEN];

    std::cin>>A>>B;
    len1 = strlen(A);
    len2 = strlen(B);

    if(len1<len2)
    {
        j = len2-len1;
        for(i=0; i<j; ++i)
            result[i]='0';
        result[i] = '\0';
        strcat(result, A);
        strcpy(A, result);
    }
    else
    {
        j = len1-len2;
        for(i=0; i<j; ++i)
            result[i]='0';
        result[i] = '\0';
        strcat(result, B);
        strcpy(B, result);
        len2 = len1;
    }
    result[len2]='\0';

    bOdd = (len2%2!=0);
    for(i=0; i<len2; ++i)
    {
        if(bOdd)
        {
            sum = (int(A[i]-'0')+int(B[i]-'0'))%13;
            if(sum>=0 && sum<=9)
                result[i]='0'+sum;
            else if(sum==10)
                result[i]='J';
            else if(sum==11)
                result[i]='Q';
            else if(sum==12)
                result[i]='K';
        }
        else
        {
            sum = (int(B[i]-'0')-int(A[i]-'0')+10)%10;
            result[i]='0'+sum;
        }
        bOdd = !bOdd;
    }

    std::cout<<result<<std::endl;

    return 0;
}

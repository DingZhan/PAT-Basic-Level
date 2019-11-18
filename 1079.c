#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 2001


void Reverse(const char* A, char *B)
{
    int i, n;
    n = strlen(A);
    for(i=0; i<n; ++i)
        B[i] = A[n-i-1];
    B[i] = '\0';
}

void Add(const char *A, const char *B, char *C)
{
    int i, n = strlen(A), j;
    int add = 0, sum;
    char t;
    for(i=0; i<n; ++i)
    {
        sum = (A[i]-'0')+(B[i]-'0')+add;
        C[i] = sum%10+'0';
        add = sum/10;
    }
    if(add)
        C[i++] = '0' + add;
    C[i] = '\0';

    //erase head 0 of C
    for(j=i-1; j>=0; --j)
    {
        if(C[j]=='0')
        {
            C[j] = '\0';
            i = j;
        }
        else
            break;
    }
    //special case
    if(j<0)
    {
        C[0] = '0';
        C[1] = '\0';
        return;
    }
    //reverse C
    for(j=0, --i; j<i; ++j, --i)
    {
        t = C[i];
        C[i] = C[j];
        C[j] = t;
    }
}

int IsSymmetric(const char* A)
{
    int i, j;
    j = strlen(A)-1;
    for(i=0; i<j; ++i, --j)
    {
        if(A[i]!=A[j])
            return 0;
    }
    return 1;
}

int main()
{
    char A[MAX_N], B[MAX_N], C[MAX_N];
    int i;

    scanf("%s", &A);

    //if the input A is symmetric, just print it and return
    if(IsSymmetric(A))
    {
        printf("%s is a palindromic number.\n", A);
        return 0;
    }
    for(i=0; i<10; ++i)
    {
        //get B by A
        Reverse(A, B);
        //get C by adding B to A
        Add(A, B, C);
        //print result
        printf("%s + %s = %s\n", A, B, C);
        //judge C
        if(IsSymmetric(C))
        {
            printf("%s is a palindromic number.\n", C);
            break;
        }
        //copy C to A
        strcpy(A, C);
    }

    if(i==10)
        printf("Not found in 10 iterations.\n");

    return 0;
}

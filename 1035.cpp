#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

/*
Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
Sample Output 2:
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/
#define MAX_N 101
bool InsertionSort(int input[], int result[], int next[], int N)
{
    int i, j, t, k;
    bool bSucc=false;
    memcpy(next, input, sizeof(int)*N);
    for(i=1; i<N; ++i)
    {
        for(j=0; j<i; ++j) //not using binary searching, using this stupid method
        {
            if(next[i]<next[j])
            {
                k = next[i];
                for(t=i; t>j; --t)
                    next[t] = next[t-1];
                next[j] = k;
                break;
            }
        }
        if(bSucc)
            return true;
        if(memcmp(next, result, sizeof(int)*N)==0)
        {
            bSucc=true;
        }
    }
    return false;
}
bool MergeSort(int input[], int result[], int next[], int N)
{
    int numInGroup=1;
    int i, j, k, t, len1, len2;
    bool bSucc=false;
    memcpy(next, input, sizeof(int)*N);
    while(N/numInGroup>1)
    {
        i=0;
        while(i<N)
        {
            j = 0;
            len1 = std::min(N-i, numInGroup);
            k = 0;
            len2 = std::min(N-len1-i, numInGroup);
            t = 0;
            while(j<len1 && k<len2)
            {
                if(input[i+j]<input[i+len1+k])
                {
                    next[i+t++] = input[i+j++];
                }
                else
                {
                    next[i+t++] = input[i+len1+k++];
                }
            }
            while(j<len1)
                next[i+t++] = input[i+j++];
            while(k<len2)
                next[i+t++] = input[i+len1+k++];
            i=i+len1+len2;
        }
        if(bSucc)
            return true;
        memcpy(input, next, sizeof(int)*N);
        if(memcmp(next, result, sizeof(int)*N)==0)
        {
            bSucc = true;
        }
        numInGroup*=2;
    }
    //if numInGroup>N, that means the final result is the same as InsertionSort, that's not unique, so
    //skip it
    return false;
}

int main()
{
    int i, N, rawInput[MAX_N], input[MAX_N], result[MAX_N], next[MAX_N];
    cin>>N;
    for(i=0; i<N; ++i)
        cin>>rawInput[i];
    memcpy(input, rawInput, sizeof(int)*N);
    for(i=0; i<N; ++i)
        cin>>result[i];
    if(InsertionSort(input, result, next, N))
    {
        cout<<"Insertion Sort"<<endl;
        for(i=0; i<N; ++i)
        {
            if(i!=0)
                cout<<" ";
            cout<<next[i];
        }
        cout<<endl;
        return 0;
    }
    memcpy(input, rawInput, sizeof(int)*N);
    if(MergeSort(input, result, next, N))
    {
        cout<<"Merge Sort"<<endl;
        for(i=0; i<N; ++i)
        {
            if(i!=0)
                cout<<" ";
            cout<<next[i];
        }
        cout<<endl;
        return 0;
    }
    return 0;
}

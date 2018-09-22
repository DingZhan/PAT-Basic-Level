#include <iostream>
using namespace std;

#define MAX 101
int main()
{
    int n, m, values[MAX], answers[MAX], scores[MAX]={0},i, result, j;
    cin>>n>>m;
    for(i=0; i<m; ++i)
        cin>>values[i];
    for(i=0; i<m; ++i)
        cin>>answers[i];
    for(i=0; i<n; ++i)
    {
        for(j=0; j<m; ++j)
        {
            cin>>result;
            if(answers[j]==result)
                scores[i]+=values[j];
        }
    }
    for(i=0; i<n; ++i)
        cout<<scores[i]<<endl;
    return 0;
}

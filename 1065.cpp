#include <iostream>
#include <cmath>
#include <iomanip>
#include <memory>
#include <memory.h>

using namespace std;

#define NUM 100000
int main()
{
    int N, M, i, ID1, ID2, ID, singleNum=0, lockID=2;
    int *singleTags, *locks;
    bool bFirst = true;
    cin>>N;
    singleTags = new int[NUM];
    locks = new int[N+2];
    memset(singleTags, 0, sizeof(int)*NUM);
    for(i=0; i<N+2; ++i)
        locks[i] = 2;
    for(i=0; i<N; ++i)
    {
        cin>>ID1>>ID2;
        singleTags[ID1] = lockID;
        singleTags[ID2] = lockID;
        ++lockID;
    }
    cin>>M;
    for(i=0; i<M; ++i)
    {
        cin>>ID;
        if(singleTags[ID]==0)
            singleTags[ID]=1;
        else if(singleTags[ID]>=2)
        {
            --locks[singleTags[ID]];
            singleTags[ID]=-singleTags[ID];
        }
    }
    for(i=0; i<NUM; ++i)
    {
        if(singleTags[i]==1)
        {
            ++singleNum;
        }
        else if(singleTags[i]<0)
        {
            if(locks[-singleTags[i]]==1)
                ++singleNum;
        }
    }
    cout<<singleNum<<endl;
    for(i=0; i<NUM; ++i)
    {
        if(singleTags[i]==1)
        {
            if(bFirst)
            {
                cout<<setw(5)<<setfill('0')<<i;
                bFirst = false;
            }
            else
                cout<<" "<<setw(5)<<setfill('0')<<i;
        }
        else if(singleTags[i]<0)
        {
            if(locks[-singleTags[i]]==1)
            {
                if(bFirst)
                {
                    cout<<setw(5)<<setfill('0')<<i;
                    bFirst = false;
                }
                else
                    cout<<" "<<setw(5)<<setfill('0')<<i;
            }
        }
    }
    if(singleNum)
        cout<<endl;
    delete[] singleTags;
    delete[] locks;
    return 0;
}

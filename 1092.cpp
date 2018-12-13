#include <iostream>

using namespace std;
#define MAX_N 1002

int main()
{
    int N, M, i, j, q, maxPies=0;
    int pies[MAX_N]={0};
    cin>>N>>M;
    for(i=0;i<M; ++i)
    {
        for(j=0; j<N; ++j)
        {
            cin>>q;
            pies[j]+=q;
            if(pies[j]>maxPies)
                maxPies = pies[j];
        }
    }
    bool bFirst=true;
    cout<<maxPies<<endl;
    for(i=0; i<N; ++i)
    {
        if(maxPies==pies[i])
        {
            if(!bFirst)
                cout<<" ";
            cout<<i+1;
            bFirst=false;
        }
    }
    cout<<endl;


    return 0;
}

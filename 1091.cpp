#include <iostream>

using namespace std;
#define MAX_N 10
int main()
{
    int M, K, i, j, t, k, result, count1;
    cin>>M;
    for(i=0; i<M; ++i)
    {
        cin>>K;
        count1 = 0;
        t = K;
        while(t)
        {
            ++count1;
            t/=10;
        }
        for(j=1; j<MAX_N; ++j)
        {
            result = K*K*j;
            //N, result
            t = 1;
            for(k=0; k<count1; ++k)
            {  t*=10;  }
            if(result%t==K)
            {
                cout<<j<<" "<<result<<endl;
                break;
            }
        }
        if(j==MAX_N)
            cout<<"No"<<endl;

    }
    return 0;
}

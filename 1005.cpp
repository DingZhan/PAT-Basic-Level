#include <iostream>

#define N 101
int main()
{
    int n, num, i, counts[N];
    bool bTakens[N];

    for(i=0; i<N; ++i)
    {
        counts[i] = 0;
        bTakens[i] = false;
    }

    std::cin>>num;
    while(num>0)
    {
        std::cin>>n;
        ++counts[n];
        bTakens[n] = true;
        while(n!=1)
        {
            if(n%2==0)
                n = n/2;
            else
                n = (3*n+1)/2;
            if(n<N)
                ++counts[n];
        }
        --num;
    }
    bool bFirst=true;
    for(i=N-1; i>=0; --i)
    {
        if(counts[i]==1&& bTakens[i])
        {
            if(bFirst)
            {
                std::cout<<i;
                bFirst=false;
            }
            else
            {
                std::cout<<' '<<i;
            }
        }
    }
    return 0;
}

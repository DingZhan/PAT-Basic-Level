#include <iostream>
#include <cmath>

bool IsPrimerSimple(int p)
{
    int t = (int)sqrt(p+0.0);
    int i;
    for(i=2; i<=t; ++i)
    {
        if( p%i==0)
            return false;
    }
    return true;
}
int CalculatePairCount(int n)
{
    int lastPrime=3, pairCount=0, i;
    for(i=lastPrime+2; i<=n; i+=2)
    {
        if(IsPrimerSimple(i))
        {
            if(i-lastPrime==2)
                ++pairCount;
            lastPrime = i;
        }
    }
    return pairCount;
}
int main()
{
    int n;
    std::cin>>n;
    std::cout<<CalculatePairCount(n)<<std::endl;
    return 0;
}
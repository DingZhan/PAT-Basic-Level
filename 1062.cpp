#include <iostream>
#include <sstream>

using namespace std;

/*
7/18 13/20 12
*/
int gcd(int a, int b)
{
    int k = a%b;
    while(k)
    {
        a = b;
        b = k;
        k = a%b;
    }
    return b;
}
int lcm(int a, int b)
{
    int k = gcd(a, b);
    return a*b/k;
}
int main()
{
    int N1, M1, N2, M2, K, i, j;
    char c;
    bool bFirst=true;

    cin>>N1>>c>>M1>>N2>>c>>M2>>K;

    int maxLCM = lcm(lcm(M1, M2), K);
    N1*=(maxLCM/M1);
    N2*=(maxLCM/M2);
    if(N1>N2)
        std::swap(N1, N2);
    for(i=N1+1; i<N2; ++i)
    {
        j = gcd(i, maxLCM);
        if(maxLCM/j==K)
        {
            if(!bFirst)
                cout<<" ";
            cout<<i/j<<"/"<<K;
            bFirst=false;
        }
    }
    cout<<endl;
    return 0;
}

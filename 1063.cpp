#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n, i, real, image,  r;
    double maxR=0.0;

    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>real>>image;
        r = real*real+image*image;
        if(r>maxR)
            maxR = r;
    }
    maxR = sqrt(maxR);
    cout<<setprecision(2)<<std::fixed<<maxR;
    return 0;
}

#include <iostream>
#include <sstream>


int main()
{
    int n, i, a, b,c ,r;
    bool *bResults;
    std::cin>>n;
    if(n<=0)
        return 0;
    bResults = new bool[n];
    for(i=0; i<n; ++i)
    {
        std::cin>>a>>b>>c;
        r = a+b;
        if(a>0 && b>0 && r<0)
            bResults[i] = true;
        else if(a<0 && b<0 && r>0)
            bResults[i] = false;
        else
            bResults[i] = r>c;
    }
    for(i=0; i<n; ++i)
    {
        std::cout<<"Case #"<<i+1<<": "<<(bResults[i]?"true":"false")<<std::endl;
    }
    delete[] bResults;
    return 0;
}
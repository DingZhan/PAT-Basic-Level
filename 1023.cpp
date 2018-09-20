#include <iostream>
#include <string>
#include <algorithm>

//2 2 0 0 0 3 0 0 1 0
int main()
{
    int counts[10]={0}, a, i, j, minID=-1;

    for(i=0; i<10; ++i)
    {
        std::cin>>counts[i];
        if(minID==-1 && i!=0 && counts[i]!=0)
            minID = i;
    }
    std::cout<<minID;
    --counts[minID];
    for(i=0; i<10; ++i)
    {
        for(j=0; j<counts[i]; ++j)
            std::cout<<i;
    }
    std::cout<<std::endl;
    return 0;
}
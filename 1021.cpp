#include <iostream>
#include <string>
#include <algorithm>


//100311
int main()
{
    std::string N;
    int i, counts[10]={0};
    std::cin>>N;
    std::string::iterator it;

    for(it=N.begin(); it!=N.end(); ++it)
        ++counts[(*it)-'0'];
    for(i=0; i<=9; ++i)
    {
        if(counts[i])
            std::cout<<i<<":"<<counts[i]<<std::endl;
    }
    return 0;
}
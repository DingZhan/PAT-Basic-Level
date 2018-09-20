#include <iostream>
#include <string>

int main()
{
    int n, BWinCounts[2]={0}, JWinCounts[2]={0}, CWinCounts[2]={0}, i;
    char a, b;
    std::cin>>n;
    for(i=0; i<n; ++i)
    {
        std::cin>>a>>b;
        if(a==b)
            continue;
        else if(a=='J' && b=='C')
            ++CWinCounts[1];
        else if(a=='J' && b=='B')
            ++JWinCounts[0];
        else if(a=='C' && b=='B')
            ++BWinCounts[1];
        else if(a=='C' && b=='J')
            ++CWinCounts[0];
        else if(a=='B' && b=='C')
            ++BWinCounts[0];
        else if(a=='B' && b=='J')
            ++JWinCounts[1];
    }
    int winCounts[2];
    winCounts[0] = BWinCounts[0]+JWinCounts[0]+CWinCounts[0];
    winCounts[1] = BWinCounts[1]+JWinCounts[1]+CWinCounts[1];
    std::cout<<winCounts[0]<<' '<<n-winCounts[0]-winCounts[1]<<' '<<winCounts[1]<<std::endl;
    std::cout<<winCounts[1]<<' '<<n-winCounts[0]-winCounts[1]<<' '<<winCounts[0]<<std::endl;
    if(BWinCounts[0]>=CWinCounts[0] && BWinCounts[0]>=JWinCounts[0])
        std::cout<<"B";
    else if(CWinCounts[0]>=JWinCounts[0])
        std::cout<<"C";
    else
        std::cout<<"J";
    std::cout<<" ";
    if(BWinCounts[1]>=CWinCounts[1] && BWinCounts[1]>=JWinCounts[1])
        std::cout<<"B";
    else if(CWinCounts[1]>=JWinCounts[1])
        std::cout<<"C";
    else
        std::cout<<"J";
    std::cout<<std::endl;
    return 0;
}
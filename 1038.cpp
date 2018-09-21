#include <iostream>
#include <cstring>
#include <memory>
#include <string>

/*
输入样例：
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
输出样例：
3 2 0
*/

int main()
{
    int N, i, scoreCount[100], score, N2, *scoreIDs;

    for(i=0; i<100; ++i)
        scoreCount[i]=0;
    std::cin>>N;
    for(i=0; i<N; ++i)
    {
        std::cin>>score;
        ++scoreCount[score];
    }
    std::cin>>N2;
    scoreIDs = new int[N2];
    for(i=0; i<N2; ++i)
        std::cin>>scoreIDs[i];
    for(i=0; i<N2; ++i)
    {
        std::cout<<scoreCount[scoreIDs[i]];
        if(i!=N2-1)
            std::cout<<" ";
    }
    delete[] scoreIDs;
    std::cout<<std::endl;
    return 0;
}
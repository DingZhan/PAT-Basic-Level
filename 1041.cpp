#include <iostream>
#include <cstring>
#include <memory>
#include <string>

/*
ÊäÈëÑùÀý£º
4
10120150912233 2 4
10120150912119 4 1
10120150912126 1 3
10120150912002 3 2
2
3 4
Êä³öÑùÀý£º
10120150912002 2
10120150912119 1
*/

int main()
{
    int i, testID, realIDs[1000], N, M, laterIDs[1000];
    char (*IDs)[17], ID[17];

    std::cin>>N;
    IDs = new char[N][17];
    for(i=0; i<N; ++i)
    {
        std::cin>>ID>>testID;
        std::cin>>realIDs[testID-1];
        strcpy(IDs[testID-1], ID);
    }
    std::cin>>M;
    for(i=0; i<M; ++i)
        std::cin>>laterIDs[i];
    for(i=0; i<M; ++i)
    {
        std::cout<<IDs[laterIDs[i]-1]<<" "<<realIDs[laterIDs[i]-1]<<std::endl;
    }
    delete[] IDs;

    return 0;
}

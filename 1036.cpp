#include <iostream>
#include <cstring>
#include <memory>
#include <string>

/*
����������
10 a
���������
aaaaaaaaaa
a        a
a        a
a        a
aaaaaaaaaa
*/

int main()
{
    int N, i, j, M;
    char c;
    std::cin>>N>>c;
    M = int(N*0.5+0.5);
    for(i=0; i<M; ++i)
    {
        for(j=0; j<N; ++j)
        {
            if(j==0||i==0||i==M-1)
                std::cout<<c;
            else if(j==N-1)
                std::cout<<c;
            else
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}
#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>

/*
输入样例：
3 2 8 5
输出样例：
330
*/

int main()
{
    int N, i, j;
    int datas[10], sum=0;
    std::string str;

    std::cin>>N;
    for(i=0; i<N; ++i)
        std::cin>>datas[i];

    for(i=0; i<N; ++i)
    {
        for(j=0; j<N; ++j)
        {
            if(i==j)
                continue;
            sum += datas[i]*10+datas[j];
        }
    }
    std::cout<<sum<<std::endl; 
    return 0;
}
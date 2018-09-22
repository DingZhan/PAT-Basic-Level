#include <iostream>
#include <cstring>
#include <iomanip>

/*
输入样例：
4
0.1 0.2 0.3 0.4 
输出样例：
5.00
*/

int main()
{
    int N, i;
    double data, sum=0.0;

    std::cin>>N;
    for(i=0; i<N; ++i)
    {
        std::cin>>data;
        sum+=data*(N-i)*(i+1);
    }

    std::cout<<std::fixed<<std::setprecision(2)<<sum<<std::endl;

    return 0;
}
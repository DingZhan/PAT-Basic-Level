#include <iostream>
#include <cstring>
#include <memory>
#include <string>

/*
输入样例：
APPAPT
输出样例：
2
*/

int main()
{
    int PCount=0, ACount=0, TCount=0, maxC=100000, sum=0, sum1=0;
    char *str, *p;

    str = new char[maxC+1];
    std::cin>>str;
    p = str;
    while((*p)!='\0')
    {
        if((*p)=='P')
            ++PCount;
        else if((*p)=='A')
        {
            ++ACount;
            sum1+=PCount;
        }
        else if((*p)=='T')
        {
            ++TCount;
            sum = (sum+sum1)%1000000007;
        }
        ++p;
    }
    std::cout<<sum<<std::endl;

    delete[] str;
    return 0;
}
#include <iostream>
#include <iomanip>
#include <cmath>

/*
2*thegma(2*i+1)-1<=N
输入样例：
19 *
输出样例：
*****
 ***
  *
 ***
*****
2

等差公式: Sn=a1*n+[n*(n-1)*d]/2
2*n*n<=N+1
*/
int main()
{
    int N, n, leftD, i, j;
    char c;
    std::cin>>N>>c;
    n = sqrt((N+1)/2+0.0);
    leftD = N+1-2*n*n;
    for(i=n; i>=1; --i)
    {
        j=n-i;
        while(j-->0)
            std::cout<<" ";
        j=2*i-1;
        while(j-->0)
            std::cout<<c;
        std::cout<<std::endl;
    }
    for(i=2; i<=n; ++i)
    {
        j=n-i;
        while(j-->0)
            std::cout<<" ";
        j=2*i-1;
        while(j-->0)
            std::cout<<c;
        std::cout<<std::endl;
    }
    std::cout<<leftD<<std::endl;
    return 0;
}
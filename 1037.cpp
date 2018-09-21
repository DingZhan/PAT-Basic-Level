#include <iostream>
#include <cstring>
#include <memory>
#include <string>

/*
输入样例1：
10.16.27 14.1.28
输出样例1：
3.2.1
输入样例2：
14.1.28 10.16.27
输出样例2：
-3.2.1
*/

int main()
{
    int GUnit=17, SUnit=29, sub, gp, sp, kp, ga, sa, ka, gsum, asum, g, s, k;
    char c;

    std::cin>>gp>>c>>sp>>c>>kp;
    std::cin>>ga>>c>>sa>>c>>ka;

    gsum = gp*GUnit*SUnit+sp*SUnit+kp;
    asum = ga*GUnit*SUnit+sa*SUnit+ka;
    if(asum<gsum)
    {
        std::cout<<"-";
        std::swap(asum, gsum);
    }
    sub = asum-gsum;
    g = sub/(GUnit*SUnit);
    s = sub/SUnit-g*GUnit;
    k = sub - g*GUnit*SUnit-s*SUnit;
    std::cout<<g<<"."<<s<<"."<<k<<std::endl;

    return 0;
}
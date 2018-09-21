#include <iostream>
#include <cstring>
#include <memory>
#include <string>

/*
输入样例1：
2/3 -4/2
输出样例1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例2：
5/3 0/6
输出样例2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

10/3 2/1

这道题折磨这么长时间，最重要原因都是数据中间计算的时候会有溢出，所以把int全部改成long long就对了
*/
long long gcd(long long a, long long b)
{
    long long c;
    c = a%b;
    while(c!=0)
    {
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}
int main()
{
    long long a1, b1, a2, b2, k1, k2, k, g, i, b, na1, na2,a;
    char c;
    bool bMinus1=false, bMinus2=false, bMinus, bInteger1, bInteger2, bInteger, bInfinite=false;
    char opers[4]={'+', '-', '*', '/'};
    std::cin>>a1>>c>>b1>>a2>>c>>b2;
    if(a1<0)
    {
        bMinus1=true;
        a1 = -a1;
    }
    if(a2<0)
    {
        bMinus2=true;
        a2 = -a2;
    }
    bInteger1=false;
    k1 = a1/b1;
    if(a1%b1==0)
    {
        bInteger1=true;
        a1/=b1;
        b1 = 1;
    }
    else
    {
        a1-=b1*k1;
        g = gcd(a1, b1);
        a1/=g;
        b1/=g;
    }

    bInteger2=false;
    k2 = a2/b2;
    if(a2%b2==0)
    {
        bInteger2=true;
        a2/=b2;
        b2 = 1;
    }
    else
    {
        a2-=b2*k2;
        g = gcd(a2, b2);
        a2/=g;
        b2/=g;
    }

    for(i=0; i<4; ++i)
    {
        if(bMinus1)
            std::cout<<"(-";
        if(k1!=0)
        {
            std::cout<<k1;
            if(a1%b1!=0)
                std::cout<<" "<<a1<<"/"<<b1;
        }
        else
        {
            if(a1%b1!=0)
                std::cout<<a1<<"/"<<b1;
            else
                std::cout<<0;
        }
        if(bMinus1)
            std::cout<<")";
        std::cout<<" "<<opers[i]<<" ";

        if(bMinus2)
            std::cout<<"(-";
        if(k2!=0)
        {
            std::cout<<k2;
            if(a2%b2!=0)
                std::cout<<" "<<a2<<"/"<<b2;
        }
        else
        {
            if(a2%b2!=0)
                std::cout<<a2<<"/"<<b2;
            else
                std::cout<<0;
        }
        if(bMinus2)
            std::cout<<")";
        std::cout<<" = ";
        if(bInteger1)
            na1 = k1;
        else
            na1 = b1*k1+a1;
        if(bInteger2)
            na2=  k2;
        else
            na2=  b2*k2+a2;
        g = gcd(b1, b2);
        b = b1*b2/g;
        na1 = na1*b2/g;
        na2 = na2*b1/g;
        if(bMinus1)
            na1  = -na1;
        if(bMinus2)
            na2  = -na2;
        if(opers[i]=='+')
            a=na1+na2;
        else if(opers[i]=='-')
            a=na1-na2;
        else if(opers[i]=='*')
        {
            a = na1*na2;
            b = b*b;
        }
        else if(opers[i]=='/')
        {
            if(a2==0)
            {
                bInfinite = true;
            }
            else
            {
                a = na1*b;
                b = na2*b;
                if(b<0)
                {
                    b = -b;
                    a = -a;
                }
            }
        }
        if(bInfinite)
            std::cout<<"Inf";
        else
        {
            bInteger=false;
            bMinus=false;
            if(a<0)
            {
                bMinus=true;
                a = -a;
            }
            k = a/b;
            if(a%b==0)
                bInteger=true;
            else
            {
                a-=b*k;
                g = gcd(a, b);
                a/=g;
                b/=g;
            }
            if(bMinus)
                std::cout<<"(-";
            if(k!=0)
            {
                std::cout<<k;
                if(a%b!=0)
                    std::cout<<" "<<a<<"/"<<b;
            }
            else
            {
                if(a%b!=0)
                    std::cout<<a<<"/"<<b;
                else
                    std::cout<<0;
            }
            if(bMinus)
                std::cout<<")";

        }
        std::cout<<std::endl;
    }
    return 0;
}

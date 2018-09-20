#include <iostream>
#include <iomanip>
#include <cmath>

bool IsPrimerSpecial(int a)
{
    int b = (int)sqrt(a+0.0);
    for(int i=3; i<=b; ++i)
    {
        if(a%i==0)
            return false;
    }
    return true;
}
int main()
{
    int m, n, id=1, count=1, i;
    bool bFirst=false;
    std::cin>>m>>n;
    if(m<=0)
        return 0;
    if(m==1)
    {
        std::cout<<2;
        i = 3;
    }
    else
    {
        i = 3;
        while(true)
        {
            if(IsPrimerSpecial(i))
                ++id;
            if(id==m)
                break;
            i+=2;
        }
        std::cout<<i;
        i+=2;
    }
    if(m==n)
        return 0;
    while(true)
    {
        if(IsPrimerSpecial(i))
        {
            ++id;
            if(bFirst)
            {
                std::cout<<i;
                bFirst=false;
            }
            else
                std::cout<<" "<<i;
            if(count%10==9)
            {
                bFirst = true;
                std::cout<<std::endl;
            }
            if(id==n)
                break;
            ++count;
        }
        i+=2;
    }

    return 0;
}
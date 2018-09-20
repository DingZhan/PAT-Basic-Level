#include <iostream>

int Calculate(int n)
{
    int step = 0;
    while(n!=1)
    {
        if(n%2==0)
            n/=2;
        else
            n = (3*n+1)/2;
        ++step;
    }
    return step;
}
int main()
{
    int n = 5;
    std::cin>>n;
    if(n<=1)
    {
        std::cout<<0<<std::endl;
        return 0;
    }
    int step = Calculate(n);
    std::cout<<step<<std::endl;
    return 0;
}
#include <iostream>
#include <iomanip>

/*
123 4577973
Êä³öÑùÀý£º
12:42:59
*/
int main()
{
    const int CLK_TCK_A =100;
    unsigned int C1, C2, seconds, part;
    std::cin>>C1>>C2;
    seconds = (C2-C1)/CLK_TCK_A;
    part = (C2-C1)%CLK_TCK_A;
    if(part>=CLK_TCK_A/2)
        ++seconds;

    std::cout<<std::setfill('0')<<std::setw(2)<<seconds/3600;
    seconds=seconds-seconds/3600*3600;
    std::cout<<":"<<std::setfill('0')<<std::setw(2)<<seconds/60;
    seconds=seconds-seconds/60*60;
    std::cout<<":"<<std::setfill('0')<<std::setw(2)<<seconds;

    return 0;
}
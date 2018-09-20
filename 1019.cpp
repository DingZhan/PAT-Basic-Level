#include <iostream>
#include <string>
#include <algorithm>

/*
6767
Êä³öÑùÀı1£º
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
*/
int main()
{
    int a, f, l;
    short bits[5];
    const int N = 6174;
    std::cin>>a;
    bits[0] = a/1000;
    bits[1] = (a/100)%10;
    bits[2] = (a/10)%10;
    bits[3] = a%10;
    if(bits[0]==bits[1] && bits[0]==bits[2] && bits[0]==bits[3])
        std::cout<<bits[0]<<bits[0]<<bits[0]<<bits[0]<<" - "<< bits[0]<<bits[0]<<bits[0]<<bits[0]<<" = 0000"<<std::endl;
    else
    {
        do
        {
            std::sort(bits+0, bits+4);
            f = bits[0]+bits[1]*10+bits[2]*100+bits[3]*1000;
            l = bits[0]*1000+bits[1]*100+bits[2]*10+bits[3];
            std::cout<<bits[3]<<bits[2]<<bits[1]<<bits[0]<<" - "<<bits[0]<<bits[1]<<bits[2]<<bits[3]<<" = ";
            a = f-l;
            bits[0] = a/1000;
            bits[1] = (a/100)%10;
            bits[2] = (a/10)%10;
            bits[3] = a%10;
            std::cout<<bits[0]<<bits[1]<<bits[2]<<bits[3]<<std::endl;
        }  while(a!=N);
    }
    return 0;
}
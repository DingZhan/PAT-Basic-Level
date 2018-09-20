#include <iostream>

void Print(int n)
{
    int num[3]={0}, i=0;
    while(n>0)
    {
        num[i++] = n%10;
        n = n/10;
    }
    for(i=0; i<num[2]; ++i)
        std::cout<<'B';
    for(i=0; i<num[1]; ++i)
        std::cout<<'S';
    for(i=0; i<num[0]; ++i)
        std::cout<<i+1;
    std::cout<<std::endl;
}
int main()
{
    int n;
    std::cin>>n;
    Print(n);
    return 0;
}
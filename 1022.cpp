#include <iostream>
#include <string>
#include <algorithm>

//123 456 8
int main()
{
    int A, B, C, D;
    std::string result;

    std::cin>>A>>B>>D;
    C = A+B;

    while(C)
    {
        result.push_back(C%D+'0');
        C = C/D;
    }
    if(result.empty())
        result.push_back('0');
    std::reverse(result.begin(), result.end());
    std::cout<<result<<std::endl;
    return 0;
}
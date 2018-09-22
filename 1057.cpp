#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>

/*
输入样例：
PAT (Basic)
输出样例：
3 4
*/

int main()
{
    int N, i, num0=0, num1=0;
    char c;
    std::string str;

    std::getline(std::cin, str);
    N=0;
    for(std::string::iterator it=str.begin(); it!=str.end(); ++it)
    {
        c = *it;
        if(c>='a' && c<='z')
            N+=c-'a'+1;
        else if(c>='A' && c<='Z')
            N+=c-'A'+1;
    }
    while(N>0)
    {
        if(N%2)
            ++num1;
        else
            ++num0;
        N=N/2;
    }
    std::cout<<num0<<" "<<num1<<std::endl; 
    return 0;
}
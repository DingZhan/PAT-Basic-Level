#include <iostream>
#include <sstream>

/*
输入样例：
3 4 -5 2 6 1 -2 0
输出样例：
12 3 -10 1 6 0
*/
void Diff(const char* str)
{
    std::istringstream iss(str);
    int expData, coeff;
    bool bFirst=true;
    while(true)
    {
        if(iss.fail()||iss.eof())
            break;
        iss>>coeff>>expData;
        if(iss.fail())
            break;
        if(expData==0 || coeff==0)
            continue;
        if(bFirst)
            bFirst=false;
        else
            std::cout<<' ';
        std::cout<<expData*coeff<<" "<<expData-1;
    }
    if(bFirst)
        std::cout<<"0 0";
    std::cout<<std::endl;
}

int main()
{
    std::string buffer;
    std::getline(std::cin, buffer);
    Diff(buffer.c_str());
    return 0;
}
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <sstream>
/*
输入样例：
2.3 3.5 5.2 0.4
输出样例：
-8.68-8.23i
*/

int main()
{
    double R1, P1, R2, P2, real, image, angle;
    std::ostringstream oss;
    std::string str1, str2;

    std::cin>>R1>>P1>>R2>>P2;
    angle = P1+P2;
    real = cos(angle)*R1*R2;
    image = sin(angle)*R1*R2;


    oss.str("");
    oss<<std::fixed<<std::setprecision(2)<<real;
    str1 = oss.str();
    if(str1[0]=='-')
    {
        if(str1.size()==5 && str1[1]=='0' && str1[2]=='.' && str1[3]=='0' && str1[4]=='0')
            str1.erase(str1.begin());
    }

    oss.str("");
    oss<<std::fixed<<std::setprecision(2)<<image;
    str2 = oss.str();
    if(str2[0]=='-')
    {
        if(str2.size()==5 && str2[1]=='0' && str2[2]=='.' && str2[3]=='0' && str2[4]=='0')
            str2[0]='+';
        std::cout<<std::fixed<<std::setprecision(2)<<str1<<str2<<"i"<<std::endl;
    }
    else
        std::cout<<std::fixed<<std::setprecision(2)<<str1<<"+"<<image<<"i"<<std::endl;
    return 0;
}
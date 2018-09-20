#include <iostream>
#include <string>
#include <algorithm>

/* [+-][1-9]"."[0-9]+E[+-][0-9]+
+1.23400E-03
输出样例1：
0.00123400
输入样例2：
-1.2E+10
输出样例2：
-12000000000
*/
int main()
{
    int i, a;
    bool bNegData=false, bNegExp=false;
    char part1, c;
    bool bThird=false;
    std::string part2, part3, str;
    std::string::iterator it;


    i=0;
    std::cin>>str;
    for(i=0; i<(int)str.size(); ++i)
    {
        c = str[i];
        if(c=='-' || c=='+')
        {
            if(c=='-')
            {
                if(i==0)
                    bNegData = true;
                else
                    bNegExp = true;
            }
        }
        else if(i==1)
            part1 = c;
        else if(c=='E'||c=='e')
            bThird = true;
        else if(c=='.')
        {
            continue;
        }
        else
        {
            if(!bThird)
                part2.push_back(c);
            else
                part3.push_back(c);
        }
    }

    a = atoi(part3.c_str());
    if(bNegData)
        std::cout<<"-";
    if(bNegExp)
    {
        if(a>0)
        {
            std::cout<<"0.";
            for(i=1; i<a; ++i)
                std::cout<<"0";
            std::cout<<part1;
            std::cout<<part2;
        }
        else
        {
            std::cout<<part1<<".";
            std::cout<<part2;
        }
    }
    else
    {
        std::cout<<part1;
        for(i=0; i<a && i<part2.size(); ++i)
            std::cout<<part2[i];
        if(i<a)
        {
            for(; i<a ; ++i)
                std::cout<<"0";
        }
        else if(i<part2.size())
        {
            std::cout<<".";
            for(;i<part2.size(); ++i)
                std::cout<<part2[i];
        }
    }
    std::cout<<std::endl;
    return 0;
}
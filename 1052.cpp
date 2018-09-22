#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
/*
输入样例：
[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
输出样例：
╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@
*/

int main()
{
    char tokens[3][10][10];
    std::string str;
    bool bSucc;
    int N, i, nums[3], w, p;
    size_t j;
    char (*results)[40], *s;


    for(i=0; i<3; ++i)
    {
        std::getline(std::cin, str);
        j=0;
        p=0;
        while(true)
        {
            bSucc =false;
            w = 0;
            if(j>=str.size())
                break;
            while(j<str.size())
            {
                if(str[j]=='[')
                {
                    ++j;
                    break;
                }
                ++j;
            }
            if(j>=str.size())
                break;

            while(j<str.size())
            {
                if(str[j]==']')
                {
                    ++j;
                    bSucc = true;
                    break;
                }
                tokens[i][p][w++]=str[j];
                ++j;
            }
            if(bSucc)
            {
                if(w!=0)
                {
                    tokens[i][p][w++]='\0';
                    ++p;
                }
            }
            else
                break;
        }
        nums[i]=p;
    }

    /*
    for(i=0; i<3; ++i)
    {
         for(j=0; j<nums[i]; ++j)
         {
             std::cout<<tokens[i][j]<<" ";
         }
        std::cout<<std::endl;
    }*/

    std::cin>>N;
    results = new char[N][40];
    for(i=0; i<N; ++i)
    {
        bSucc=true;
        w=0;
        for(j=0; j<5; ++j)
        {
            std::cin>>p;
            --p;
            if(j==1)
                results[i][w++]='(';
            else if(j==4)
                results[i][w++]=')';
            if(j<3)
            {
                if(p>=nums[j]||p<0)
                {
                    bSucc=false;
                    break;
                }
                s = tokens[j][p];
            }
            else
            {
                if(p>=nums[4-j]||p<0)
                {
                    bSucc=false;
                    break;
                }
                s = tokens[4-j][p];
            }
            while((*s)!='\0')
                results[i][w++]=*s++;
        }
        if(!bSucc)
            strcpy(results[i],"Are you kidding me? @\\/@");
        else
            results[i][w]='\0';
    }
    for(i=0; i<N; ++i)
    {
        std::cout<<results[i]<<std::endl;
    }
    delete[] results;
    return 0;
}
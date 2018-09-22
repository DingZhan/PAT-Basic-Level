#include <iostream>
#include <cstring>
#include <memory>
#include <string>

/*
输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee
*/

int main()
{
    int i, counts[6]={0};
    const int LEN=10001;
    char *s="PATest";
    char str[LEN], *p;
    bool bSucc;

    std::cin.getline(str, LEN);
    p = str;
    while((*p)!='\0')
    {
        if((*p)=='P')
            ++counts[0];
        else if((*p)=='A')
            ++counts[1];
        else if((*p)=='T')
            ++counts[2];
        else if((*p)=='e')
            ++counts[3];
        else if((*p)=='s')
            ++counts[4];
        else if((*p)=='t')
            ++counts[5];
        ++p;
    }
    
    while(true)
    {
        bSucc=false;
        for(i=0; i<6; ++i)
        {
            if(counts[i]>0)
            {
                std::cout<<s[i];
                --counts[i];
                bSucc = true;
            }
        }
        if(!bSucc)
            break;
    }
    std::cout<<std::endl;
    return 0;
}
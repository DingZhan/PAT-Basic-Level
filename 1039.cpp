#include <iostream>
#include <cstring>
#include <memory>
#include <string>

/*
输入样例1：
ppRYYGrrYBR2258
YrR8RrY
输出样例1：
Yes 8
*/

int main()
{
    int i, sellPerls[62], needPerls[62], count1=0, count2=0,  lessCount=0;
    char perls[1001], *p;
    bool bYes=true;

    for(i=0; i<62; ++i)
    {
        sellPerls[i]=0;
        needPerls[i]=0;
    }
    std::cin.getline(perls, 1001);
    p = perls;
    while((*p)!='\0')
    {
        if((*p)>='0'&&(*p)<='9')
            ++sellPerls[(*p)-'0'];
        else if((*p)>='a'&&(*p)<='z')
            ++sellPerls[(*p)-'a'+10];
        else if((*p)>='A'&&(*p)<='Z')
            ++sellPerls[(*p)-'A'+36];
        ++p;
        ++count1;
    }

    std::cin.getline(perls, 1001);
    p = perls;
    while((*p)!='\0')
    {
        if((*p)>='0'&&(*p)<='9')
            ++needPerls[(*p)-'0'];
        else if((*p)>='a'&&(*p)<='z')
            ++needPerls[(*p)-'a'+10];
        else if((*p)>='A'&&(*p)<='Z')
            ++needPerls[(*p)-'A'+36];
        ++p;
        ++count2;
    }

    for(i=0; i<62; ++i)
    {
        if(sellPerls[i]<needPerls[i])
        {
            bYes = false;
            lessCount+=(needPerls[i]-sellPerls[i]);
        }
    }

    if(bYes)
        std::cout<<"Yes "<<count1-count2<<std::endl;
    else
        std::cout<<"No "<<lessCount<<std::endl;
    return 0;
}
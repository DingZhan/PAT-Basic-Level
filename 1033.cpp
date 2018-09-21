#include <iostream>
#include <cstring>
#include <memory>
#include <string>

/*
7+IE.
7_This_is_a_test.
Êä³öÑùÀý£º
_hs_s_a_tst

*/

int main()
{
    bool badKeys[256];
    char *text, *c, i;
    bool bUpperBad=false, bHas=false;

    memset(badKeys, 0, sizeof(bool)*256);
    text = new char[100001];
    std::cin.getline(text, 100001);
    c = text;
    while((*c)!='\0')
    {
        badKeys[*c]=true;
        if((*c)=='+')
            bUpperBad=true;
        else if((*c)>='A' && (*c)<='Z')
            badKeys[(*c)-'A'+'a']=true;
        else if((*c)>='a' && (*c)<='z')
            badKeys[(*c)-'a'+'A']=true;
        ++c;
    }
    if(bUpperBad)
    {
        for(i='A' ; i<='Z'; ++i)
            badKeys[i] = true;
    }
    std::cin>>text;
    c = text;
    while((*c)!='\0')
    {
        if(!badKeys[*c])
            std::cout<<(*c);
        ++c;
    }
    delete[] text;
    std::cout<<std::endl;
    return 0;
}
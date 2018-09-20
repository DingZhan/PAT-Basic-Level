#include <iostream>
#include <cstring>


/*
7_This_is_a_test
_hs_s_a_es

7_This_is_a_tespta
_hs_s_a_es
*/

int main()
{
    char rawStr[81], inputStr[81], badKeys[37],c;
    bool badTags[37], hasIt[37]; //0-25, "A-Z", 26-35  "0-9"  36 "_"
    int badKeyCount=0, n1, n2, code, i, j;

    for(i=0; i<37; ++i)
    {
        badTags[i] = false;
        hasIt[i] = false;
    }
    std::cin>>rawStr;
    std::cin>>inputStr;
    n1 = strlen(rawStr);
    n2 = strlen(inputStr);
    for(j=0, i=0; j<n2; ++j)
    {
        while(i<n1)
        {
            c = rawStr[i];
            if(c>='a' && c<='z')
            {
                code=c-'a';
                c = code+'A';
            }
            else if(c>='A' && c<='Z')
                code=c-'A';
            else if(c>='0' && c<='9')
                code=c-'0'+26;
            else if(c>='_')
                code=36;
            hasIt[code] = true;
            if(inputStr[j]==rawStr[i])
            {
                ++i;
                break;
            }
            if(!badTags[code])
            {
                badTags[code]=true;
                badKeys[badKeyCount++]=c;
            }
            ++i;
        }
    }
    while(i<n1)
    {
        c = rawStr[i];
        if(c>='a' && c<='z')
        {
            code=c-'a';
            c = code+'A';
        }
        else if(c>='A' && c<='Z')
            code=c-'A';
        else if(c>='0' && c<='9')
            code=c-'0'+26;
        else if(c>='_')
            code=36;
        if(hasIt[code])
        {
            ++i;
            continue;
        }
        hasIt[code] = true;
        if(!badTags[code])
        {
            badTags[code]=true;
            badKeys[badKeyCount++]=c;
        }
        ++i;
    }
    for(i=0; i<badKeyCount; ++i)
        std::cout<<badKeys[i];
    std::cout<<std::endl;
    return 0;
}
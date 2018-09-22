#include <iostream>
#include <cstring>
#include <memory>
#include <string>

/*
输入样例：
4
10120150912233 2 4
10120150912119 4 1
10120150912126 1 3
10120150912002 3 2
2
3 4
输出样例：
10120150912002 2
10120150912119 1
*/

int main()
{
    int i, counts[26], maxCount=0;
    const int LEN=1001;
    char str[LEN], *p;

    memset(counts, 0, sizeof(int)*26);

    std::cin.getline(str, LEN);
    p = str;
    while((*p)!='\0')
    {
        if((*p)>='a' && (*p)<='z')
        {
            ++counts[(*p)-'a'];
            if(maxCount<counts[(*p)-'a'])
                maxCount=counts[(*p)-'a'];
        }
        else if((*p)>='A' && (*p)<='Z')
        {
            ++counts[(*p)-'A'];
            if(maxCount<counts[(*p)-'A'])
                maxCount=counts[(*p)-'A'];
        }
        ++p;
    }

    for(i=0; i<26; ++i)
    {
        if(maxCount==counts[i])
        {
            std::cout<<char('a'+i)<<" "<<maxCount<<std::endl;
            break;
        }
    }


    return 0;
}
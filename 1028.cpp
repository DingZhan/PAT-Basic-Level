#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

/*
    2014年9月6日
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John
*/

int main()
{
    int year, month, day;
    int youngCode=2014*10000+9*100+7;
    int oldCode=1814*10000+9*100+5;
    int curOldCode = oldCode, curYoungCode = youngCode;
    std::string oldName, youngName, name;
    int n, i, code, count=0;
    char c;

    std::cin>>n;
    for(i=0; i<n; ++i)
    {
        std::cin>>name;
        std::cin>>year>>c>>month>>c>>day;
        code = year*10000+month*100+day;
        if(code>=youngCode || code<=oldCode)
            continue;
        ++count;
        if(count==1)
        {
            if(code<curYoungCode && code>=curOldCode)
            {
                curYoungCode = code;
                youngName = name;
            }
            if(code>curOldCode && curYoungCode>=code)
            {
                curOldCode = code;
                oldName = name;
            }
        }
        else
        {
            if(code>curYoungCode)
            {
                curYoungCode = code;
                youngName = name;
            }
            else if(code<curOldCode)
            {
                curOldCode = code;
                oldName = name;
            }
        }
//        John 2001/05/12
    }

    if(count==0)
    {
        std::cout<<"0"<<std::endl;
    }
    else
        std::cout<<count<<" "<<oldName<<" "<<youngName<<std::endl;
    return 0;
}
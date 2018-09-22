#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <set>
/*
输入样例：
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
输出样例：
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John

*/

int main()
{
    int N, K, m, i, h, curHeight, j;
    std::string str;
    char name[10];
    const int MAX_HEIGHT = 301;
    const int MIN_HEIGHT = 30;
    std::set<std::string> heights[MAX_HEIGHT];
    std::set<std::string>::iterator it;
    std::vector<std::string> leftNames, printNames;

    std::cin>>N>>K;
    
    for(i=0; i<N; ++i)
    {
        std::cin>>name>>h;
        heights[h].insert(name);
    }
    curHeight = MAX_HEIGHT-1;
    for(j=K-1; j>=0; --j)
    {
        if(j==K-1)
            m = N-N/K*(K-1);
        else
            m = N/K;
        printNames.resize(m);
        while(leftNames.size()<printNames.size())
        {
            for(it=heights[curHeight].begin(); it!=heights[curHeight].end(); ++it)
                leftNames.push_back(*it);
            --curHeight;
        }
        if(m%2==0)
        {
            for(i=0; i<m/2; ++i)
                printNames[i] = leftNames[m-1-2*i];
            for(i=m/2; i<m; ++i)
                printNames[i] = leftNames[m-1-(2*(m-i)-1)];
        }
        else
        {
            for(i=0; i<m/2; ++i)
                printNames[i] = leftNames[m-1-(2*i+1)];
            for(i=m/2; i<m; ++i)
                printNames[i] = leftNames[m-1-2*(m-1-i)];
        }
        leftNames.erase(leftNames.begin(), leftNames.begin()+m);
        for(i=0; i<(int)printNames.size(); ++i)
        {
            std::cout<<printNames[i];
            if(i+1==printNames.size())
                std::cout<<std::endl;
            else
                std::cout<<" ";
        }
    }
 
    return 0;
}
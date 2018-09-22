#include <iostream>
#include <cstring>


/*
输入样例：
5
8 10 9 12
5 10 5 10
3 8 5 12
12 18 1 13
4 16 12 15
输出样例：
1 2
*/

int main()
{
    int callNum1, callNum2, sumNum1, sumNum2, sum;
    int N, i, lostCount1=0, lostCount2=0;
    bool bWin1,bWin2;
    std::cin>>N;

    for(i=0; i<N; ++i)
    {
        std::cin>>callNum1>>sumNum1>>callNum2>>sumNum2;
        sum = callNum1+callNum2;
        bWin1 = (sumNum1==(callNum1+callNum2));
        bWin2 = (sumNum2==(callNum1+callNum2));
        if(bWin1==bWin2)
            continue;
        if(!bWin1)
            ++lostCount1;
        else
            ++lostCount2;
    }

    std::cout<<lostCount1<<" "<<lostCount2<<std::endl;

    return 0;
}
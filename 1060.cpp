#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

/*
输入样例：
10
6 7 6 9 3 10 8 2 7 8
输出样例：
6
*/

int main()
{
    const int LEN=100002;
    int N, i, k, *miles, j, *datas;

    std::cin>>N;
    miles = new int[LEN];
    datas = new int[N];
    memset(miles, 0, sizeof(int)*LEN);
    for(i=0; i<N; ++i)
    {
        std::cin>>j;
        if(j>=LEN)
            j = LEN-1;
        ++miles[j];
    }
    j=0;
    for(i=LEN-1; i>=0; --i)
    {
        if(miles[i])
        {
            for(k=0; k<miles[i]; ++k)
                datas[j++] = i;
        }
    }
    for(i=N; i>=1; --i)
    {
        if(datas[i-1]>i)
        {
            break;
        }
    }
    std::cout<<i<<std::endl;
    delete[] datas;
    delete[] miles;
    return 0;
}
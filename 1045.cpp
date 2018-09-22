#include <iostream>
#include <cstring>
#include <memory>
#include <string>
#include <set>

/*
这一题Judge系统是错的，在结果为0的情况下多输出了一个回车键
输入样例：
5
1 3 2 4 5
输出样例：
3
1 4 5
*/

int main()
{
    int N, i, L;
    bool *bSuccTags;
    unsigned int* datas, v, curMin=1000000001, curMax=0;
    std::set<unsigned int> dataSets;
    std::set<unsigned int>::iterator it;

    std::cin>>N;
    bSuccTags = new bool[N];
    datas = new unsigned int[N];
    for(i=0; i<N; ++i)
    {
        bSuccTags[i] = true;
        std::cin>>v;
        datas[i] = v;
        if(v>curMax)
            curMax=v;
        else if(v<curMax)
            bSuccTags[i]=false;
    }

    for(i=N-1; i>=0; --i)
    {
        v = datas[i];
        if(v<curMin)
            curMin=v;
        else if(v>curMin)
            bSuccTags[i]=false;
    }
    
    for(i=0; i<N; ++i)
    {
        if(bSuccTags[i])
            dataSets.insert(datas[i]);
    }

    std::cout<<dataSets.size()<<std::endl;
    i=0;
    L = dataSets.size();
    for(it=dataSets.begin(); it!=dataSets.end(); ++it)
    {
        std::cout<<*it;
        if(i!=L-1)
            std::cout<<" ";
        ++i;
    }
    std::cout<<std::endl;
    delete[] bSuccTags;
    delete[] datas;

    return 0;
}
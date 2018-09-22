#include <iostream>
#include <iomanip>
/*
����������
5 0.5 10
6 0.3 0.4 0.5 0.2 0.8 0.6
10 0.0 0.1 0.2 0.3 0.0 0.8 0.6 0.7 0.0 0.5
5 0.4 0.3 0.5 0.1 0.7
11 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1
11 2 2 2 1 1 0.1 1 0.1 0.1 0.1 0.1
���������
40.0% 20.0%
���������ͣ���2��3��Ϊ�����ܿ��á�����4��Ϊ�����á������������ǿ��á���
*/

int main()
{
    int N, D, K, i, j, count;
    float e, ei;
    int totalEmpty=0, maybeEmpty=0;

    std::cin>>N>>e>>D;
    for(i=0; i<N; ++i)
    {
        std::cin>>K;
        count=0;
        for(j=0; j<K; ++j)
        {
            std::cin>>ei;
            if(ei<e)
                ++count;
        }
        if(count>K-count)
        {
            if(K>D)
                ++totalEmpty;
            else
                ++maybeEmpty;
        }
    }
    std::cout<<std::fixed<<std::setprecision(1)<<maybeEmpty*100.0/N<<"% ";
    std::cout<<std::fixed<<std::setprecision(1)<<totalEmpty*100.0/N<<"%"<<std::endl;
    return 0;
}
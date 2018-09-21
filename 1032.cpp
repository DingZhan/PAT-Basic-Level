#include <iostream>
#include <cstring>
#include <memory>

/*
����������
6
3 65
2 80
1 100
2 70
3 40
3 0
���������
2 150

*/

int main()
{
    int N, ID, i, value, *values, maxV=-1, maxID=-1;

    std::cin>>N;

    values = new int[N];
    memset(values, 0, sizeof(int)*N);
    for(i=0; i<N; ++i)
    {
        std::cin>>ID>>value;
        values[ID]+=value;
        if(values[ID]>maxV)
        {
            maxV = values[ID];
            maxID = ID;
        }
    }
    delete[] values;
    std::cout<<maxID<<" "<<maxV<<std::endl;
    return 0;
}
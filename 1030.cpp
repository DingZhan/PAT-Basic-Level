#include <iostream>
#include <cstring>
#include <algorithm>

/*
10 8
2 3 20 4 5 1 6 7 8 9
Êä³öÑùÀý£º
8
*/

int main()
{
    int N, i, j, maxCount=1, high, low, middle, lastSuccID;
    int *arrays;
    long long data, p;

    std::cin>>N>>p;
    arrays = new int[N];
    for(i=0; i<N; ++i)
        std::cin>>arrays[i];

    std::sort(arrays, arrays+N);

    for(i=0; i<N-maxCount; ++i)
    {
        //since it's sorted, use binary search
        low = i;
        high = N-1;
        data = arrays[i]*p;
        middle = (high+low)/2;
        lastSuccID = -1;
        while(low<high)
        {
            if(arrays[middle]>data)
                high = middle;
            else if(arrays[middle]<data)
            {
                low = middle;
                lastSuccID = middle;
            }
            else if(arrays[middle]==data)
            {
                lastSuccID = middle;
                break;
            }
            middle = (high+low)/2;
            if(low==middle)
            {
                if(low<high && arrays[high]<=data)
                    lastSuccID = high;
                break;
            }
        }
        
        if(lastSuccID>0)
        {
            if(lastSuccID-i+1>maxCount)
                maxCount = lastSuccID-i+1;
        }        

    }

    delete[] arrays;
    std::cout<<maxCount<<std::endl;
    return 0;
}
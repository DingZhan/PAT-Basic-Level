#include <iostream>
#include <cmath>

void ShiftData(int data[], int n, int m)
{
    int i, j, t, p, lt, limit;
    m = m%n;
    limit = m;
    if(limit>n-limit)
        limit = n-limit;
    for(i=0; i<limit; ++i)
    {
        j=i;
        p = (j+m)%n;
        lt = data[j];
        while(p!=i)
        {
            t = data[p];
            data[p] = lt;
            j = p;
            p=(p+m)%n;
            lt = t;
            t = data[p];
        }
        data[p] = lt;
    }
}

int main()
{
    int n, m, data[100], i;
    
    std::cin>>n>>m;
    for(i=0; i<n; ++i)
        std::cin>>data[i];
    /*
    n = 6;
    m = 6;
    for(i=0; i<n; ++i)
        data[i] = i+1;
    */

    ShiftData(data, n, m);
    for(i=0; i<n; ++i)
    {
        std::cout<<data[i];
        if(i!=n-1)
            std::cout<<' ';
        else
            std::cout<<std::endl;
    }
    return 0;
}
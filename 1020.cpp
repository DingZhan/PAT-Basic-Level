#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
/*
3 20
18 15 10
75 72 45
*/
int main()
{
    int N, D, i, j;
    double *stores, *sumProfits;
    double price;
    std::cin>>N>>D;

    stores = new double[N];
    sumProfits = new double[N];
    for(i=0; i<N; ++i)
        std::cin>>stores[i];
    for(i=0; i<N; ++i)
        std::cin>>sumProfits[i];
    for(i=0; i<N; ++i)
    {
        if(stores[i]<=0)
            continue;
        price = sumProfits[i]/(stores[i]+0.0);
        for(j=i+1; j<N; ++j)
        {
            if(sumProfits[j]/(stores[j]+0.0)>price)
            {
                price = sumProfits[j]/(stores[j]+0.0);
                std::swap(stores[i], stores[j]);
                std::swap(sumProfits[i], sumProfits[j]);
            }
        }
    }
    price = 0.0;
    for(i=0, j=0; i<N; ++i)
    {
        if(stores[i]<=0)
            continue;
        if(stores[i]+j<D)
        {
            price+=sumProfits[i];
            j+=stores[i];
        }
        else
        {
            price+=sumProfits[i]*(D-j+0.0)/stores[i];
            break;
        }
    }
    delete[] stores;
    delete[] sumProfits;
    std::cout<<std::fixed<<std::setprecision(2)<<price<<std::endl;
    return 0;
}
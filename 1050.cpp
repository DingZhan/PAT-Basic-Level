#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>

/*
m*n等于N；m>=n；且m-n取所有可能值中的最小值。

输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：
98 95 93
42 37 81
53 20 76
58 60 76
*/

int main()
{
    int N, i, j, m, n, v, k, row, column;
    const int MAX_LEN = 10001;
    int counts[MAX_LEN]={0}, *datas;
    int xSteps[]={0, 1, 0, -1};
    int ySteps[]={1, 0, -1, 0};
    int direction = 0;
    int **results;

    std::cin>>N;
    n = (int)sqrt(N+0.0);
    for(;n>=1; --n)
    {
        if(N%n==0)
            break;
    }
    m=N/n;

    for(i=0; i<N; ++i)
    {
        std::cin>>v;
        ++counts[v];
    }
    datas = new int[N];
    k=0;
    for(i=MAX_LEN-1; i>=0; --i)
    {
        if(counts[i])
        {
            for(j=0; j<counts[i]; ++j)
                datas[k++] = i;
        }
    }
    //test
    /*
    for(i=0; i<N; ++i)
        std::cout<<datas[i]<<" ";
    std::cout<<std::endl;
    */
    results = new int*[m];
    for(i=0; i<m; ++i)
        results[i] = new int[n];

    //rotate
    row=m;
    column=n+1;
    direction=0;
    i=0;
    j=-1;
    v = 0;
    while(row>1 || column>1)
    {
        if(direction==0 || direction==2)
        {
            column--;
            k=column;
        }
        else if(direction==1||direction==3)
        {
            row--;
            k=row;
        }
        if(k==0)
            break;
        while(k>0)
        {
            --k;
            i+=xSteps[direction];
            j+=ySteps[direction];
            results[i][j] = datas[v++];
        }
        direction=(direction+1)%4;
    }
//    std::cout<<std::fixed<<std::setprecision(2)<<sum<<std::endl;
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            std::cout<<results[i][j];
            if(j==n-1)
                std::cout<<std::endl;
            else
                std::cout<<" ";
        }
    }
    delete[] datas;
    for(i=0; i<m; ++i)
        delete[] results[i];
    delete[] results;
    return 0;
}
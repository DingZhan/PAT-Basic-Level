#include <iostream>
#include <cstring>


/*
输入样例1：
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
输出样例1：
12010X198901011234
110108196711301866
37070419881216001X
输入样例2：
2
320124198808240056
110108196711301862
输出样例2：
All passed

*/

int main()
{
    char (*IDs)[19];
    int N, W, i, j, succCount=0;
    int weights[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int M[]={'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    bool bSucc;

    std::cin>>N;
    IDs = new char[N][19];
    for(i=0; i<N; ++i)
    {
        std::cin>>IDs[i];
    }

    for(i=0; i<N; ++i)
    {
        bSucc=true;
        W = 0;
        for(j=0; j<17; ++j)
        {
            if(IDs[i][j]<'0'||IDs[i][j]>'9')
            {
                bSucc=false;
                break;
            }
            W+=(IDs[i][j]-'0')*weights[j];
        }
        if(!bSucc)
            std::cout<<IDs[i]<<std::endl;
        else
        {
            W=W%11;
            if(M[W]!=IDs[i][17])
                std::cout<<IDs[i]<<std::endl;
            else
                ++succCount;
        }
    }
    delete[] IDs;
    if(succCount==N)
    {
        std::cout<<"All passed"<<std::endl;
    }
    return 0;
}
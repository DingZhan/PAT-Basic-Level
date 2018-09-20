#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cmath>
/*
输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/
struct Data
{
    long code;
    int ID;
};
int compareDouble(const void* a, const void* b)
{
    Data* da = (Data*)a;
    Data* db = (Data*)b;
    if(da->code>db->code)
        return -1;
    else if(da->code<db->code)
        return 1;
    else if(da->ID>db->ID)
        return 1;
    else
        return -1;
}
int main()
{
    int N, Ns[4]={0}, L, H, ID, G, T, i, j, W, index, ids[4]={0};
    short *tags;
    Data *datas=NULL, *datass[4]={NULL};
    //two overtime loss, so I have to disable synchronize
    //this statement is most important, and it must locate before any cin or cout calling
    std::ios::sync_with_stdio(false);
    std::cin>>N>>L>>H;
    datas = new Data[N];
    tags = new short[N];
    for(i=0, j=0; i<N; ++i, ++j)
    {
        std::cin>>ID>>G>>T;
        datas[j].code = (T+G)*1000+G;
        datas[j].ID = ID;
        if(G>=H && T>=H)
        {
            ++Ns[0];
            tags[j] = 0;
        }
        else if(G>=H && T>=L)
        {
            ++Ns[1];
            tags[j] = 1;
        }
        else if(G>=L && T>=L && G>=T)
        {
            ++Ns[2];
            tags[j] = 2;
        }
        else if(G>=L && T>=L)
        {
            ++Ns[3];
            tags[j] = 3;
        }
        else
        {
            --j;
            continue;
        }
    }
    for(i=0; i<4; ++i)
        datass[i] = new Data[Ns[i]];
    for(i=0; i<j; ++i)
    {
        index  = tags[i];
        datass[index][ids[index]++] = datas[i];
    }
    delete[] datas;
    std::cout<<j<<std::endl;

    for(i=0; i<4; ++i)
    {
        if(Ns[i]>0)
        {
            qsort(datass[i], Ns[i], sizeof(Data), compareDouble);
        }
    }
    for(i=0; i<4; ++i)
    {
        for(j=0; j<Ns[i]; ++j)
        {
            ID = datass[i][j].ID;
            W = datass[i][j].code/1000;
            G = datass[i][j].code-W*1000;
            T = W-G;
            /**********************************
            here if I use std::endl, it will produce time overlimit loss,
            so I replace "endl" by "\n", it works well now.
            ***********************************/
            std::cout<<ID<<" "<<G<<" "<<T<<"\n";
        }
    }
    delete[] datass[0];
    delete[] datass[1];
    delete[] datass[2];
    delete[] datass[3];
    return 0;
}

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
/*
输入样例：
4 2
2333 6666
CYLL 3 1234 2345 3456
U 4 9966 6666 8888 6666
GG 2 2333 7777
JJ 3 0012 6666 2333
输出样例：
U: 6666 6666
GG: 2333
JJ: 6666 2333
3 5
*/
#define MAX_GOODS 10000
#define MAX_K 11
int main()
{
    int N, M, i,j,id, K, forbidenGoods[MAX_K], forbidenGoodsCount, tatalStudentsNum=0, tatalCount=0;
    bool forbidenGoodTags[MAX_GOODS]={false};
    char name[5];
    cin>>N>>M;
    for(i=0; i<M; ++i)
    {
        cin>>id;
        forbidenGoodTags[id] = true;
    }
    for(i=0; i<N; ++i)
    {
        cin>>name>>K;
        forbidenGoodsCount = 0;
        for(j=0; j<K; ++j)
        {
            cin>>id;
            if(forbidenGoodTags[id])
                forbidenGoods[forbidenGoodsCount++] = id;
        }
        if(forbidenGoodsCount)
        {
            cout<<name<<":";
            for(j=0; j<forbidenGoodsCount; ++j)
                cout<<" "<<setw(4)<<setfill('0')<<forbidenGoods[j];
            cout<<endl;
            tatalCount+=forbidenGoodsCount;
            ++tatalStudentsNum;
        }
    }
    cout<<tatalStudentsNum<<" "<<tatalCount;
    //system("pause");
    return 0;
}

#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

/*
输入样例：
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
输出样例：
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?
*/

int main()
{
    const int MAX_NUM=10001;
    int rank[MAX_NUM]={0};
    int N, K, i,j, k, ID, *searchResult;
    char (*IDs)[5];

    std::cin>>N;
    for(i=0; i<N; ++i)
    {
        std::cin>>ID;
        rank[ID]=i+1;
    }
    std::cin>>K;
    searchResult = new int[K];
    IDs = new char[K][5];
    for(i=0; i<K; ++i)
    {
        std::cin>>IDs[i];
        ID = atoi(IDs[i]);
        if(ID>=MAX_NUM)
            searchResult[i] = -1; //kidding
        else if(rank[ID]==0)
            searchResult[i] = -1; //kidding
        else if(rank[ID]==-2)//checked
            searchResult[i] = 3; //kidding
        else if(rank[ID]==1)
        {
            searchResult[i] = 0; //mystery
            rank[ID]=-2;
        }
        else
        {
            j = rank[ID];
            rank[ID]=-2;
            k = (int)sqrt(j+0.0);
            while(k>1)
            {
                if(j%k==0)
                    break;
                --k;
            }
            if(k>1)
                searchResult[i] = 2; //Chocolate;
            else
                searchResult[i] = 1; //minion;
        }
    }


    for(i=0; i<K; ++i)
    {
        switch(searchResult[i])
        {
        case -1:
            std::cout<<IDs[i]<<": Are you kidding?"<<std::endl;
            break;
        case 0:
            std::cout<<IDs[i]<<": Mystery Award"<<std::endl;
            break;
        case 1:
            std::cout<<IDs[i]<<": Minion"<<std::endl;
            break;
        case 2:
            std::cout<<IDs[i]<<": Chocolate"<<std::endl;
            break;
        case 3:
            std::cout<<IDs[i]<<": Checked"<<std::endl;
            break;
        default:
            break;
        }
    }
    delete[] IDs;
    delete[] searchResult;
    return 0;
}
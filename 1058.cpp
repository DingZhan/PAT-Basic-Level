#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>

/*
输入样例：
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
输出样例：
3
6
5
2 2 3 4
*/

int main()
{
    const int MAX_QUESTION=100;
    int N, M, i,j, v,maxWrongNum=0;
    int wrongNums[MAX_QUESTION]={0};
    int questions[MAX_QUESTION][4];
    int *scores, answer;
    char c;
    std::string str;

    std::cin>>N>>M;
    scores = new int[N];
    for(i=0; i<M; ++i)
    {
        std::cin>>questions[i][0]>>questions[i][1]>>questions[i][2];
        questions[i][3]=0;
        for(j=0; j<questions[i][2]; ++j)
        {
            std::cin>>c;
            questions[i][3]|=(1<<(c-'a'+1));
        }
    }

    std::getline(std::cin, str);

    for(i=0; i<N; ++i)
    {
        scores[i] = 0;
        std::getline(std::cin, str);
        j=0;
        v=0;
        while(j<str.size())
        {
            c = str[j];
            if(c=='(')
            {
                answer = 0;
                do
                {
                    ++j;
                    if(j>=str.size())
                        break;
                    c = str[j];
                    if(c>='a' && c<='z')
                        answer|=(1<<(c-'a'+1));
                }while(c!=')');
                if(answer==questions[v][3])
                    scores[i]+=questions[v][0];
                else
                    ++wrongNums[v];
                ++v;
            }
            ++j;
        }
    }

    for(i=0; i<M; ++i)
    {
        if(wrongNums[i]>maxWrongNum)
            maxWrongNum = wrongNums[i];
    }
    for(i=0; i<N; ++i)
        std::cout<<scores[i]<<std::endl;

    if(maxWrongNum==0)
    {
        std::cout<<"Too simple"<<std::endl;
    }
    else
    {
        std::cout<<maxWrongNum<<" ";
        for(i=0, j=0; i<M; ++i)
        {
            if(wrongNums[i]==maxWrongNum)
            {
                if(j!=0)
                    std::cout<<" ";
                std::cout<<i+1;
                ++j;
            }
        }
        std::cout<<std::endl;
    } 
    delete[] scores;
    return 0;
}
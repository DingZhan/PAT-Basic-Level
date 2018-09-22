#include <iostream>
#include <cstring>

/*
输入样例：
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
输出样例：
11 176
*/

int main()
{
    int N, i, teamID, memID, score, scores[10000]={0}, maxScore=0, maxTeamID=-1;
    char c;
    std::cin>>N;

    for(i=0; i<N; ++i)
    {
        std::cin>>teamID>>c>>memID>>score;
        scores[teamID]+=score;
        if(scores[teamID]>maxScore)
        {
            maxScore = scores[teamID];
            maxTeamID = teamID;
        }
    }

    std::cout<<maxTeamID<<" "<<scores[maxTeamID]<<std::endl;

    return 0;
}
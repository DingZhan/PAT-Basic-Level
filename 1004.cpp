#include <iostream>
#include <string>

int main()
{
    int n, score, minScore=101, maxScore=-1;
    char buffer[128], buffer2[128];
    std::string maxScoreName, maxScoreClass, minScoreName, minScoreClass;
    std::cin>>n;
    while(n>0)
    {
        std::cin>>buffer>>buffer2>>score;
        if(score>maxScore)
        {
            maxScore  = score;
            maxScoreName = buffer;
            maxScoreClass = buffer2;
        }
        if(score<minScore)
        {
            minScore  = score;
            minScoreName = buffer;
            minScoreClass = buffer2;
        }
        --n;
    }
    std::cout<<maxScoreName<<" "<<maxScoreClass<<std::endl;
    std::cout<<minScoreName<<" "<<minScoreClass<<std::endl;
    return 0;
}

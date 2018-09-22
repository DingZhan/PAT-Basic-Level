#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
/*
输入样例1：
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)
输出样例1：
3.5
6.0
2.5
2 2-e
2 3-a
2 3-b
输入样例2：
2 2
3 4 2 a c
2 5 1 b
(2 a c) (1 b)
(2 a c) (1 b)
输出样例2：
5.0
5.0
Too simple
*/
#define MAX_M 101
#define MAX_OPTIONS 5
#define MAX_N 1001

int main()
{
    int N, M, i, j, k, optionNum, fullScores[MAX_M], optionNums[MAX_M], correctOptionNums[MAX_M];
    bool correctOptions[MAX_M][MAX_OPTIONS]={false};
    int errorOptions[MAX_M][MAX_OPTIONS]={0};
    int errorStudentOption=0;
    char option, parenthesis;
    float point, points[MAX_N];
    cin>>N>>M;
    for(i=0; i<M; ++i)
    {
        cin>>fullScores[i]>>optionNums[i]>>correctOptionNums[i];
        for(j=0; j<correctOptionNums[i]; ++j)
        {
            cin>>option;
            correctOptions[i][option-'a'] = true;
        }
    }
    for(i=0; i<N; ++i)// student i
    {
        point = 0;
        for(j=0; j<M; ++j) //question j
        {
            cin>>parenthesis>>optionNum;
            bool bHasWrong=false, bTotalWrong=false;
            bool myOptions[MAX_OPTIONS]={false};
            for(k=0; k<optionNum; ++k)
            {
                cin>>option;
                myOptions[option-'a'] = true;
            }
            for(k=0; k<MAX_OPTIONS; ++k)
            {
                //choose it and it's correct, don't choose it and it's wrong
                if(myOptions[k] && correctOptions[j][k]||
                   !myOptions[k] && !correctOptions[j][k])
                {
                }
                else
                {
                    if(myOptions[k] && !correctOptions[j][k])
                        bTotalWrong = true;
                    ++errorOptions[j][k];
                    if(errorOptions[j][k]>errorStudentOption)
                        errorStudentOption = errorOptions[j][k];
                    bHasWrong=true;
                }
            }
            cin.ignore();
            if(bHasWrong) //0 point
            {
                if(!bTotalWrong)
                    point+=fullScores[j]*0.5;
            }
            else
            {
                point+=fullScores[j];
            }
        }
        points[i] = point;
    }

    for(i=0; i<N; ++i)
        cout<<fixed<<setprecision(1)<<points[i]<<endl;
    if(errorStudentOption==0)
        cout<<"Too simple"<<endl;
    else
    {
        for(i=0; i<M; ++i )
        {
            for(j=0; j<optionNums[i]; ++j)
            {
                if(errorOptions[i][j]==errorStudentOption)
                {
                    cout<<errorStudentOption<<" "<<i+1<<"-";
                    cout<<(char)('a'+j)<<endl;
                }
            }
        }
    }
//    system("pause");
    return 0;
}

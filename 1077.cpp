#include <iostream>
#include <vector>

using namespace std;

int main()
{
    double G1, G2, G, minG, maxG;
    int N, M, i, j, validNum;
    vector<int> scores;

    cin>>N>>M;
    scores.resize(N);
    for(i=0; i<N;++i)
    {
        cin>>G2;
        G1 = 0.0;
        validNum = 0;
        for(j=1; j<N; ++j)
        {
            cin>>G;
            if(G>=0 && G<=M)
            {
                G1+=G;
                ++validNum;
                if(validNum==1)
                {
                    minG = maxG = G;
                }
                else
                {
                    if(minG>G)
                        minG = G;
                    else if(maxG<G)
                        maxG = G;
                }
            }
        }
        G1=(G1-maxG-minG)/(validNum-2);
        G = (G1+G2)*0.5;
        scores[i] = (int)(G+0.5);
    }
    for(i=0; i<N; ++i)
        cout<<scores[i]<<"\n";
    return 0;
}

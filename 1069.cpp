#include <iostream>
#include <cstdlib>

using namespace std;

/*
输入样例1：
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
输出样例1：
PickMe
Imgonnawin!
TryAgainAgain
输入样例2：
2 3 5
Imgonnawin!
PickMe
输出样例2：
Keep going...
*/
#define MAX_M 1000
int main()
{
    int M, N, S, i,j;
    std::string names[MAX_M];
    bool bGotGift[MAX_M];
    cin>>M>>N>>S;
	for(i=0; i<M; ++i)
    {
        cin>>names[i];
        bGotGift[i] = false;
    }
    if(S>M)
    {
        cout<<"Keep going..."<<endl;
    }
    else
    {
        for(i=S-1; i<M; )
        {
            if(!bGotGift[i])
            {
                bGotGift[i] = true;
                cout<<names[i]<<endl;
                for(j=i+1; j<M; ++j)
                {
                    if(names[i]==names[j])
                        bGotGift[j] = true;
                }
                i+=N;
            }
            else
                ++i;
        }
    }
//    system("pause");
	return 0;
}

#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
using namespace std;
/*
输入样例1：
8 6 200
0 	 0 	  0 	   0	    0 	     0 	      0        0
65280 	 65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280 	 65280    65280    65280    65280    65280    165280   165280
65280 	 65280 	  16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215
输出样例1：
(5, 3): 16711680
输入样例2：
4 5 2
0 0 0 0
0 0 3 0
0 0 0 0
0 5 0 0
0 0 0 0
输出样例2：
Not Unique
输入样例3：
3 3 5
1 2 3
3 4 5
5 6 7
输出样例3：
Not Exist
*/
const int MAX_LEN=1000;
int image[MAX_LEN][MAX_LEN];
int main()
{
    int m, n, i, j, tol, succCount=0, idM, idN;
    bool bSucc;
    std::map<int, bool> bUniqueMaps;
    std::map<int, bool>::iterator it;
    cin>>m>>n>>tol;
    for(i=0; i<n; ++i)
    {
        for(j=0; j<m; ++j)
        {
            cin>>image[i][j];
            it = bUniqueMaps.find(image[i][j]);
            if(it!=bUniqueMaps.end())
            {
                it->second = false;
            }
            else
                bUniqueMaps[image[i][j]] = true;
        }
    }
    for(i=0; i<n; ++i)
    {
        for(j=0; j<m; ++j)
        {
            if(!bUniqueMaps[image[i][j]])
                continue;
            bSucc=true;
            if(i>0)
            {
                if((j>0 && abs(image[i-1][j-1]-image[i][j])<=tol) || abs(image[i-1][j]-image[i][j])<=tol||
                   (j<n-1 && abs(image[i-1][j+1]-image[i][j])<=tol))
                {
                    bSucc=false;
                }
            }
            if(bSucc)
            {
                if((j>0 && abs(image[i][j-1]-image[i][j])<=tol) || (j<m-1 && abs(image[i][j+1]-image[i][j])<=tol))
                {
                    bSucc=false;
                }
            }
            if(bSucc && i<m-1)
            {
                if((j>0 && abs(image[i+1][j-1]-image[i][j])<=tol) || abs(image[i+1][j]-image[i][j])<=tol||
                   (j<n-1 && abs(image[i+1][j+1]-image[i][j])<=tol))
                {
                    bSucc=false;
                }
            }
            if(bSucc)
            {
                ++succCount;
                idN = i;
                idM = j;
            }
        }
    }
    if(succCount==0)
        cout<<"Not Exist"<<endl;
    else if(succCount==1)
        cout<<"("<<idM+1<<", "<<idN+1<<"): "<<image[idN][idM]<<endl;
    else
        cout<<"Not Unique"<<endl;
    return 0;
}

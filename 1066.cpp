#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/*
输入样例：
3 5 100 150 0
3 189 254 101 119
150 233 151 99 100
88 123 149 0 255
输出样例：
003 189 254 000 000
000 233 151 099 000
088 000 000 000 255
*/
#define MAX_MN 500
int main()
{
    unsigned char image[MAX_MN][MAX_MN],d;
    int M, N, A, B, i,j, t;
    cin>>M>>N>>A>>B>>t;
    d = (unsigned char)t;
	for(i=0; i<M; ++i)
    {
        for(j=0; j<N; ++j)
        {
            cin>>t;
            if(t>=A && t<=B)
                t=d;
            image[i][j] = (unsigned char)t;
        }
    }
   	for(i=0; i<M; ++i)
    {
        for(j=0; j<N; ++j)
        {
            if(j!=0)
                cout<<" ";
            cout<<setw(3)<<setfill('0')<<(int)image[i][j];
        }
        cout<<endl;
    }
 //   system("pause");
	return 0;
}

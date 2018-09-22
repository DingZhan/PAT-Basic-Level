#include <iostream>
#include <cstdlib>
using namespace std;
/*
有个小坑，多个空格
输入样例1：
100 4
8 0 100 2
3 1 50 1
5 1 200 6
7 0 200 8
输出样例1：
Win 100!  Total = 200.
Lose 50.  Total = 150.
Not enough tokens.  Total = 150.
Not enough tokens.  Total = 150.
*/

int main()
{
    int T, K, i, n1, b, t, n2;
    cin>>T>>K;
    for(i=0; i<K; ++i)
    {
        cin>>n1>>b>>t>>n2;
        if(t>T)
        {
            cout<<"Not enough tokens.  Total = "<<T<<"."<<endl;
            continue;
        }
        if((b==0 && n2<n1) || (b==1 && n2>n1))
        {
            T+=t;
            cout<<"Win "<<t<<"!  Total = "<<T<<"."<<endl;
        }
        else
        {
            T-=t;
            cout<<"Lose "<<t<<".  Total = "<<T<<"."<<endl;
            if(T==0)
            {
                cout<<"Game Over."<<endl;
                break;
            }
        }
    }
    //system("pause");
    return 0;
}

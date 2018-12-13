#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX_L 1005
bool IsPrime(int n)
{
    if(n==1)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    int t = sqrt(n);
    int i;
    for(i=3;i<=t; i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    char N[MAX_L], temp[20];
    int L, K, i;
    int n;
    cin>>L>>K;
    cin>>N;
    for(i=0; i<=L-K; ++i)
    {
        strncpy(temp, N+i, K);
        temp[K] = '\0';
        n = atoi(temp);
        if(IsPrime(n))
        {
            cout<<temp<<endl;
            break;
        }
    }
    if(i>L-K)
        cout<<"404"<<endl;
}

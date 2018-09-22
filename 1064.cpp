#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n, numDiffFriends=0, value, sum, i;
    bool friendIDs[37]={false}, bFirst=true;
    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>value;
        sum = 0;
        while(value!=0)
        {
            sum+=value%10;
            value/=10;
        }
        if(!friendIDs[sum])
        {
            friendIDs[sum] = true;
            ++numDiffFriends;
        }
    }
    cout<<numDiffFriends<<endl;
    for(i=0; i<37; ++i)
    {
        if(friendIDs[i])
        {
            if(bFirst)
            {
                cout<<i;
                bFirst = false;
            }
            else
                cout<<" "<<i;
        }
    }
    cout<<endl;
    return 0;
}

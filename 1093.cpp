#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int i, num=0;
    bool bTakens[128]={false};
    char orderStrings[128];
    char c;
    while((c=getchar())!='\n')
    {
        if(bTakens[c])
            continue;
        bTakens[c] = true;
        orderStrings[num++] = c;
    }
    while((c=getchar())!='\n')
    {
        if(bTakens[c])
            continue;
        bTakens[c] = true;
        orderStrings[num++] = c;
    }
    orderStrings[num]= '\0';
    cout<<orderStrings<<endl;
    return 0;
}

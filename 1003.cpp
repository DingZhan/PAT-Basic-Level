#include <iostream>
#include <sstream>

using namespace std;

/*
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
*/

#define N 101
int main()
{
    int num, i, aA=0, bA=0, cA=0, bSucc, bHasP, bHasT;
    bool results[N] = {false};
    char s[N], *p;

    cin>>num;
    for(i=0; i<num; ++i)
    {
        cin>>s;
        bHasP = false;
        bHasT = false;
        p = s;
        bSucc=true;
        aA=0;
        bA=0;
        cA=0;
        while((*p)!='\0')
        {
            if(((*p)!='P') && ((*p)!='A') && ((*p)!='T'))
            {
                bSucc=false;
                break;
            }
            if((*p)=='P')
            {
                if(bHasP)
                {
                    bSucc=false;
                    break;
                }
                bHasP = true;
            }
            else if((*p)=='A')
            {
                if(!bHasP)
                    ++aA;
                else if(bHasP && !bHasT)
                    ++bA;
                else if(bHasT)
                    ++cA;
            }
            else if((*p)=='T')
            {
                if(!bHasP || bHasT)
                {
                    bSucc=false;
                    break;
                }
                bHasT = true;
            }
            ++p;
        }
        if(!bSucc)
            results[i]=false;
        else
        {
            if(!bHasP || !bHasT || bA==0)
                results[i]=false;
            else if(aA==cA && bA==1)
                results[i]=true;
            else
            {
                if(cA==((bA-1)*aA+aA))
                   results[i]=true;
            }
        }
    }
    for(i=0; i<num; ++i)
    {
        cout<<(results[i]?"YES":"NO")<<endl;
    }
    return 0;
}

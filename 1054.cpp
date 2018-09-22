#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>

/*
输入样例1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
输出样例1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
输入样例2：
2
aaa -9999
输出样例2：
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
*/

int main()
{
    int N, K=0, i, k, dotPos;
    size_t j;
    double sum=0.0, v;
    char c;
    bool bHaveDot;
    std::string str, subStr;
    bool bLegals[100]={false};
    std::string allSubStrs[100];
    bool bMakeDotWithoutPrefixLegal = true;

    std::getline(std::cin, str);
    N = atoi(str.c_str());

    i=0;
    j=0;
    k=0;
    bHaveDot=false;
    std::getline(std::cin, str);
    while(j<str.size())
    {
        c = str[j];
        if(c==' ')
        {
            if(i>0)
            {
                //check str;
                allSubStrs[k]= subStr;
                if(i==1 && (subStr[0]<'0'||subStr[0]>'9'))
                    bLegals[k]=false;
                else if(subStr[i-1]=='.' && !(subStr[i-2]>='0' && subStr[i-2]<='9'))
                    bLegals[k]=false;
                else
                {
                    v = atof(subStr.c_str());
                    if((v<-1000 || v>1000) || (bHaveDot && (i-dotPos)>3))
                        bLegals[k]=false;
                    else
                    {
                        bLegals[k]=true;
                        sum+=v;
                        ++K;
                    }
                }
                bHaveDot = false;
                ++k;
                i=0;
                subStr="";
                if(k>=N)
                    break;
            }
        }
        else if(c=='-'||c=='+')
        {
            if(i>0)
                goto _FAILED_;
            else
            {
                subStr.push_back(c);
                i++;
            }
        }
        else if(c=='.')
        {
            if(bHaveDot)
                goto _FAILED_;
            else
            {
                dotPos = i;
                if(dotPos==0 && !bMakeDotWithoutPrefixLegal)
                    goto _FAILED_;
                if(i>0 && (subStr[i-1]<'0' || subStr[i-1]>'9'))
                    goto _FAILED_;
                subStr.push_back(c);
                ++i;
                bHaveDot = true;
            }
        }
        else if(c>='0' && c<='9')
        {
            subStr.push_back(c);
            ++i;
        }
        else
            goto _FAILED_;
        ++j;
        continue;

_FAILED_:
        //illegal
        while(j<str.size())
        {
            if(str[j]==' ')
                break;
            subStr.push_back(str[j]);
            ++i;
            ++j;
        }
        allSubStrs[k]= subStr;
        i=0;
        subStr="";
        bLegals[k]=false;
        bHaveDot =false;
        ++k;
        if(k>=N)
            break;
    }
    if(i>0)
    {
        allSubStrs[k]= subStr;

        if(i==1 && (subStr[0]<'0'||subStr[0]>'9'))
            bLegals[k]=false;
        else if(subStr[i-1]=='.' && !(subStr[i-2]>='0' && subStr[i-2]<='9'))
            bLegals[k]=false;
        else
        {
            v = atof(subStr.c_str());
            if((v<-1000 || v>1000) || (bHaveDot && (i-dotPos)>3))
                bLegals[k]=false;
            else
            {
                bLegals[k]=true;
                sum+=v;
                ++K;
            }
        }
        ++k;
        subStr="";
    }
    for(i=0; i<N; ++i)
    {
        if(!bLegals[i])
            std::cout<<"ERROR: "<<allSubStrs[i]<<" is not a legal number"<<std::endl;
        else
            subStr = allSubStrs[i];
    }
    if(K==0)
        std::cout<<"The average of 0 numbers is Undefined"<<std::endl;
    else if(K==1)
        std::cout<<std::fixed<<std::setprecision(2)<<"The average of 1 number is "<<sum<<std::endl;
    else
        std::cout<<std::fixed<<std::setprecision(2)<<"The average of "<<K<<" numbers is "<<sum/K<<std::endl;
    return 0;
}
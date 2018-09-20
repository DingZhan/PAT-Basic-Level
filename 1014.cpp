#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

int main()
{
    std::string str1, str2, str3, str4;
    size_t i, thirdPos, count;
    char sameStrs[3];

    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    std::getline(std::cin, str3);
    std::getline(std::cin, str4);

    count = 0;
    for(i=0; i<str1.size() && i<str2.size(); ++i)
    {
        if(str1[i]==str2[i])
        {
//            if(count==0 && (str1[i]>='a' && str1[i]<='g' || str1[i]>='A' && str1[i]<='G' )) 
            if(count==0 && (str1[i]>='A' && str1[i]<='G' )) 
            {
                sameStrs[count] = str1[i];
                ++count;
            }
            else if(count==1 && (str1[i]>='A' && str1[i]<='N'|| str1[i]>='0' && str1[i]<='9'))
            {
                sameStrs[count] = str1[i];
                ++count;
            }
            if(count==2)
                break;
        }
    }
    for(i=0; i<str3.size() && i<str4.size(); ++i)
    {
        if(str3[i]==str4[i] && (str3[i]>='a' && str3[i]<='z' || str3[i]>='A' && str3[i]<='Z') )
        {
            sameStrs[count] = str3[i];
            ++count;
            if(count==3)
            {
                thirdPos = i;
                break;
            }
        }
    }
    if(sameStrs[0]>='A' && sameStrs[0]<='Z')
        i = sameStrs[0]-'A'+1;
    else if(sameStrs[0]>='a' && sameStrs[0]<='z')
        i = sameStrs[0]-'a'+1;
    else if(sameStrs[0]>='1' && sameStrs[0]<='9')
        i = sameStrs[0]-'1'+1;

    switch(i)
    {
    case 1:
        std::cout<<"MON";
        break;
    case 2:
        std::cout<<"TUE";
        break;
    case 3:
        std::cout<<"WED";
        break;
    case 4:
        std::cout<<"THU";
        break;
    case 5:
        std::cout<<"FRI";
        break;
    case 6:
        std::cout<<"SAT";
        break;
    case 7:
        std::cout<<"SUN";
        break;
    default:
        return 0;
        break;
    }
    std::cout<<" ";

    if(sameStrs[1]>='A' && sameStrs[1]<='Z')
        i = sameStrs[1]-'A'+10;
    else if(sameStrs[1]>='a' && sameStrs[1]<='z')
        i = sameStrs[1]-'a'+10;
    else if(sameStrs[1]>='0' && sameStrs[1]<='9')
        i = sameStrs[1]-'0';

    if(i<10)
        std::cout<<'0';
    std::cout<<i<<":";

    if(thirdPos<10)
        std::cout<<'0';
    std::cout<<thirdPos<<std::endl;
    
    return 0;
}
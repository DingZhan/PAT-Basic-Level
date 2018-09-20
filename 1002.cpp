#include <iostream>
#include <string>

std::string Calculate(const std::string&  data)
{
    int result = 0, s;
    std::string::const_iterator it;
    for(it=data.begin(); it!=data.end(); ++it)
    {
        if(isdigit(*it))
            result+=*it-'0';
    }
    std::string resultStr2, resultStr;
    if(result==0)
    {
        resultStr2.push_back('0');
    }
    else
    {
        while(result>0)
        {
            s = result%10;
            resultStr2.push_back(s-0+'0');
            result = result/10;
        }
    }
    for(int i = (int)resultStr2.size()-1; i>=0; --i)
    {
        switch(resultStr2[i])
        {
            case '0': 
                resultStr+="ling";
                break;
            case '1': 
                resultStr+="yi";
                break;
            case '2': 
                resultStr+="er";
                break;
            case '3': 
                resultStr+="san";
                break;
            case '4': 
                resultStr+="si";
                break;
            case '5': 
                resultStr+="wu";
                break;
            case '6': 
                resultStr+="liu";
                break;
            case '7': 
                resultStr+="qi";
                break;
            case '8': 
                resultStr+="ba";
                break;
            case '9': 
                resultStr+="jiu";
                break;
        }
        if(i!=0)
            resultStr+=" ";
    }
    return resultStr;
}

int main()
{
    std::string data;
    std::cin>>data;
//    data="1234567890987654321123456789";
    std::string result= Calculate(data);
    std::cout<<result<<std::endl;
    return 0;
}
#include <iostream>
#include <string>

int main()
{
    int B, R, A2=0;
    std::string A, Q;
    std::string::iterator it;
    std::cin>>A>>B;
//    A = "123456789050987654321";
//    B = 7;

    for(it=A.begin(); it!=A.end(); ++it)
    {
        A2 = A2*10+(*it-'0');
        if(A2<B)
        {
            if(Q.empty())
                continue;
            Q.push_back('0');
        }
        else
        {
            Q.push_back(A2/B+'0');
            A2 = A2%B;
        }
    }
    if(Q.empty())
        Q.push_back('0');
    R = A2;
    std::cout<<Q<<' '<<R<<std::endl;
    return 0;
}
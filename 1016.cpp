#include <iostream>
#include <string>


int main()
{
    int PA=0, PB=0;
    char DA, DB;
    std::string A, B;
    std::string::iterator it;
    std::cin>>A>>DA>>B>>DB;
    for(it=A.begin(); it!=A.end(); ++it)
    {
        if(*it==DA)
            PA=PA*10+DA-'0';
    }
    for(it=B.begin(); it!=B.end(); ++it)
    {
        if(*it==DB)
            PB=PB*10+DB-'0';
    }
    std::cout<<PA+PB<<std::endl;
    return 0;
}
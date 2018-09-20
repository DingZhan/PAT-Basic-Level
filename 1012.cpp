#include <iostream>
#include <iomanip>

/*
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9
*/

int main()
{
    int n, i, a, m;
    int counts[5]= {0}, sums[5]={0};

    std::cin>>n;
    for(i=0; i<n; ++i)
    {
        std::cin>>a;
        m = a%5;
        if(m==0)
        {
            if(a%2==0)
            {
                ++counts[0];
                sums[0]+=a;
            }
        }
        else if(m==1)
        {
            if(counts[1]%2==0)
                sums[1]+=a;
            else
                sums[1]-=a;
            ++counts[1];
        }
        else if(m==2)
            ++counts[2];
        else if(m==3)
        {
            ++counts[3];
            sums[3]+=a;
        }
        else if(m==4)
        {
            if(sums[4]<a)
                sums[4] = a;
            ++counts[4];
        }
    }

    if(counts[0]==0)
        std::cout<<'N';
    else
        std::cout<<sums[0];
    std::cout<<' ';
    if(counts[1]==0)
        std::cout<<'N';
    else
        std::cout<<sums[1];
    std::cout<<' ';
    if(counts[2]==0)
        std::cout<<'N';
    else
        std::cout<<counts[2];
    std::cout<<' ';
    if(counts[3]==0)
        std::cout<<'N';
    else
        std::cout<<std::fixed<<std::setprecision(1)<<sums[3]/(0.0+counts[3]);
    std::cout<<' ';
    if(counts[4]==0)
        std::cout<<'N';
    else
        std::cout<<sums[4];
    std::cout<<std::endl;
    return 0;
}
#include <iostream>
#include <iomanip>

/*
����һϵ�����������밴Ҫ������ֽ��з��࣬���������5�����֣�

A1 = �ܱ�5����������������ż���ĺͣ�
A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��
A3 = ��5������2�����ֵĸ�����
A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
A5 = ��5������4��������������֡�
�����ʽ��

ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��������N��������1000�Ĵ�����������������ּ��Կո�ָ���

�����ʽ��

�Ը�����N��������������ĿҪ�����A1~A5����һ����˳����������ּ��Կո�ָ�������ĩ�����ж���ո�

������ĳһ�����ֲ����ڣ�������Ӧλ�������N����

��������1��
13 1 2 3 4 5 6 7 8 9 10 20 16 18
�������1��
30 11 2 9.7 9
��������2��
8 1 2 4 5 6 7 9 16
�������2��
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
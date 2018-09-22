/*
输入样例：
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
输出样例：
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
    std::string name;
    short score;
};
struct StudentAdv
{
    std::string name;
    short p;
    short m;
    short n;
    short ave;
};
bool CompareName(const Student& a, const Student& b)
{
    return a.name<b.name;
}
bool CompareAdv(const StudentAdv& a, const StudentAdv& b)
{
    if(a.ave>b.ave)
    {
        return true;
    }
    else if(a.ave<b.ave)
    {
        return false;
    }
    else if(a.name<b.name)
        return true;
    else
        return false;
}
#define MAX_N 10001
int main()
{
    int P, M, N, i, j, k, t, ave;
    Student Ps[MAX_N];
    Student Ms[MAX_N];
    Student Ns[MAX_N];
    StudentAdv results[MAX_N];
    cin>>P>>M>>N;
    for(i=0; i<P; ++i)
        cin>>Ps[i].name>>Ps[i].score;
    for(i=0; i<M; ++i)
        cin>>Ms[i].name>>Ms[i].score;
    for(i=0; i<N; ++i)
        cin>>Ns[i].name>>Ns[i].score;
    std::sort(Ps, Ps+P, CompareName);
    std::sort(Ms, Ms+M, CompareName);
    std::sort(Ns, Ns+N, CompareName);

    for(i=0, j=0, k=0, t=0; i<P&&j<M&&k<N; )
    {
        if(Ps[i].score<200)
        {
            ++i;
            continue;
        }
        if(Ps[i].name==Ms[j].name && Ps[i].name==Ns[k].name)
        {
            if(Ms[j].score<Ns[k].score)
                ave = Ns[k].score;
            else
                ave = int (Ms[j].score*0.4 + Ns[k].score*0.6+0.5);
            if(ave<60)
            {
                ++i;
                ++j;
                ++k;
                continue;
            }
            results[t].ave = ave;
            results[t].name = Ps[i].name;
            results[t].p = Ps[i].score;
            results[t].m = Ms[j].score;
            results[t].n = Ns[k].score;
            ++t;
            ++i;
            ++j;
            ++k;
        }
        else if(Ps[i].name==Ns[k].name)
        {
            if(Ms[j].name<Ps[i].name)
            {
                ++j;
                continue;
            }
            else
            {
                ave = Ns[k].score;
                if(ave<60)
                {
                    ++i;
                    ++k;
                    continue;
                }
                results[t].ave = ave;
                results[t].name = Ps[i].name;
                results[t].p = Ps[i].score;
                results[t].m = -1;
                results[t].n = Ns[k].score;
                ++t;
                ++i;
                ++k;
            }
        }
        else if(Ps[i].name<Ns[k].name)
        {
            ++i;
        }
        else if(Ps[i].name>Ns[k].name)
        {
            ++k;
        }
    }
     for(; i<P&&k<N; )
    {
        if(Ps[i].score<200)
        {
            ++i;
            continue;
        }
        if(Ps[i].name==Ns[k].name)
        {
            ave = Ns[k].score;
            if(ave<60)
            {
                ++i;
                ++k;
                continue;
            }
            results[t].ave = ave;
            results[t].name = Ps[i].name;
            results[t].p = Ps[i].score;
            results[t].m = -1;
            results[t].n = Ns[k].score;
            ++t;
            ++i;
            ++k;
        }
        else if(Ps[i].name<Ns[k].name)
        {
            ++i;
        }
        else if(Ps[i].name>Ns[k].name)
        {
            ++k;
        }
    }

    std::sort(results, results+t, CompareAdv);
    for(i=0; i<t; ++i)
    {
        cout<<results[i].name<<" "<<results[i].p<<" "<<results[i].m<<" "<<results[i].n<<" "<<results[i].ave<<endl;
    }
    return 0;
}

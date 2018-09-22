#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
using namespace std;
/*
输入样例：
30527
06203
415
输出样例：
7201
*/

int main()
{
    std::string a, b;
    std::string table, result;
    int i, step=0, value, tableStep;
    cin>>table;
    cin>>a>>b;
    std::reverse(table.begin(), table.end());
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    for(i=0; ; ++i)
    {
        if(i<a.size() && i<b.size())
            value = a[i]-'0'+b[i]-'0'+step;
        else if(i<a.size())
            value = a[i]-'0'+step;
        else if(i<b.size())
            value = b[i]-'0'+step;
        else
            break;
        if(i<table.size())
        {
            tableStep = table[i]-'0';
            if(tableStep==0)
                tableStep = 10;
        }
        else
            tableStep = 10;
        result.push_back((char)('0'+value%tableStep));
        step = value/tableStep;
    }
    if(step!=0)
        result.push_back((char)('0'+step));
    while(result.size() && result[result.size()-1]=='0')
        result.erase(result.end()-1);
    if(result.empty())
        cout<<"0"<<endl;
    else
    {
        std::reverse(result.begin(), result.end());
        cout<<result<<endl;
    }
//    system("pause");
    return 0;
}

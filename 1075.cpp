#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
/*
输入样例：
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
输出样例：
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1
*/
#define MAX_N 100001
#define MAX_K 1001

struct Node{int value; int next;};
int main()
{
    int i, N, K, startAddress, address, negCount=0, midCount=0, posCount=0;
    Node node;
    std::vector<Node> nodes, negNodes, midNodes, posNodes;
    cin>>startAddress>>N>>K;
    nodes.resize(MAX_N);
    for(i=0; i<N; ++i)
    {
        cin>>address>>node.value>>node.next;
        nodes[address]= node;
        if(node.value<0)
            ++negCount;
        else if(node.value<=K)
            ++midCount;
        else
            ++posCount;
    }
    negNodes.reserve(negCount);
    midNodes.reserve(midCount);
    posNodes.reserve(posCount);
    address = startAddress;
    while(address!=-1)
    {
        if(nodes[address].value<0)
        {
            node = nodes[address];
            node.next = address; //here next is itself
            negNodes.push_back(node);
        }
        else if(nodes[address].value<=K)
        {
            node = nodes[address];
            node.next = address; //here next is itself
            midNodes.push_back(node);
        }
        else
        {
            node = nodes[address];
            node.next = address; //here next is itself
            posNodes.push_back(node);
        }
        address = nodes[address].next;
    }
    address = -1;
    for(i=0; i<negNodes.size(); ++i)
    {
        if(address!=-1)
            cout<<" "<<setfill('0')<<setw(5)<<negNodes[i].next<<endl;
        cout<<setfill('0')<<setw(5)<<negNodes[i].next<<" "<<negNodes[i].value;
        address = negNodes[i].next;
    }
    for(i=0; i<midNodes.size(); ++i)
    {
        if(address!=-1)
            cout<<" "<<setfill('0')<<setw(5)<<midNodes[i].next<<endl;
        cout<<setfill('0')<<setw(5)<<midNodes[i].next<<" "<<midNodes[i].value;
        address = midNodes[i].next;
    }
    for(i=0; i<posNodes.size(); ++i)
    {
        if(address!=-1)
            cout<<" "<<setfill('0')<<setw(5)<<posNodes[i].next<<endl;
        cout<<setfill('0')<<setw(5)<<posNodes[i].next<<" "<<posNodes[i].value;
        address = posNodes[i].next;
    }
    cout<<" -1"<<endl;
//    system("pause");
    return 0;
}

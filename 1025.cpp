#include <iostream>
#include <iomanip>
#include <vector>

struct Node
{
    int value;
    int next;
    bool bValid;
    Node()
    {
        bValid = false;
        next = -1;
        value = 0;
    }
};
int main()
{
    int startAddress, address, lastAddress, numNodes, K, i, j,t, realValidNodes;
    Node* nodes = new Node[100000];
    std::cin>>startAddress>>numNodes>>K;
    std::vector<int> addss(K);
    bool bFind=false;

    for(i=0; i<numNodes; ++i)
    {
        std::cin>>address;
        std::cin>>nodes[address].value>>nodes[address].next;
        nodes[address].bValid = true;
        if(address==startAddress)
            bFind = true;
    }

    if(!bFind)
    {
        std::cout<<std::endl;
        return 0;
    }
    //scan for make sure there is only one link list, that means recalculate numNodes if there are multiple link lists
    realValidNodes  = 0;
    address = startAddress;
    while(realValidNodes<numNodes)
    {
        if(!nodes[address].bValid)
            break;
        address = nodes[address].next;
        ++realValidNodes;
    }
    numNodes = realValidNodes;

    address = startAddress;
    lastAddress = address;
    for(i=0; i<numNodes; i+=K)
    {
        if(i+K<=numNodes)
        {
            address = lastAddress;
            for(j=0; j<K; ++j)
            {
                addss[j]=address;
                address = nodes[address].next;
            }
            lastAddress = nodes[addss[K-1]].next;
            for(j=K-1; j>=0; --j)
            {
                address = addss[j];

                if(i!=0 && j==K-1)
                    std::cout<<std::setfill('0')<<std::setw(5)<<addss[j]<<std::endl;
                std::cout<<std::setfill('0')<<std::setw(5)<<address<<" ";
                std::cout<<nodes[address].value<<" ";
                if(j!=0)
                    std::cout<<std::setfill('0')<<std::setw(5)<<addss[j-1]<<std::endl;
            }
        }
    }
    if(numNodes%K!=0)
    {
        t = numNodes-numNodes%K;
        address = lastAddress;
        for(j=t; j<numNodes; ++j)
        {
            if(j==t)
            {
                std::cout<<std::setfill('0')<<std::setw(5)<<address<<std::endl;
            }
            std::cout<<std::setfill('0')<<std::setw(5)<<address<<" ";
            std::cout<<nodes[address].value<<" ";
            if(j==numNodes-1)
                std::cout<<"-1"<<std::endl;
            else
                std::cout<<std::setfill('0')<<std::setw(5)<<nodes[address].next<<std::endl;
            address = nodes[address].next;
        }
    }
    else
        std::cout<<"-1"<<std::endl;

    delete[] nodes;
    return 0;
}


void ReverseSentence(char* str)
{
    int n = strlen(str);
    if(n==0)
        return;
    char *b = str, *e = str+n-1, t, *e2;
    while(b<e)
    {
        t = *b;
        *b = *e;
        *e = t;
        ++b;
        --e;
    }
    b = str;
    while(true)
    {
        e = b+1;
        while((*e)!=' ' && (*e)!='\0')
            ++e;
        --e;
        e2 = e;
        while(b<e)
        {
            t = *b;
            *b = *e;
            *e = t;
            ++b;
            --e;
        }
        b = e2+1;
        if((*b)=='\0')
            break;
        ++b;
    }
}

int main()
{
    char buffer[82];
    
    //="Hello World Here I Come";
    
    std::cin.getline(buffer, 81);

    ReverseSentence(buffer);
    std::cout<<buffer<<std::endl;
    return 0;
}
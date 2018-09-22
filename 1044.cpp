#include <iostream>
#include <cstring>
#include <memory>
#include <string>

/*
输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13
*/

int main()
{
    char *lowStrs[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    char *highStrs[] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    char str[128],str2[128], result[1024]={'\0'};
    int N, i, v, d, l, j;

    std::cin.getline(str, 128);
    N = atoi(str);
    for(j=0; j<N; ++j)
    {
        std::cin.getline(str, 128);
        if(str[0]>='0' && str[0]<='9')
        {
            v=atoi(str);
            if(v==0)
                strcat(result, "tret\n");
            else
            {
                d = v/13;
                l = v%13;
                if(d!=0)
                {
                    strcat(result, highStrs[d]);
                }
                if(l!=0)
                {
                    if(d!=0)
                        strcat(result, " ");
                    strcat(result, lowStrs[l]);
                }
                strcat(result, "\n");
            }
        }
        else
        {
            strcpy(str2, str);
            str2[3]='\0';
            d = 0;
            for(i=1; i<13; ++i)
            {
                if(!strcmp(highStrs[i], str2))
                {
                    d = i;
                    if(str[3]==' ')
                        strcpy(str2, str+4);
                    else
                        str2[0]='\0';
                    break;                
                }
            }
            l=0;
            for(i=0; i<13; ++i)
            {
                if(!strcmp(lowStrs[i], str2))
                {
                    l = i;
                    break;                
                }
            }
            v = d*13+l;
            sprintf(str2, "%d\n", v);
            strcat(result, str2);
        }
    }
 
    std::cout<<result;
    return 0;
}
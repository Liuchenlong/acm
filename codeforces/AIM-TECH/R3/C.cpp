#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;
char str[1000005];
char nxt(char ch)
{
    if(ch=='a')return 'z';
    return ch-1;
}
int main()
{
    scanf("%s",str);
    int len=strlen(str);
    bool flag=0;
    for(int i=0; i<len; i++)
    {
        if(str[i]!='a')
        {
            flag=1;
            for(int j=i; j<len; j++)
            {
                if(str[j]=='a')break;
                str[j]=nxt(str[j]);
            }
            break;
        }
    }
    if(!flag)
    {
        str[len-1]=nxt(str[len-1]);
    }
    printf("%s\n",str);
    return 0;
}

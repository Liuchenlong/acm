#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
char str[105];
bool check(int pos,int len)
{
    if(len%2==1)
        return false;
    if(len==2)
    {
        if(str[pos]=='P'||str[pos+1]=='P')
            return true;
        return false;
    }
    else
    {
        return check(pos,len/2)&&check(pos+len/2,len/2);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int len=strlen(str);
        if(len==1)
            puts("YES");
        else
        {
            if(len%2==1)puts("NO");
            else
            {
                if(check(0,len))
                    puts("YES");
                else
                    puts("NO");
            }
        }
    }
    return 0;
}

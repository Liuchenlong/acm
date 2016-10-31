#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-12
char str[100];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int ans=0;
        scanf("%s",str);
        for(int i=0;str[i];i++)
        {
            if(str[i]=='C')ans+=12;
            if(str[i]=='H')ans++;
            if(str[i]=='O')ans+=16;
        }
        printf("%d\n",ans);
    }
    return 0;
}

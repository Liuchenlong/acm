#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

char str[1000005];
int main()
{
    int dx=0;
    int dy=0;
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]=='L')
            dx--;
        if(str[i]=='R')
            dx++;
        if(str[i]=='U')
            dy++;
        if(str[i]=='D')
            dy--;
    }
    dx=abs(dx);
    dy=abs(dy);
    if((dx+dy)%2==1)
    {
        puts("-1");
    }
    else
    {
        int ans=dx/2+dy/2;
        dx%=2;
        dy%=2;
        if(dx&1)ans++;
        printf("%d\n",ans);
    }
    return 0;
}

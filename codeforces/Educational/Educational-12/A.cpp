#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a,ta;
    int b,tb;
    scanf("%d%d",&a,&ta);
    scanf("%d%d",&b,&tb);
    char str[6];
    scanf("%s",str);
    int h=(str[0]-'0')*10+str[1]-'0';
    int m=(str[3]-'0')*10+str[4]-'0';
    int tim=h*60+m;
    int now=300;
    int ans=0;
    while(now<24*60)
    {
        if(now+tb<=tim)
            ;
        else if(now>=tim+ta)
            ;
        else
            ans++;

        now+=b;
    }
    printf("%d\n",ans);
    return 0;
}

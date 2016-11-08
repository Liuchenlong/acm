#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8

int c,n;
int cnt[200005];
int nxt[200005];
int vnxt[200005];
bool check(int add)
{
    int now=c;
    int pre=c+1;
    bool flag=false;
    while(1)
    {
        int nval=min(vnxt[now],nxt[pre]);
        if(now==0)return true;
        if(now>=add&&nval<add&&!flag)
        {
            flag=true;
            now-=add;
            continue;
        }
        if(nval==-1)return false;
        pre=nval;
        now-=min(cnt[nval],now/nval)*nval;
    }
}
int main()
{
    scanf("%d%d",&c,&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    nxt[0]=-1;
    vnxt[0]=-1;
    for(int i=1;i<=c;i++)
    {
        if(cnt[i])vnxt[i]=i;
        else vnxt[i]=vnxt[i-1];
        if(cnt[i-1])nxt[i]=i-1;
        else nxt[i]=nxt[i-1];
    }
    nxt[c+1]=c;
    for(int i=1;i<=c;i++)
    {
        if(!check(i))
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("Greed is good\n");
    return 0;
}

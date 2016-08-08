#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-9
const double pi=acos(-1.0);
int sg[10005];
int getsg(int x)
{
    if(sg[x]!=-1)return sg[x];
    bool vis[10005]={0};
    for(int i=1;i*2<x;i++)
    {
        vis[getsg(i)^getsg(x-i)]=1;
    }
    for(int i=0;;i++)
    {
        if(vis[i]==0)
        {
            sg[x]=i;
            return sg[x];
        }
    }
}
int main()
{
    memset(sg,-1,sizeof(sg));
    sg[1]=0;
    sg[2]=0;
    for(int i=3;i<=10000;i++)
        sg[i]=getsg(i);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        int ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            ans^=sg[x];
        }
        if(ans)
            printf("Case %d: Alice\n",cas);
        else
            printf("Case %d: Bob\n",cas);
    }
    return 0;
}

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
#define eps 1e-12
int p,q;
int ans;
void dfs(int now,int stop,int cot,int cost)
{
    if(now<=q)
    {
        ans=min(ans,cost+max(0,q-now-stop));
        return ;
    }
    if(now-(1<<cot)<q)
        dfs(now-1,stop+1,1,cost+2);
    dfs(max(now-(1<<cot),0),stop,cot+1,cost+1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ans=1e9;
        scanf("%d%d",&p,&q);
        dfs(p,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}

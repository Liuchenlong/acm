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

const long long mod=1e9+7;
long long C[1005][1005];
void init()
{
    C[0][0]=1;
    for(int i=1;i<=1000;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
}
int father[1005];
vector<int>son[1005];
int siz[1005];
void dfs(int rt)
{
    siz[rt]=1;
    for(int i=0;i<son[rt].size();i++)
    {
        dfs(son[rt][i]);
        siz[rt]+=siz[son[rt][i]];
    }
}
long long dp[1005];
void getdp(int rt)
{
    dp[rt]=1;
    int num=siz[rt]-1;
    for(int i=0;i<son[rt].size();i++)
    {
        getdp(son[rt][i]);
        dp[rt]=dp[rt]*dp[son[rt][i]]%mod*C[num][siz[son[rt][i]]]%mod;
        num-=siz[son[rt][i]];
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            father[i]=-1;
            son[i].clear();
        }
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            father[b]=a;
            son[a].push_back(b);
        }
        int rt=0;
        for(int i=1;i<=n;i++)if(father[i]==-1)rt=i;
        dfs(rt);
        getdp(rt);
        printf("Case %d: %lld\n",cas,dp[rt]);
    }
    return 0;
}

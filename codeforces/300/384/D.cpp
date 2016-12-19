#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
int fa[200005];
vector<int>son[200005];
long long inf=-(200000LL)*(1000000000LL);
long long Max[200005];
long long sum[200005];
void findmax(int rt)
{
    long long ans=inf;
    sum[rt]=a[rt];
    for(int i=0; i<son[rt].size(); i++)
    {
        int nxt=son[rt][i];
        if(fa[rt]==nxt)continue;
        fa[nxt]=rt;
        findmax(nxt);
        ans=max(ans,Max[nxt]);
        sum[rt]+=sum[nxt];
    }
    Max[rt]=max(ans,sum[rt]);
}
long long dfs(int rt)
{
    long long ans=inf;
    long long mx=inf,msx=inf;
    for(int i=0; i<son[rt].size(); i++)
    {
        int nxt=son[rt][i];
        if(fa[rt]==nxt)continue;
        fa[nxt]=rt;
        ans=max(ans,dfs(nxt));
        if(Max[nxt]>mx)
        {
            msx=mx;
            mx=Max[nxt];
        }
        else if(Max[nxt]>msx)
            msx=Max[nxt];
    }
    ans=max(ans,mx+msx);
//    printf("%d %I64d\n",rt,ans);
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%I64d",&a[i]);
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        son[u].push_back(v);
        son[v].push_back(u);
    }
    memset(fa,-1,sizeof(fa));
    findmax(1);
    long long ans=dfs(1);
    if(ans<(long long)(-2e9))
        printf("Impossible\n");
    else
        printf("%I64d\n",ans);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

vector<int>son[105];
int fa[105];
int n,k;
long long mod=1e9+7;
long long dp[105][42];
long long tmp[42];
void getdp(int rt)
{
    dp[rt][0]=1;
    dp[rt][k+1]=1;
    for(int i=0;i<son[rt].size();i++)
    {
        int nxt=son[rt][i];
        if(fa[rt]==nxt)continue;
        fa[nxt]=rt;
        getdp(nxt);
        memset(tmp,0,sizeof(tmp));
        for(int a=0;a<=2*k;a++)
        {
            for(int b=0;b<=2*k;b++)
            {
                if(a+b<=2*k)
                    tmp[min(a,b+1)]+=dp[rt][a]*dp[nxt][b]%mod;
                else
                    tmp[max(a,b+1)]+=dp[rt][a]*dp[nxt][b]%mod;
            }
        }
        for(int a=0;a<=k*2;a++)
            dp[rt][a]=tmp[a]%mod;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        son[u].push_back(v);
        son[v].push_back(u);
    }
    if(k==0)
    {
        printf("1\n");
        return 0;
    }
    memset(fa,-1,sizeof(fa));
    getdp(1);
    long long ans=0;
    for(int i=0;i<=k;i++)ans+=dp[1][i];
    printf("%I64d\n",ans%mod);
    return 0;
}

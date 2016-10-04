#include<stdio.h>
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
const int mod=1e9+7;
const int maxn=300005;
int fac[maxn];
int inv[maxn];
int ifac[maxn];
void init()
{
    fac[0]=inv[0]=ifac[0]=1;
    fac[1]=inv[1]=ifac[1]=1;
    for(int i=2; i<maxn; i++)
    {
        fac[i]=(long long)fac[i-1]*i%mod;
        inv[i]=(long long)(mod-mod/i)*inv[mod%i]%mod;
        ifac[i]=(long long)ifac[i-1]*inv[i]%mod;
    }
}
int dp[2005][30];
int roads[2005][2005];
pair<int,int>pr[2005];
int tot;
int C(int n,int m,int mod)
{
    if(m<0)return 0;
    if(n<m)return 0;
    return (long long)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
int main()
{
    init();
    int n,m,k,s;
    scanf("%d%d%d%d",&n,&m,&k,&s);
    for(int i=0; i<k; i++)
    {
        scanf("%d%d",&pr[i].first,&pr[i].second);
        tot++;
    }
    int cnt=0;
    pr[tot++]=make_pair(1,1),cnt++;
    pr[tot++]=make_pair(n,m),cnt++;
    sort(pr,pr+tot);
    for(int i=0; i<tot; i++)
    {
        for(int j=i+1; j<tot; j++)
        {
            roads[i][j]=C(pr[j].first-pr[i].first+pr[j].second-pr[i].second,pr[j].second-pr[i].second,mod);
        }
    }
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1; i<tot; i++)
    {
        for(int j=1; j<23; j++)
        {
            for(int k=0; k<i; k++)
            {
                dp[i][j]+=(long long)dp[k][j-1]*roads[k][i]%mod;
                if(dp[i][j]>=mod)dp[i][j]-=mod;
                dp[i][j]-=(long long)dp[k][j]*roads[k][i]%mod;
                if(dp[i][j]<0)dp[i][j]+=mod;
            }
        }
    }
    long long ans=C(n+m-2,n-1,mod);
    long long val=s;
    for(int i=cnt; i<23; i++)
    {
        ans+=(val-1)*dp[tot-1][i]%mod;
        val=(val+1)/2;
    }
    ans%=mod;
    ans=ans*qpow(C(n+m-2,n-1,mod),mod-2,mod)%mod;
    printf("%I64d\n",ans);
    return 0;
}

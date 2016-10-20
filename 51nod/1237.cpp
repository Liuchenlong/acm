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
#define eps 1e-8
#define LL long long
#define pii pair<int,int>

const int maxn=10000005;
const long long mod = 1e9+7;
long long inv6=166666668;
long long inv2=(mod+1)/2;
bool notprime[maxn];
int prime[maxn],prinum;
int phi[maxn];
int mu[maxn];
long long pre[maxn];
void init()
{
    phi[1]=1;
    mu[1]=1;
    notprime[0]=notprime[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            phi[i]=i-1;
            mu[i]=-1;
        }
        for(int j=0;j<prinum&&i*prime[j]<maxn;j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                mu[i*prime[j]]=0;
                break;
            }
            else
            {
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
    for(int i=1;i<maxn;i++)
        pre[i]=(pre[i-1]+phi[i])%mod;
}
map<LL,LL>mp;
LL calpre(LL n)
{
    if(n<maxn)
        return pre[n];
    if(mp.find(n)!=mp.end())
        return mp[n];
    LL ans=n%mod*((n+1)%mod)%mod*inv2%mod;
    for(LL i=2;i<=n;)
    {
        LL j=n/(n/i);
        ans-=calpre(n/i)*((j-i+1)%mod)%mod;
        if(ans<0)ans+=mod;
        i=j+1;
    }
    return mp[n]=ans;
}
LL glen(LL l,LL r)
{
    LL ans=r%mod*((r+1)%mod)%mod-l%mod*((l-1)%mod)%mod;
    return (ans*inv2%mod+mod)%mod;
}
LL cal(LL n)
{
    LL ans=0;
    for(LL i=1;i<=n;)
    {
        LL j=n/(n/i);
        ans+=calpre(n/i)*glen(i,j)%mod;
        if(ans>=mod)
            ans-=mod;
        i=j+1;
    }
    return ans;
}
int main()
{
    init();
    long long n;
    scanf("%I64d",&n);
    long long ans=cal(n)*2-(n%mod*((n+1)%mod)%mod*inv2%mod);
    ans=(ans%mod+mod)%mod;
    printf("%I64d\n",ans);
    return 0;
}

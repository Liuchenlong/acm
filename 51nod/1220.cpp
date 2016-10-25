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

const int maxn=5000005;
bool notprime[maxn];
int prime[maxn],prinum;
int mu[maxn];
const long long mod=1e9+7;
long long inv2=(mod+1)/2;
long long pres[maxn];
void init()
{
    mu[1]=1;
    notprime[0]=notprime[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<prinum&&i*prime[j]<maxn;j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                mu[i*prime[j]]=0;
                break;
            }
            else
            {
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
    for(int i=1;i<maxn;i++)
        pres[i]=(pres[i-1]+i*mu[i])%mod;
}
long long g(int x)
{
    long long ans=0;
    for(long long i=1;i<=x;)
    {
        int j=x/(x/i);
        long long xi=(x/i);
        ans+=((xi*(xi+1)%mod*inv2)%mod)*(j-i+1)%mod;
        if(ans>=mod)
            ans-=mod;
        i=j+1;
    }
    return ans;
}
long long cal(long long n)
{
    return (n*(n+1)%mod*inv2)%mod;
}
long long h(int x)
{
    long long ans=0;
    for(int i=1;i<=x;)
    {
        long long j=x/(x/i);
        ans+=(cal(j)-cal(i-1))*(x/i)%mod;
        i=j+1;
    }
    return (ans%mod+mod)%mod;
}
map<int,long long>mp;
long long s(int n)
{
    if(n<maxn)
        return pres[n];
    if(mp.find(n)!=mp.end())
        return mp[n];
    long long ans=1;
    for(int i=2;i<=n;)
    {
        long long j=n/(n/i);
        ans-=s(n/i)*(cal(j)-cal(i-1))%mod;
        i=j+1;
    }
    return mp[n]=(ans%mod+mod)%mod;
}
int main()
{
    init();
    int n;
    scanf("%d",&n);
    long long ans=0;
    for(int i=1;i<=n;)
    {
        int j=n/(n/i);
        ans+=(s(j)-s(i-1))*g(n/i)%mod*h(n/i)%mod;
        i=j+1;
    }
    printf("%I64d\n",(ans%mod+mod)%mod);
    return 0;
}

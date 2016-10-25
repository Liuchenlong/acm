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

const int maxn=20000005;
bool notprime[maxn];
int prime[maxn/10],prinum;
int mu[maxn];
const long long mod=1e9;
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
long long g(long long x)
{
    long long ans=0;
    for(long long i=1;i<=x;)
    {
        long long j=x/(x/i);
        long long xi=(x/i);
        if(xi&1)
            ans+=(j-i+1)%mod*(xi%mod*((xi+1)/2%mod)%mod)%mod;
        else
            ans+=(j-i+1)%mod*((xi/2)%mod*((xi+1)%mod))%mod;
        i=j+1;
    }
    return ans%mod;
}
long long cal(long long n)
{
    n%=mod;
    return (n*(n+1)/2)%mod;
}
long long h(long long x)
{
    long long ans=0;
    for(long long i=1;i<=x;)
    {
        long long j=x/(x/i);
        ans+=(x/i)%mod*(cal(j)-cal(i-1))%mod;
        ans%=mod;
        i=j+1;
    }
    return (ans%mod+mod)%mod;
}
map<long long,long long>mp;
long long s(long long n)
{
    if(n<maxn)
        return pres[n];
    if(mp.find(n)!=mp.end())
        return mp[n];
    long long ans=1;
    for(long long i=2;i<=n;)
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
    long long n;
    scanf("%I64d",&n);
    long long ans=0;
    for(long long i=1;i<=n;)
    {
        long long j=n/(n/i);
        ans+=(s(j)-s(i-1))%mod*g(n/i)%mod*h(n/i)%mod;
        i=j+1;
    }
    printf("%I64d\n",(ans%mod+mod)%mod);
    return 0;
}

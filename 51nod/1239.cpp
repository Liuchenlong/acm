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
const int mod=1000000007;
long long inv2=(mod+1)/2;
bool notprime[maxn];
int prime[maxn],prinum;
int phi[maxn];
int pre[maxn];
void init()
{
    phi[1]=1;
    notprime[0]=notprime[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<prinum&&i*prime[j]<maxn;j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            else
            {
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
    for(int i=1;i<maxn;i++)
    {
        pre[i]=pre[i-1]+phi[i];
        if(pre[i]>=mod)
            pre[i]-=mod;
    }
}
map<long long,long long>mp;
long long cal(long long n)
{
    if(n<maxn)
        return pre[n];
    if(mp.find(n)!=mp.end())
        return mp[n];
    long long ans=n%mod*((n+1)%mod)%mod*inv2%mod;
    for(long long i=2;i<=n;)
    {
        long long j=n/(n/i);
        ans-=cal(n/i)*(j-i+1)%mod;
        if(ans<=0)ans+=mod;
        i=j+1;
    }
    ans=(ans%mod+mod)%mod;
    return mp[n]=ans;
}
int main()
{
    init();
    long long n;
    scanf("%I64d",&n);
    printf("%I64d\n",cal(n));
    return 0;
}

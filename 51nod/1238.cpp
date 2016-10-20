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
long long PHI[maxn];
void init()
{
    phi[1]=1;
    notprime[0]=notprime[1]=1;
    for(int i=2; i<maxn; i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            phi[i]=i-1;
        }
        for(int j=0; j<prinum&&i*prime[j]<maxn; j++)
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
    for(int i=1; i<maxn; i++)
    {
        PHI[i]=(1LL*i*i%mod*phi[i])%mod+PHI[i-1];
        PHI[i]%=mod;
    }
}
LL cal1(LL n)
{
    n%=mod;
    return n*(n+1)%mod*inv2%mod;
}
LL cal2(LL n)
{
    n%=mod;
    return n*(n+1)%mod*(n*2%mod+1)%mod*inv6%mod;
}
LL cal3(LL n)
{
    LL ans=cal1(n);
    return ans*ans%mod;
}
map<LL,LL>mp;
LL cal(LL n)
{
    if(n<maxn)
        return PHI[n];
    if(mp.find(n)!=mp.end())
        return mp[n];
    LL ans=cal3(n);
    for(LL i=2; i<=n;)
    {
        LL j=n/(n/i);
        ans-=cal(n/i)*(cal2(j)-cal2(i-1)+mod)%mod;
        if(ans<0)ans+=mod;
        i=j+1;
    }
    return mp[n]=ans;
}

LL gcd(LL a,LL b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    init();
        long long n;
        scanf("%I64d",&n);
        long long ans=0;
        for(LL i=1; i<=n;)
        {
            LL j=n/(n/i);
            ans=ans+cal(n/i)*(cal1(j)-cal1(i-1)+mod)%mod;
            if(ans>=mod)ans-=mod;
            i=j+1;
        }
        printf("%I64d\n",ans);
    return 0;
}

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
const long long mod=1e9+7;
long long qpow(long long x,long long k,long long mod)
{
    long long b = 1;
    while (k > 0)
    {
          if (k & 1)
             b = (b*x)%mod;
          k = k >> 1 ;
          x = (x*x)%mod;
    }
    return b;
}
long long C(long long n,long long m,long long mod)
{
    if(m*2>n)
        return C(n,n-m,mod);
    long long fz=1;
    long long fm=1;
    for(long long i=1;i<=m;i++)
    {
        fz=fz*(n-i+1)%mod;
        fm=fm*i%mod;
    }
    long long x=qpow(fm,mod-2,mod);
    long long ans=fz*x%mod;
    return ans;
}

long long fac[1000005];
long long inv[1000005];
long long ifac[1000005];
long long C(long long n,long long m)
{
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
void init()
{
    fac[0]=inv[0]=ifac[0]=1;
    fac[1]=inv[1]=ifac[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        ifac[i]=ifac[i-1]*inv[i]%mod;
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        long long n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
        long long ans=C(m,k,mod);
        long long sum=0;
        long long sig=1;
        for(int i=0;i<k;i++)
        {
            sum=sum+sig*C(k,i)*(k-i)%mod*qpow(k-i-1,n-1,mod)%mod;
            sum=(sum%mod+mod)%mod;
            sig*=-1;
        }
        printf("Case #%d: %lld\n",cas,ans*sum%mod);
    }
    return 0;
}

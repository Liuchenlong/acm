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
long long mod;
long long qpow(long long x,long long k)
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
long long inv(long long x)
{
    return qpow(x,mod-2);
}
long long C(long long n,long long m)
{
    if(m>n)return 0;
    if(m*2>n)
        return C(n,n-m);
    long long fz=1;
    long long fm=1;
    for(long long i=1;i<=m;i++)
    {
        fz=fz*(n-i+1)%mod;
        fm=fm*i%mod;
    }
    long long ans=fz*inv(fm)%mod;
    return ans;
}
long long lucas(long long n,long long m)
{
    if(m>n)return 0;
    if(m==0)return 1;
    if(n==0)return 1;
    return lucas(n/mod,m/mod)*C(n%mod,m%mod)%mod;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n,m;
        scanf("%I64d%I64d%I64d",&n,&m,&mod);
        printf("%I64d\n",lucas(n+m,m));
    }
    return 0;
}

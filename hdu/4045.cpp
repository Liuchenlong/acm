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
long long mod=1e9+7;
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
    for(long long i=1; i<=m; i++)
    {
        fz=fz*(n-i+1)%mod;
        fm=fm*i%mod;
    }
    long long ans=fz*inv(fm)%mod;
    return ans;
}
long long stirling[1005][1005];

int main()
{
    for(int i=0; i<=1002; i++)
    {
        stirling[i][i]=1;
        if(i>=1)
            stirling[i][0]=0;
    }

    for(int i=1; i<=1002; i++)
    {
        for(int j=1; j<i; j++)
        {
            stirling[i][j]=(stirling[i-1][j]*j%mod+stirling[i-1][j-1])%mod;
        }
    }
    long long n,r,k,m;
    while(scanf("%I64d%I64d%I64d%I64d",&n,&r,&k,&m)!=EOF)
    {
        long long ans=0;
        long long kkk=C(n-(k*(r-1)+1)+r,r);
        int t=min(r,m);
        for(int i=1; i<=t; i++)
        {
            ans=ans+stirling[r][i];
            ans%=mod;
        }
        ans=ans*kkk%mod;
        printf("%I64d\n",ans);
    }
    return 0;
}

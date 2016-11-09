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
long long mod=1e9+7;
long long qpow(long long x,int k,long long mod)
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
long long d,x,y;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long ret=exgcd(b,a%b,x,y);
        long long temp=x;
        x=y;
        y=temp-a/b*y;
        return ret;
    }
}
long long inv(long long n,long long mod)
{
    d=exgcd(n,mod,x,y);
    x=(x%mod+mod)%mod;
    if(d==1)
        return x;
    return -1;//ÎÞÄæÔª
}
int n,k;
long long p[1000005];
long long fac[1000005];
long long facn[1000005];
int main()
{
    fac[0]=1;
    fac[1]=1;
    for(int i=2;i<=1000003;i++)
        fac[i]=fac[i-1]*i%mod;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k+2;i++)
    {
        p[i]=(p[i-1]+qpow(i,k,mod))%mod;
    }
    if(n<=k+2)
    {
        printf("%I64d\n",p[n]);
        return 0;
    }
    facn[0]=1;
    for(int i=1;i<=k+2;i++)
    facn[i]=facn[i-1]*(n-i)%mod;
    long long ans=0;
    for(int i=1;i<=k+2;i++)
    {
        long long fm=fac[i-1]*fac[k+2-i]%mod;
        long long fz=facn[k+2]*inv(n-i,mod)%mod;
        long long det=fz*inv(fm,mod)%mod;
        if((k+2-i)&1)
            det=(mod-det)%mod;
        ans=(ans+p[i]*det%mod)%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}

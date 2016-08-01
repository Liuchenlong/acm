#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
const int maxn=1000005;
int phi[maxn];
bool notprime[maxn];
int prime[maxn],prinum;
long long sum[maxn];
const long long mod=1e9+7;
long long inv[maxn];
void init()
{
    phi[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<prinum;j++)
        {
            if(i*prime[j]>=maxn)break;
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
        sum[i]=(sum[i-1]+phi[i])%mod;
    inv[0]=inv[1]=1;
    for(int i=2;i<maxn;i++)
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
}
long long sumx[maxn];
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
long long cal(long long x,long long n)
{
    if(x==1)
        return n;
    if(n==0)
        return 1;
    return (qpow(x,n+1)-1)*inv[x-1]%mod;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x,n;
        scanf("%d%d",&x,&n);
        long long ans=0;
        for(int i=1;i<=n;)
        {
            int j=(n/(n/i));
            ans=ans+(sum[n/i]*2-1)*(cal(x,j)-cal(x,i-1))%mod;
            i=j+1;
        }
        ans-=(long long)n*n%mod;
        printf("%I64d\n",(ans%mod+mod)%mod);
    }
    return 0;
}

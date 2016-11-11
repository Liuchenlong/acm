#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
const long long mod=1e9+7;
long long cal(long long x)
{
    return x*(x+1)/2;
}
long long qpow(long long x,long long k,long long mod)
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
    return qpow(x,mod-2,mod);
}
long long pre[100005];
long long ipre[100005];
long long invn[100005];
long long sum[100005];
int main()
{
    int T;
    scanf("%d",&T);
    pre[0]=pre[1]=1;
    ipre[0]=ipre[1]=1;
    invn[0]=invn[1]=1;
    for(int i=1;i<=100000;i++)
        sum[i]=sum[i-1]+i;
    for(int i=2;i<=100000;i++)
        invn[i]=(mod-mod/i)*invn[mod%i]%mod;
    for(int i=2; i<=100000; i++)
        pre[i]=pre[i-1]*i%mod;
    for(int i=2; i<=100000; i++)
        ipre[i]=ipre[i-1]*invn[i]%mod;
    while(T--)
    {
        int x;
        scanf("%d",&x);
        if(x<=4)
        {
            printf("%d\n",x);
            continue;
        }
        int r=upper_bound(sum,sum+100000,x+1)-sum-1;
        int res=x-sum[r]+1;
        long long ans;
        if(res==r)
        {
            ans=pre[r+2]*invn[2]%mod*invn[r+1]%mod;
        }
        else
        {
            ans=pre[r];
            ans=ans*(r+1)%mod*invn[r+1-res]%mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

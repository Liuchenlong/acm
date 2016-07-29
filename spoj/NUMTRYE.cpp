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
const int maxn = 1000000+20;
int phi[maxn];
bool notprime[maxn];
int prime[216817],prinum;
long long f[maxn];
unsigned long long sum[maxn];
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
                phi[i*prime[j]]=prime[j]*phi[i];
                break;
            }
            else
            {
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
    for(int i=2;i<maxn;i++)
    {
        for(int j=i;j<maxn;j+=i)
        {
            f[j]+=(long long)j*((long long)i*phi[i]/2);
        }
    }
    for(int i=2;i<maxn;i++)
        sum[i]=sum[i-1]+f[i];
}
int main()
{
    init();
//    printf("%d\n",prinum);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        long long n;
        scanf("%lld",&n);
        long long ans=1;
        for(int i=0;i<prinum;i++)
        {
            if(prime[i]>n/prime[i])break;
            if(n%prime[i]==0)
            {
                ans=ans*(prime[i]+1)%mod;
                while(n%prime[i]==0)
                    n/=prime[i];
            }
        }
        if(n!=1)
            ans=ans*(n+1)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}

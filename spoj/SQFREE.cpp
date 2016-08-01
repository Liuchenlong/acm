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

const int maxn=10000005;
bool notprime[maxn];
int prime[maxn],prinum;
int mu[maxn];
long long sum[maxn];
void init()
{
    mu[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<prinum;j++)
        {
            if(i*prime[j]>=maxn)break;
            notprime[i*prime[j]]=1;
            if(i%prime[j])
            {
                mu[i*prime[j]]=-mu[i];
            }
            else
            {
                mu[i*prime[j]]=0;
                break;
            }
        }
    }
    for(int i=1;i<maxn;i++)
        sum[i]=sum[i-1]+mu[i];
}

int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n;
        scanf("%lld",&n);
        long long ans=0;
        long long x=sqrt(n);
        for(long long i=1;i*i<=n;)
        {
            long long j=sqrt(n/(n/i/i));
            ans=ans+(sum[j]-sum[i-1])*(n/(i*i));
            i=j+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

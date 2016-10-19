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
bool notprime[maxn];
int prime[maxn],prinum;
int mu[maxn];
int pre[maxn];
void init()
{
    mu[1]=1;
    notprime[0]=notprime[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<prinum&&i*prime[j]<maxn;j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                mu[i*prime[j]]=0;
                break;
            }
            else
            {
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
    for(int i=1;i<maxn;i++)
        pre[i]=pre[i-1]+mu[i];
}
map<long long,long long>mp;
long long cal(long long n)
{
    if(n<maxn)
        return pre[n];
    if(mp.find(n)!=mp.end())
        return mp[n];
    long long ans=1;
    for(long long i=2;i<=n;)
    {
        long long j=n/(n/i);
        ans-=cal(n/i)*(j-i+1);
        i=j+1;
    }
    return mp[n]=ans;
}
int main()
{
    init();
    long long l,r;
    scanf("%I64d%I64d",&l,&r);
    printf("%I64d\n",cal(r)-cal(l-1));
    return 0;
}

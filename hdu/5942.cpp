#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
const double pi=acos(-1.0);
const long long mod=1e9+7;
const int maxn=1000005;
bool notprime[maxn];
int prime[maxn/10],prinum;
int mu[maxn];
void init()
{
    mu[1]=1;
    notprime[0]=notprime[1]=1;
    for(int i=2; i<maxn; i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            mu[i]=-1;
        }
        for(int j=0; j<prinum&&i*prime[j]<maxn; j++)
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
}
const int maxm=5000005;
long long pe[maxm];
long long PHI(long long n)
{
    if(n<maxm)
        return pe[n];
    long long ans=0;
    for(long long i=1; i<=n;)
    {
        long long j=n/(n/i);
        ans+=(j-i+1)*(n/i);
        i=j+1;
    }
    return ans%mod;
}
long long cal(long long n)
{
    long long x=(long long)sqrt(n);
    long long ans=0;
    for(long long i=1; i<=x; i++)
    {
        ans+=mu[i]*PHI(n/(i*i));
    }
    ans=(ans%mod+mod)%mod;
    return ans;
}
int main()
{
    init();
    for(int i=1;i<maxm;i++)
    {
        for(int j=i;j<maxm;j+=i)
        {
            pe[j]++;
        }
        pe[i]+=pe[i-1];
    }
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        long long n;
        scanf("%I64d",&n);
        printf("Case #%d: %I64d\n",cas,cal(n));
    }
    return 0;
}

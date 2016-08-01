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

const int maxn=100005;
bool notprime[maxn];
int prime[maxn],prinum;
void getprime()
{
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
            prime[prinum++]=i;
        for(int j=0;j<prinum;j++)
        {
            if(i*prime[j]>=maxn)break;
            notprime[i*prime[j]]=true;
            if(i%prime[j]==0)break;
        }
    }
}
const long long mod=10000019;
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
int getk(int n,int x)
{
    int ans=0;
    while(n)
    {
        ans+=n/x;
        n/=x;
    }
    return ans;
}
int main()
{
    getprime();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n,t;
        scanf("%d%d",&n,&t);
        bool flag=false;
        long long ans=1;
        for(int i=0;i<prinum;i++)
        {
            if(prime[i]>n)break;
            int num=getk(n,prime[i]);
            if(num>=t)
            {
                flag=true;
                ans=ans*qpow(prime[i],num/t)%mod;
            }
        }
        if(flag)
            printf("Case %d: %lld\n",cas,ans);
        else
            printf("Case %d: -1\n",cas);
    }
    return 0;
}

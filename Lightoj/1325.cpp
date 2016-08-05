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
const int mod=100000007;
int k;
long long res;
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

int bsgs()
{
    map<long long,int>mp;
    int M=(int)sqrt(mod);
    long long val=1;
    for(int i=0;i<M;i++)
    {
        mp[val]=i;
        val=val*k%mod;
    }
    mp[val]=M;
    int ans=0;
    long long iv=inv(val);
    while(true)
    {
        if(mp.find(res)!=mp.end())
        {
            ans+=mp[res];
            break;
        }
        ans+=M;
        res=res*iv%mod;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%lld",&k,&res);
        printf("Case %d: %d\n",cas,bsgs());
    }
    return 0;
}

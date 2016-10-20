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

const int maxn=4000005;
const long long mod = 1e9+7;
long long f[maxn];
long long pre[maxn];
void init()
{
    f[1]=0;
    for(int i=2;i<maxn;i++)
    {
        f[i]+=1LL*i*i-i*3+2;
        f[i]=(f[i]%mod+mod)%mod;
        for(int j=i*2;j<maxn;j+=i)
            f[j]-=f[i];
    }
    for(int i=1;i<maxn;i++)
        pre[i]=(pre[i-1]+f[i])%mod;
}
long long inv6=166666668;
long long inv2=(mod+1)/2;
map<int,long long>mp;
long long get(long long n)
{
    long long ans=n*(n+1)%mod*(n*2+1)%mod*inv6%mod-n*(n+1)%mod*inv2%mod*3+n*2;
    ans=(ans%mod+mod)%mod;
    return ans;
}
long long cal(int n)
{
    if(n<maxn)return pre[n];
    if(mp.find(n)!=mp.end())return mp[n];
    long long ans=get(n);
    for(int i=2;i<=n;)
    {
        int j=n/(n/i);
        ans-=(cal(n/i)*(j-i+1))%mod;
        if(ans<0)ans+=mod;
        i=j+1;
    }
    return mp[n]=ans;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        printf("%I64d\n",cal(n));
    }
    return 0;
}

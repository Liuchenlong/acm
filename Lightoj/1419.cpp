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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) (a<0?-a:a)
#define SIZE 500000
#define INF 0x7fffffff
const long long mod=1e9+7;
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
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

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        long long ans=0;
        for(int i=0;i<n;i++)
            ans=ans+qpow(k,gcd(n,i),mod);
        ans=ans%mod*qpow(n,mod-2,mod)%mod;
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}

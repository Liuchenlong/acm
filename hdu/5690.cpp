#include<stdio.h>
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

long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*x%mod;
        k>>=1;
        x=(x*x)%mod;
    }
    return ans;
}
long long solve(long long x,long long len,long long mod)
{
    if(len==0)
        return 0;
    if(len%2==0)
    {
        long long y=solve(x,len/2,mod);
        return (y*qpow(10,len/2,mod)%mod+y)%mod;
    }
    else
    {
        long long y=solve(x,(len-1)/2,mod);
        return (y*qpow(10,(len-1)/2+1,mod)%mod+x*qpow(10,(len-1)/2,mod)%mod+y)%mod;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        long long x,m,k,c;
        scanf("%I64d%I64d%I64d%I64d",&x,&m,&k,&c);
        printf("Case #%d:\n",cas);
        if(solve(x,m,k)==c)printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}

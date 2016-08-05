#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define ABS(a) ((a)<0?-(a):(a))

const long long mod=1e9+7;
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
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n,m;
        scanf("%I64d%I64d",&n,&m);
        if(m==1)
            printf("%I64d\n",(n+1LL)%mod);
        else
        {
            long long ans=(qpow(m,n+1)-1LL)*qpow(m-1,mod-2)%mod;
            printf("%I64d\n",(ans%mod+mod)%mod);
        }
    }
    return 0;
}

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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
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
    int n;
    scanf("%d",&n);
    long long K=1;
    for(int i=0;i<n;i++)
    {
        long long a;
        scanf("%I64d",&a);
        a%=(mod-1);
        K=K*a%(mod-1);
    }
    K=(K+mod-2)%(mod-1);
    printf("%I64d/%I64d\n",((qpow(2,K)-qpow(mod-1,K))%mod+mod)%mod*qpow(3,mod-2)%mod,qpow(2LL,K));
    return 0;
}

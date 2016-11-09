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

long long MOD=1000000007;
long long INV=500000004;
long long n,m;
long long cal(long long n)
{
    n%=MOD;
    return n*(n+1)%MOD*INV%MOD;
}
int main()
{
    scanf("%I64d%I64d",&n,&m);
    long long ans=(n%MOD)*(m%MOD)%MOD;
    m=min(n,m);
    long long t;
    for(t=1;t<=m&&t*t<=n;t++)
    {
        ans=ans-n/t*t;
        ans=(ans%MOD+MOD)%MOD;
    }
    for(long long i=n/t;i>=n/m;i--)
    {
        ans=ans-(cal(min(m,n/i))-cal(n/(i+1)))*i%MOD;
        ans=(ans%MOD+MOD)%MOD;
    }
    printf("%I64d\n",ans);
    return 0;
}

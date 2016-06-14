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
long long MOD=1e9+7;
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
    long long A,B,n,x;
    scanf("%I64d%I64d%I64d%I64d",&A,&B,&n,&x);
    long long ans=qpow(A,n,MOD)*x%MOD;
    long long sum;
    if(A==1)
    {
        sum=n%MOD*B%MOD;
    }
    else
    {
        sum=B*(qpow(A,n,MOD)-1)%MOD*qpow(A-1,MOD-2,MOD)%MOD;
    }
    printf("%I64d\n",(ans+sum)%MOD);
    return 0;
}

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
long long n,k;
long long mod=1e6+3;
bool check()
{
    long long ans=1;
    for(int i=1; i<=n; i++)
    {
        ans*=2;
        if(ans>=k)
            return false;
    }
    return true;
}
long long qpow(long long x,long long k,long long mod)
{
    x%=mod;
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
    return qpow(x,mod-2,mod);
}
long long cal(long long x)
{
    long long ans=0;
    while(x>0)
    {
        ans+=x/2;
        x/=2;
    }
    return ans;
}
int main()
{
    scanf("%I64d%I64d",&n,&k);
    if(check())
    {
        printf("1 1\n");
    }
    else
    {
        long long tnum=n%(mod-1)*((k-1)%(mod-1))%(mod-1);
        tnum-=cal(k-1);
        tnum%=(mod-1);
        tnum+=(mod-1);
        tnum%=(mod-1);
        long long tn=qpow(2,n,mod);
        long long rs=k-1;
        long long fz=1;
        if(k-1>=mod)
        {
            fz=0;
        }
        else
        {
            for(int i=1;i<=rs;i++)
            {
                fz=fz*(tn+mod-i)%mod;
            }
            fz=(fz%mod+mod)%mod;
            fz=fz*inv(qpow(2,cal(k-1),mod));
        }
        long long fm=qpow(2,tnum,mod);
        fz=fm-fz;
        fz=(fz%mod+mod)%mod;
        printf("%I64d %I64d\n",fz,fm);
    }
    return 0;
}

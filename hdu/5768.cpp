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

long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
//扩展欧几里得
//ax+by=d;
//x'=x+b/d;
//y'=y-a/d;
//a,b要求非负!
long long d,x,y;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long ret=exgcd(b,a%b,x,y);
        long long temp=x;
        x=y;
        y=temp-a/b*y;
        return ret;
    }
}
long long qadd(long long x,long long k,long long mod)
{
    long long ans=0;
    while(k)
    {
        if(k&1)
        {
            ans=ans+x;
            while(ans>=mod)ans-=mod;
        }
        k>>=1;
        x<<=1;
        while(x>=mod)x-=mod;
    }
    return ans;
}
long long china(int n,long long a[],long long m[])
{
    long long M=1,d,y,x;
    long long ans=0;
    for(int i=0; i<n; i++)
        M*=m[i];
    for(int i=0; i<n; i++)
    {
        long long w=M/m[i];
        d=exgcd(m[i],w,x,y);
        y=(y%(m[i]/d)+m[i]/d)%(m[i]/d);
        ans=(ans+qadd(qadd(y%M,w%M,M),a[i]%M,M))%M;
    }
    return ans;
}
long long a[20],m[20];
int n;
long long cal(long long x)
{
    if(x==0)return 0;
    long long ans=x/7;
    for(int i=1;i<(1<<n);i++)
    {
        long long sig=1;
        long long LCM=7;
        long long ta[20],tm[20];
        int tn=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                sig*=-1;
                LCM=lcm(LCM,m[j]);
                ta[tn]=a[j];
                tm[tn]=m[j];
                tn++;
            }
        }
        ta[tn]=0;
        tm[tn]=7;
        tn++;
        long long res=china(tn,ta,tm);
        if(res==0)res+=LCM;
        long long sum=0;
        if(res>x)sum=0;
        else sum=(x-res)/LCM+1LL;
        ans=ans+sum*sig;
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        long long x,y;
        scanf("%d%I64d%I64d",&n,&x,&y);
        for(int i=0;i<n;i++)
            scanf("%I64d%I64d",&m[i],&a[i]);
        m[n]=7;
        a[n]=0;
        printf("Case #%d: %I64d\n",cas,cal(y)-cal(x-1));
    }
    return 0;
}

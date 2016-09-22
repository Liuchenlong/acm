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

long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
    while(k)
    {
        if(k&1)ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
struct Comp
{
    long long real,image;
    Comp(){}
    Comp(long long a,long long b)
    {
        real=a;
        image=b;
    }
};
long long w;
Comp mult(Comp a,Comp b,long long mod)
{
    Comp ans;
    ans.real=(a.real*b.real%mod+a.image*b.image%mod*w%mod)%mod;
    ans.image=(a.real*b.image%mod+a.image*b.real%mod)%mod;
    return ans;
}
Comp qpow(Comp x,long long k,long long mod)
{
    Comp ans=Comp(1,0);
    while(k)
    {
        if(k&1)
            ans=mult(ans,x,mod);
        k>>=1;
        x=mult(x,x,mod);
    }
    return ans;
}
long long legendre(long long a,long long p)
{
    return qpow(a,(p-1)/2,p);
}
long long quadratic_residue(long long n,long long p)
{
    if(p==2)return 1;
    if(legendre(n,p)==p-1)return -1;
    long long a=-1,t;
    while(true)
    {
        a=rand()%p;
        t=a*a-n;
        w=(t%p+p)%p;
        if(legendre(w,p)==p-1)break;
    }
    Comp ans=Comp(a,1);
    ans=qpow(ans,(p+1)/2,p);
    return ans.real;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        if(cas>1)printf("\n");
        long long n,p;
        scanf("%I64d%I64d",&n,&p);
        long long ans=quadratic_residue(n,p);
        printf("Scenario #%d:\n",cas);
        if(ans==-1)printf("-1\n");
        else printf("1\n");
    }
    return 0;
}

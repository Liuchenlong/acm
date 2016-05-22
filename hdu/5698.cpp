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
long long C(long long n,long long m,long long mod)
{
    if(m*2>n)
        return C(n,n-m,mod);
    long long fz=1;
    long long fm=1;
    for(long long i=1;i<=m;i++)
    {
        fz=fz*(n-i+1)%mod;
        fm=fm*i%mod;
    }
    exgcd(fm,mod,x,y);
    x=(x%mod+mod)%mod;
    long long ans=fz*x%mod;
    return ans;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        n--;
        m--;
        printf("%I64d\n",C(n-1+m-1,m-1,1e9+7));
    }
    return 0;
}

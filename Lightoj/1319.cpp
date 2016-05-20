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
//中国剩余定理(m[i]两两互素)
//n个方程:x=a[i](mod m[i]) (0<=i<n)
//返回x
long long china(long long n,long long a[],long long m[])
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
        ans=(ans+y*w*a[i])%M;
    }
    return ans;
}
int n;
long long a[15],m[15];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lld%lld",&m[i],&a[i]);
        printf("Case %d: %lld\n",cas,china(n,a,m));
    }
    return 0;
}

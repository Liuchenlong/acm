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
#define eps 1e-9
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
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
bool merge(long long a1,long long m1,long long a2,long long m2,long long &a3,long long &m3)
{
    long long d=gcd(m1,m2);
    long long c=a2-a1;
    if(c%d!=0)
        return false;
    c=(c%m2+m2)%m2;
    m1/=d;
    m2/=d;
    c/=d;
    exgcd(m1,m2,x,y);
    x=(x%m2+m2)%m2;
    c*=x;
    c%=m2;
    c*=m1*d;
    c+=a1;
    m3=m1*m2*d;
    a3=(c%m3+m3)%m3;
    return true;
}
long long china(int n,long long a[],long long m[])
{
    long long a1=a[0];
    long long m1=m[0];
    for(int i=1; i<n; i++)
    {
        long long a2=a[i];
        long long m2=m[i];
        long long m3,a3;
        if(!merge(a1, m1, a2, m2, a3, m3))//无解
            return -1;
        a1=a3;
        m1=m3;
    }
    return (a1%m1+m1)%m1;
}

int n;
long long a[12];
long long m[12];

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%I64d",&m[i]);
        for(int i=0; i<n; i++)scanf("%I64d",&a[i]);
        long long ans=china(n,a,m);
        long long LCM=1;
        for(int i=0; i<n; i++)
            LCM=lcm(LCM,m[i]);
        if(ans==0)ans+=LCM;
        printf("Case %d: %I64d\n",cas,ans);
    }
    return 0;
}

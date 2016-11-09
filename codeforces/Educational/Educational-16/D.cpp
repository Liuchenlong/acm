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
using namespace std;
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
long long a[10];
long long m[10];
int main()
{
    long long a1,a2,b1,b2,L,R;
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a1,&b1,&a2,&b2,&L,&R);
    L=max(L,b1);
    L=max(L,b2);
    if(L>R)
    {
        printf("0\n");
        return 0;
    }
    n=2;
    m[0]=a1;a[0]=(b1%a1+a1)%a1;
    m[1]=a2;a[1]=(b2%a2+a2)%a2;
    long long x=china(n,a,m);
    if(x==-1)
    {
        printf("0\n");
        return 0;
    }
    long long mod=lcm(a1,a2);
    R-=L;
    x=((x-L)%mod+mod)%mod;
    if(x>R)
        printf("0\n");
    else
        printf("%I64d\n",1LL+(R-x)/mod);
    return 0;
}

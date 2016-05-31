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
#define SIZE 1001005
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
long long china(long long n,long long a[],long long m[])
{
    long long M=1,d,y,x;
    long long ans=0;
    for(long long i=0; i<n; i++)
        M*=m[i];
    for(long long i=0; i<n; i++)
    {
        long long w=M/m[i];
        d=exgcd(m[i],w,x,y);
        y=(y%(m[i]/d)+m[i]/d)%(m[i]/d);
        ans=(ans+y*w*a[i])%M;
    }
    return ans;
}
long long n;
long long a[12];
long long m[12];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d%I64d",&m[i],&a[i]);
    printf("%I64d\n",china(n,a,m));
    return 0;
}

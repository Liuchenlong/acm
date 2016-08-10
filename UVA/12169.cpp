#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int n;
long long num[10005];
long long d,x,y;
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
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%lld",&num[i]);
    }
    long long a,b;
    for(a=0;a<=10000;a++)
    {
        int flag=1;
        d=exgcd(a+1,10001,x,y);
        x*=(num[1]-a*a*num[0])/d;
        x=(x+10001)%10001;
        for(int i=1;i<n;i++)
        {
            if(num[i]!=((a*a*num[i-1]+a*x+x)%10001))
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            b=x;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%lld\n",(a*num[i]+b)%10001);
    }
    return 0;
}

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
    int a,b,c,q;
    while(scanf("%d%d%d%d",&a,&b,&c,&q))
    {
        if(a==0&&b==0&&c==0&&q==0)
            break;
        long long k=pow(2,q);
        long long t=((b-a)%k+k)%k;
        if(t==0)
            printf("0\n");
        else
        {
            d=exgcd(c,k,x,y);
            if(t%d!=0)
            {
                printf("FOREVER\n");
            }
            else
            {
                long long tt=(k);
                long long ans=((x*t/d)%(tt/d)+(tt/d))%(tt/d);
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}

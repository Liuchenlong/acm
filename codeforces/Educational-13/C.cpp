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

long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    long long n,a,b,p,q;
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&p,&q);
    long long lm=lcm(a,b);
    long long ans;
    if(p>q)
    {
        ans=n/a*p+n/b*q-n/lm*q;
    }
    else if(p<q)
    {
        ans=n/a*p+n/b*q-n/lm*p;
    }
    else
    {
        ans=n/a*p+n/b*q-n/lm*p;
    }
    printf("%I64d\n",ans);
    return 0;
}

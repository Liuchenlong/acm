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
long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
//求原根
vector<long long>a;
bool g_test(long long g,long long p)
{
    for(long long i=0;i<a.size();i++)
    {
        if(qpow(g,(p-1)/a[i],p)==1)
            return 0;
    }
    return 1;
}
long long primitive_root(long long p)
{
    long long tmp=p-1;
    a.clear();
    for(long long i=2;i<=tmp/i;i++)
    {
        if(tmp%i==0)
        {
            a.push_back(i);
            while(tmp%i==0)
                tmp/=i;
        }
    }
    if(tmp!=1)
        a.push_back(tmp);
    long long g=1;
    while(true)
    {
        if(g_test(g,p))
            return g;
        g++;
    }
}
int main()
{
    long long x;
    scanf("%I64d",&x);
    printf("%I64d\n",primitive_root(x));
    return 0;
}

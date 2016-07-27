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
#define abs(a) (a<0?-a:a)

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
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        long long n,k;
        scanf("%lld%lld",&n,&k);
        long long lst=qpow(n,k,1000);
        double num=k*log10(n);
        num=num-(int)num;
        num=pow(10,num);
        while(num*10<1000)num*=10;
        long long fst=(long long)num;
        printf("Case %d: %lld %03d\n",cas,fst,(int)lst);

    }
    return 0;
}

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
#define eps 1e-12

long long qpow(long long x,long long k)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
        {
            ans=ans*x%100;
        }
        k>>=1;
        x=x*x%100;
    }
    return ans;
}

int main()
{
    int T;
    int cas=0;
    while(scanf("%d",&T),T)
    {
        cas++;
        for(int i=1;i<=T;i++)
        {
            long long n;
            scanf("%I64d",&n);
            long long ans=qpow(4,n-1)+qpow(2,n-1);
            printf("Case %d: %I64d\n",i,ans%100);
        }
        printf("\n");
    }
    return 0;
}

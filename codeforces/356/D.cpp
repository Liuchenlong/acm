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
#pragma comment(linker, "/STACK:102400000,102400000")
long long cub[100005];
long long n;
map<long long,long long>to;
map<long long,long long>det;
map<long long,long long>dp;
long long cal(long long x)
{
    if(x<8)
    {
        to[x]=0;
        det[x]=x;
        return x;
    }
    if(dp.find(x)!=dp.end())
        return dp[x];
    int pos=upper_bound(cub,cub+100001,x)-cub-1;
    int num=x/cub[pos];
    long long ans1=num+cal(x%cub[pos]);
    long long ans2=0;
    ans2=num-1+cal(cub[pos]-1);
    if(ans1>=ans2)
    {
        to[x]=x%cub[pos];
        det[x]=cub[pos]*num;
        dp[x]=ans1;
        return ans1;
    }
    else
    {
        to[x]=cub[pos]-1;
        det[x]=cub[pos]*(num-1);
        dp[x]=ans2;
        return ans2;
    }
}
int main()
{
    for(long long i=1; i<=100000; i++)
        cub[i]=i*i*i;
    scanf("%I64d",&n);
    long long ans=cal(n);
    long long sumv=0;
    while(n)
    {
        sumv+=det[n];
        n=to[n];
    }
    printf("%I64d %I64d\n",ans,sumv);
    return 0;
}

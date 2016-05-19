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
#define eps 1e-8
int n;
long long m;
long long dp[5000005];
long long num[5000005];
long long sum[5000005];
long long squ(long long x)
{
    return x*x;
}
int Q[5000005];
long long getup(int p1,int p2)
{
    return dp[p1]+squ(sum[p1])-dp[p2]-squ(sum[p2]);
}
long long getdown(int p1,int p2)
{
    return 2LL*(sum[p1]-sum[p2]);
}
long long getdp(int pos,int i)
{
    return dp[pos]+squ(sum[i]-sum[pos])+m;
}
int main()
{
    while(scanf("%d%I64d",&n,&m)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%I64d",&num[i]);
            sum[i]=sum[i-1]+num[i];
        }
        memset(dp,0,sizeof(dp));
        dp[1]=squ(num[1])+m;
        int head=0,tail=0;
        Q[tail++]=0;
        for(int i=1; i<=n; i++)
        {
            while(head+1<tail&&getup(Q[head+1],Q[head])<=getdown(Q[head+1],Q[head])*sum[i])
                head++;
            dp[i]=getdp(Q[head],i);
            while(head+1<tail&&getup(i,Q[tail-1])*getdown(Q[tail-1],Q[tail-2])<=getup(Q[tail-1],Q[tail-2])*getdown(i,Q[tail-1]))
                tail--;
            Q[tail++]=i;
        }
        printf("%I64d\n",dp[n]);
    }
    return 0;
}

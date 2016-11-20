#include <bits/stdc++.h>

using namespace std;
int n;
long long r,p;
long long dp[1000005];
long long inf=(1LL<<60);
long long cal(int n)
{
    if(dp[n]!=-1)return dp[n];
    long long ans=inf;
    for(int i=2;i<=n;)
    {
        int j=n/(n/i);
        ans=min(ans,r+(i-1)*p+cal((n+i-1)/i));
        ans=min(ans,r+(j-1)*p+cal((n+j-1)/j));
        i=j+1;
    }
    return dp[n]=ans;
}
int main()
{
    while(scanf("%d%lld%lld",&n,&r,&p)!=EOF)
    {
        memset(dp,-1,sizeof(dp));
        dp[1]=0;
        printf("%lld\n",cal(n));
    }
    return 0;
}

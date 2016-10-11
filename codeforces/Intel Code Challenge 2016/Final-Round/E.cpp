#include <bits/stdc++.h>

using namespace std;

long long p[10005];
long long s[10005];
long long dp[2][10005];
int n;
long long m;
int main()
{
    scanf("%d%I64d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%I64d",&p[i]);
    for(int i=1;i<=n;i++)scanf("%I64d",&s[i]);
    int now=0,next=1;
    for(int i=1;i<=n;i++)
    {
        memset(dp[next],0,sizeof(dp[next]));
        for(int j=0;j<=i;j++)
        {
            if(j==0)
            {
                dp[next][j]=dp[now][j]+p[i];
            }
            else if(j==i)
            {
               dp[next][j]=dp[now][j-1]+s[i];
            }
            else
            {
                dp[next][j]=min(dp[now][j]+p[i]+m*j,dp[now][j-1]+s[i]);
            }
        }
        swap(now,next);
    }
    long long ans=dp[now][0];
    for(int i=1;i<=n;i++)ans=min(ans,dp[now][i]);
    printf("%I64d\n",ans);
    return 0;
}

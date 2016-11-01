#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
long long inf=1e18;
int n,m;
long long dp[777][777];
long long num[777];
long long pre[777];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%I64d",&num[i]);
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)
        dp[i][j]=inf;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=min(dp[i][j],max(0LL,dp[i+1][j]-num[i]));
            if(j)
                dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
        }
    }
    while(m--)
    {
        long long x;
        scanf("%I64d",&x);
        for(int i=0;i<=n;i++)
        {
            if(dp[1][i]<=x)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}


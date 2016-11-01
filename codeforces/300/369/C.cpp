#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
long long dp[105][105][105];
long long cost[105][105];
int c[105];
int n;
int main()
{
    int m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            scanf("%I64d",&cost[i][j]);
    }
    memset(dp,0x3f,sizeof(dp));
    long long INF=dp[0][0][0];
    if(c[0]==0)
    {
        for(int j=0;j<m;j++)
        dp[0][j][1]=cost[0][j];
    }
    else
        dp[0][c[0]-1][1]=0;
    for(int i=1;i<n;i++)
    {
        if(c[i]==0)
        {
            for(int now=0;now<m;now++)
            {
                for(int t=1;t<=k;t++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(j==now)
                            dp[i][now][t]=min(dp[i][now][t],dp[i-1][now][t]+cost[i][now]);
                        else
                            dp[i][now][t]=min(dp[i][now][t],dp[i-1][j][t-1]+cost[i][now]);
                    }
                }
            }
        }
        else
        {
            for(int t=1;t<=k;t++)
            {
                dp[i][c[i]-1][t]=min(dp[i][c[i]-1][t],dp[i-1][c[i]-1][t]);
                for(int j=0;j<m;j++)
                {
                    if(j==c[i]-1)continue;
                    else
                        dp[i][c[i]-1][t]=min(dp[i][c[i]-1][t],dp[i-1][j][t-1]);
                }
            }
        }
    }
    long long ans=INF;
    for(int i=0;i<m;i++)ans=min(ans,dp[n-1][i][k]);
    if(ans==INF)printf("-1\n");
    else
        printf("%I64d\n",ans);
    return 0;
}

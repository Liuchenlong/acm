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

int n,k;
int a[506];
int dp[505][505];
pair<int,int>pre[505][505];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));
    for(int i=a[0];i<=500;i++){dp[0][i]=i-a[0];pre[0][i]=make_pair(-1,-1);}
    for(int i=1;i<n;i++)
    {
        for(int j=a[i];j<=500;j++)
        {
            for(int t=a[i-1];t<=500;t++)
            {
                if(t+j<k||dp[i-1][t]==-1)continue;
                if(dp[i][j]==-1)
                {
                    dp[i][j]=dp[i-1][t]+j-a[i];
                    pre[i][j]=make_pair(i-1,t);
                }
                else if(dp[i][j]>dp[i-1][t]+j-a[i])
                {
                    dp[i][j]=dp[i-1][t]+j-a[i];
                    pre[i][j]=make_pair(i-1,t);
                }
            }
        }
    }
    int ans=9999999;
    for(int i=a[n-1];i<=500;i++)
    {
        if(~dp[n-1][i])
            ans=min(ans,dp[n-1][i]);
    }
    vector<int>tans;
    for(int i=a[n-1];i<=500;i++)
    {
        if(dp[n-1][i]==ans)
        {
            pair<int,int>now=make_pair(n-1,i);
            while(now.first!=-1)
            {
                tans.push_back(now.second);
                now=pre[now.first][now.second];
            }
            break;
        }
    }
    printf("%d\n",ans);
    for(int i=n-1;i>=0;i--)
        printf("%d ",tans[i]);
    printf("\n");
    return 0;
}

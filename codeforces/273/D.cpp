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
const int mod=1e9+7;
int dp[2][200005];
bool vis[2][200005];
int sum[3005];
int main()
{
    for(int i=1; i<=3000; i++)sum[i]=sum[i-1]+i;
    int r,g;
    scanf("%d%d",&r,&g);
    dp[0][0]=1;
    vis[0][0]=1;
    int now=1,pre=0;
    for(int i=1;; i++)
    {
        bool flag=false;
        for(int j=0; j<=r; j++)
        {
            dp[now][j]=0;
            vis[now][j]=0;
        }
        for(int j=0; j<=r; j++)
        {
            if(j>=i)
            {
                if(vis[pre][j-i])
                {
                    flag=true;
                    vis[now][j]=1;
                    dp[now][j]+=dp[pre][j-i];
                    if(dp[now][j]>=mod)dp[now][j]-=mod;
                }
            }
            if(vis[pre][j]&&sum[i]-j<=g)
            {
                flag=true;
                vis[now][j]=1;
                dp[now][j]+=dp[pre][j];
                if(dp[now][j]>=mod)dp[now][j]-=mod;
            }
        }
        if(flag==0)
        {
            long long ans=0;
            for(int j=0; j<=r; j++)
                ans+=dp[pre][j];
            printf("%I64d\n",ans%mod);
            return 0;
        }
        swap(now,pre);
    }
    return 0;
}

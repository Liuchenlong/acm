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
#define eps 1e-14
const int mod=1e9+7;
int a[1005];
int dp[2][1005][3][3];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        int n,s;
        scanf("%d%d",&n,&s);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        dp[0][0][0][0]=1;
        int now=0;
        int next=1;
        for(int i=1;i<=n;i++)
        {
            memset(dp[next],0,sizeof(dp[next]));
            for(int j=0;j<=s;j++)
            {
                for(int k1=0;k1<=2;k1++)
                {
                    for(int k2=0;k2<=2;k2++)
                    {
                        dp[next][j][k1][k2]+=dp[now][j][k1][k2];
                        while(dp[next][j][k1][k2]>=mod)
                            dp[next][j][k1][k2]-=mod;
                        if(k1>0&&j>=a[i])
                            dp[next][j][k1][k2]+=dp[now][j-a[i]][k1-1][k2];
                        while(dp[next][j][k1][k2]>=mod)
                            dp[next][j][k1][k2]-=mod;
                        if(k2>0)
                            dp[next][j][k1][k2]+=dp[now][j][k1][k2-1];
                        while(dp[next][j][k1][k2]>=mod)
                            dp[next][j][k1][k2]-=mod;
                        if(j>=a[i])
                            dp[next][j][k1][k2]+=dp[now][j-a[i]][k1][k2];
                        while(dp[next][j][k1][k2]>=mod)
                            dp[next][j][k1][k2]-=mod;
                    }
                }
            }
            swap(now,next);
        }
        long long ans=0;
        for(int i=1;i<=s;i++)
            ans+=dp[now][i][2][2];
        ans%=mod;
        printf("%I64d\n",ans*4%mod);
    }
    return 0;
}

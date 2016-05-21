#include<stdio.h>
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
int mod=1e9+7;
int dp[2005][22];
int main()
{
    memset(dp,0,sizeof(dp));
    int n;
    scanf("%d",&n);
    dp[0][0]=1;
    dp[1][1]=1;
    for(int i=2; i<=n; i++)
    {
        for(int j=max(2,(int)(log(i)/log(2))-1); j<=16; j++)
        {
            for(int k=0; k<=i-1; k++)
            {
                int l=k,r=i-1-k;
                dp[i][j]+=((long long)dp[l][j-1]*dp[r][j-1])%mod;
                if(dp[i][j]>=mod)
                    dp[i][j]-=mod;
                dp[i][j]+=((long long)dp[l][j-1]*dp[r][j-2])%mod;
                if(dp[i][j]>=mod)
                    dp[i][j]-=mod;
                dp[i][j]+=((long long)dp[l][j-2]*dp[r][j-1])%mod;
                if(dp[i][j]>=mod)
                    dp[i][j]-=mod;
            }
            if(dp[i][j]>=mod)
                dp[i][j]-=mod;
        }
    }
    int ans=0;
    for(int i=0; i<=20; i++)
    {
        ans=(ans+dp[n][i])%mod;
    }
    printf("%d\n",ans%mod);
    return 0;
}
